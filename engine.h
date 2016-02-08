#ifndef GAME_ENGINE_ENGINE_H
#define GAME_ENGINE_ENGINE_H

#include <thread>

#include "graphics/display.h"
#include "graphics/camera.h"
#include "constraints/game_object_constraint.h"
#include "communication/zmq/zmq_publisher.h"
#include "io/io_events_handler.h"

#include <SDL2/SDL.h>
#include <typeinfo>
#include <typeindex>
#include <map>
#include <vector>
#include <string>
#include "common_structs/engine_data.h"
#include "common_structs/camera_data.h"

namespace Engine
{
	class Object;
    struct EngineData;

	class Engine
	{
	public:
        typedef ZmqPublisher<std::string> Publisher;
        typedef std::map<std::string, Camera*> CamerasMap;
		//typedef std::map<std::type_index, ObjectsVec> ObjectsMap;
        typedef std::vector<Object*> ObjectsVec;
        typedef std::map<Uint32, Object*> ObjectsMap;

		Engine(const EngineData&);
		virtual ~Engine();

		void Start();
		void Stop();
        void Awake();
		void Update();
		void Render();
        //void AddCamera(const std::string& key, const CameraData&);
        //void RemoveCamera(const std::string& key);

        template <class T> void AddObject(T*);
        template <class T> void GetObjects(ObjectsVec& objectsVec);

    private:
        ObjectsMap m_objects;
        Display m_display;
        //Camera m_camera;
	};

    template <class T>
    void Engine::AddObject(T* object)
    {
        GameObjectConstraint<T>();
        m_objects[object] = object;
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
    }

	template <class T>
	void Engine::GetObjects(ObjectsVec& objectsVec)
	{
        std::type_index key(typeid(T));
        for (Engine::ObjectsMap::value_type& obj : m_objects)
        {
            if (key == std::type_index(obj)) {
                T* a = obj;
                objectsVec.push_back(a);
            }
        }
		/*std::type_index key(typeid(T));
		for (Engine::ObjectsMap::value_type& obj : m_objects)
		{
			if (key == obj.first)
				return obj.second;
		}

		std::string error = std::string("type ") + std::string(key.name()) + std::string("is not defined in m_objects");
		throw std::runtime_error(error.c_str());*/
	}
}

#endif //GAME_ENGINE_ENGINE_H