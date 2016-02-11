#include "engine.h"
#include "components/game_object.h"

//#include "ball.h"
//#include "features/walk.h"

#include <boost/thread/thread.hpp>

namespace Engine
{
	struct DeletePtr
	{
		template <class T>
		void operator()(T* ptr)
		{
			delete ptr;
		}
	};

	Engine::Engine(const EngineData& engine_data)
		: m_display(engine_data.m_display_data), m_state(false)
	{
	}

	Engine::~Engine()
	{
        std::for_each(m_scenes.begin(), m_scenes.end(), [](ScenesMap::value_type& object) {
            delete (&object)->second;
        });
	}

	void Engine::Start()
	{
        m_state.Start();
        this->Awake();
        this->EventLoop();
	}

    void Engine::Stop()
    {
        m_state.Stop();
    }

    void Engine::EventLoop() {
        while (m_state.GetState())
        {
            HandleEvents();
            Update();
            Render();

            m_display.SwapBuffers();
            m_display.Clear(0, 0, 0, 0);
        }
    }

    void Engine::Awake()
    {
        std::for_each(m_scenes.begin(), m_scenes.end(), [](ScenesMap::value_type& object){
            auto scene = (&object)->second;
            if (scene->GetState()) {
                scene->Awake();
            }
        });
    }

	void Engine::Update()
	{
        std::for_each(m_scenes.begin(), m_scenes.end(), [](ScenesMap::value_type& object){
            auto scene = (&object)->second;
            if (scene->GetState()) {
                scene->Update();
            }
        });
	}

	void Engine::Render()
	{
        std::for_each(m_scenes.begin(), m_scenes.end(), [](ScenesMap::value_type& object){
            auto scene = (&object)->second;
            if (scene->GetState()) {
                scene->Render();
            }
        });
	}

    void Engine::DeleteScene(const std::string& scene_key) {
        auto iter = m_scenes.find(scene_key);
        if (iter != m_scenes.end()) {
            delete iter->second;
            m_scenes.erase(iter);
        } else {
            // throw runtime exception...
        }
    }

    void Engine::AddScene(Scene* scene, const std::string& scene_key) {

        auto iter = m_scenes.find(scene_key);
        if (iter != m_scenes.end()) {
            // throw runtime exception...
        } else {
            m_scenes.insert(std::make_pair(scene_key, scene));
        }
    }

    void Engine::HandleEvents()
    {
        SDL_PollEvent(&m_event);
        if (m_event.type == SDL_MOUSEMOTION)
            m_scenes.begin()->second->GetCamera().mouseUpdate(glm::vec2(m_event.motion.x, m_event.motion.y));
        if (m_event.type == SDL_KEYDOWN)
            HandleKeyPressEvent(m_event.key.keysym.scancode);
    }

    void Engine::HandleKeyPressEvent(size_t key)
    {
        switch (key)
        {
            case SDL_SCANCODE_A:
                m_scenes.begin()->second->GetCamera().strafeLeft();
                break;
            case SDL_SCANCODE_D:
                m_scenes.begin()->second->GetCamera().strafeRight();
                break;
            case SDL_SCANCODE_W:
                m_scenes.begin()->second->GetCamera().moveUp();
                break;
            case SDL_SCANCODE_S:
                m_scenes.begin()->second->GetCamera().moveDown();
                break;
            case SDL_SCANCODE_E:
                m_scenes.begin()->second->GetCamera().moveForward();
                break;
            case SDL_SCANCODE_Q:
                m_scenes.begin()->second->GetCamera().moveBackward();
                break;
            default:
                break;
        }
    }
}