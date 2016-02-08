#include "engine.h"
#include "components/game_object.h"

#include "ball.h"
#include "features/walk.h"

//#include <functional>

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
		: m_display(engine_data.m_display_data)
	{
        //Ball ball;
        //Walk walk(&ball);
        //ball.AddFeature(&walk);
	}

	Engine::~Engine()
	{
		/*std::for_each(m_objects.begin(), m_objects.end(), [](ObjectsMap::value_type& iter){
			std::for_each(iter.second.begin(), iter.second.end(), DeletePtr());
		});*/
		std::for_each(m_objects.begin(), m_objects.end(), DeletePtr());
	}

	void Engine::Start()
	{
        Awake();
        //std::thread event_keys_thread([this] {m_key_events_handler.Start(NULL);});
        //std::thread event_keys_thread(&IOEventsHandler::Start, &m_io_events_handler);

        bool condition_variable = true;
		while (condition_variable)
		{
			Update();
			Render();

			m_display.SwapBuffers();
			m_display.Clear(0, 0, 0, 0);
		}

        //event_keys_thread.join();
	}

    void Engine::Awake()
    {
        /*std::for_each(m_objects.begin(), m_objects.end(), [](objects_map::value_type& iter){
            std::for_each(iter.second.begin(), iter.second.end(), [](objects_map::value_type::second_type::value_type& vec_iter){
                vec_iter->Awake();
            });
        });*/

        std::for_each(m_objects.begin(), m_objects.end(), [](ObjectsMap::value_type& object){
            (&object)->Awake();
        });
    }

	void Engine::Update()
	{
		std::for_each(m_objects.begin(), m_objects.end(), [](objects_map::value_type& iter){
			std::for_each(iter.second.begin(), iter.second.end(), [](objects_map::value_type::second_type::value_type& vec_iter){
				vec_iter->Update();
			});
		});
	}

	void Engine::Render()
	{
		std::for_each(m_objects.begin(), m_objects.end(), [](objects_map::value_type& iter){
			std::for_each(iter.second.begin(), iter.second.end(), [](objects_map::value_type::second_type::value_type& vec_iter){
				vec_iter->Render();
			});
		});
	}

//	void GameEngine::HandleEvents()
//	{
//		SDL_PollEvent(&m_event);
//		if (m_event.type == SDL_QUIT)
//			m_running = false;
//		if (m_event.type == SDL_MOUSEMOTION)
//			m_camera.mouseUpdate(glm::vec2(m_event.motion.x, m_event.motion.y));
//		if (m_event.type == SDL_KEYDOWN)
//			HandleKeyPressEvent(m_event.key.keysym.scancode);
//	}

//	void GameEngine::HandleKeyPressEvent(size_t key)
//	{
//		switch (key)
//		{
//		case SDL_SCANCODE_A:
//			m_camera.strafeLeft();
//			break;
//		case SDL_SCANCODE_D:
//			m_camera.strafeRight();
//			break;
//		case SDL_SCANCODE_W:
//			m_camera.moveUp();
//			break;
//		case SDL_SCANCODE_S:
//			m_camera.moveDown();
//			break;
//		case SDL_SCANCODE_E:
//			m_camera.moveForward();
//			break;
//		case SDL_SCANCODE_Q:
//			m_camera.moveBackward();
//			break;
//		default:
//			break;
//		}
//	}

	//void GameEngine::MoveBord(const glm::vec3& dir)
	//{
	//	//case SDL_SCANCODE_KP_2:
	//	//	MoveBord(glm::vec3(0.0f, -m_bordSpeed, 0.0f));
	//	//case SDL_SCANCODE_KP_4:
	//		//MoveBord(glm::vec3(0.0f, 0.0f, -m_bordSpeed));
	//		//case SDL_SCANCODE_KP_6:
	//		//	MoveBord(glm::vec3(0.0f, 0.0f, m_bordSpeed));
	//		//case SDL_SCANCODE_KP_8:
	//		//	MoveBord(glm::vec3(0.0f, m_bordSpeed, 0.0f));
	//		//	break;
	//	auto bord = (*m_objects.at(std::type_index(typeid(Bord))).begin());
	//	bord->m_transform->SetPos(bord->m_transform->GetPos() + dir);
	//}
}