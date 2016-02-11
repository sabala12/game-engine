#ifndef GAME_ENGINE_ENGINE_H
#define GAME_ENGINE_ENGINE_H

#include <thread>

#include "graphics/display.h"
#include "graphics/camera.h"
#include "components/scene.h"
#include "components/state.h"
#include "common_structs/engine_data.h"
#include "common_structs/camera_data.h"
#include "io/io_events_handler.h"

#include <typeinfo>
#include <map>
#include <vector>
#include <string>

#include <SDL2/SDL.h>
#include <boost/thread/shared_mutex.hpp>
#include <components/game_object.h>

namespace Engine
{
	class Object;
    class Scene;
    struct EngineData;

	class Engine
	{
	public:
        typedef std::map<std::string, Scene*> ScenesMap;
        typedef Scene::ObjectsVec ObjectsVec;

		Engine(const EngineData&);
		virtual ~Engine();

		void Start();
		void Stop();

        void DeleteScene(const std::string& scene_key);
        void AddScene(Scene* scene, const std::string& scene_key);

        template <class T>
        void AddObject(T* object, const std::string& scene_key);

        template <class T>
        void GetObjects(std::vector<T*>& objectsVec, const std::string& scene_key);

    private:

        void HandleEvents();
        void HandleKeyPressEvent(size_t key);
        SDL_Event m_event;

        void Awake();
        void Update();
        void Render();
        void EventLoop();

        ScenesMap m_scenes;
        Display m_display;
        State m_state;
	};

    template <class T>
    void Engine::AddObject(T* object, const std::string& scene_key)
    {
        GameObjectConstraint<T>();
        auto scene = m_scenes.find(scene_key);
        if (scene != m_scenes.end()) {
            object->SetScene((*scene).second);
            (*scene).second->AddObject(object);
        } else {
            // throw runtime exception...
        }
    }

	template <class T>
	void Engine::GetObjects(std::vector<T*>& objectsVec, const std::string& scene_key)
	{
        GameObjectConstraint<T>();
        auto scene = m_scenes.find(scene_key);
        if (scene != m_scenes.end()) {
            (*scene).second->GetObjects<T>(objectsVec);
        } else {
            // throw runtime exception...
        }
	}
}

#endif //GAME_ENGINE_ENGINE_H



/*std::type_index key(typeid(*object));
        ObjectsMap::iterator begin = m_objects.begin();
        for (begin; begin != m_objects.end(); begin++)
        {
            if (begin->first == key)
            {
                begin->second.push_back(object);
                return;
            }
        }

        std::vector<Object *> vec;
        vec.push_back(object);
        m_objects.insert(std::make_pair(key, vec));*/




/*std::type_index key(typeid(T));
		for (Engine::ObjectsMap::value_type& obj : m_objects)
		{
			if (key == obj.first)
				return obj.second;
		}

		std::string error = std::string("type ") + std::string(key.name()) + std::string("is not defined in m_objects");
		throw std::runtime_error(error.c_str());*/