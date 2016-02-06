#ifndef GAME_ENGINE_ENGINE_H
#define GAME_ENGINE_ENGINE_H

#include <thread>

#include "graphics/display.h"
#include "graphics/camera.h"
#include "constraints/game_object_constraint.h"
#include "communication/zmq/zmq_publisher.h"
#include "components/key_events_handler.h"

#include <SDL2/SDL.h>
#include <typeinfo>
#include <typeindex>
#include <map>
#include <vector>
#include <string>
#include <common_structs/engine_data.h>

namespace Engine
{
	class Object;
    struct EngineData;

	class Engine
	{
	public:
        typedef ZmqPublisher<std::string> Publisher;
        typedef std::vector<Object*> objects_vec;
		typedef std::map<std::type_index, objects_vec> objects_map;

		Engine(const EngineData& engine_data);
		virtual ~Engine();

		void Start(const RoutingData& m_routing_data);
		void Stop();

        void Awake();
		void Update();
		void Render();

        template <class T> void AddObject(T*);
        template <class T> const objects_vec& GetObjects();


    private:
		KeyEventsHandler<Publisher > &m_key_events_handler;
        objects_map m_objects;
        Display m_display;
        Camera m_camera;
	};

    template <class T>
    void Engine::AddObject(T* object)
    {
        GameObjectConstraint<T>();

        std::type_index key(typeid(*object));
        objects_map::iterator begin = m_objects.begin();
        for (begin; begin != m_objects.end(); begin++)
        {
            if (begin->first == key)
            {
                begin->second.push_back(object);
                begin = m_objects.end();
                return;
            }
        }

        std::vector<Object *> vec;
        vec.push_back(object);
        m_objects.insert(std::make_pair(key, vec));
    }

	template <class T>
	const Engine::objects_vec& Engine::GetObjects()
	{
		std::type_index key(typeid(T));
		for (Engine::objects_map::value_type& obj : m_objects)
		{
			if (key == obj.first)
				return obj.second;
		}

		std::string error = std::string("type ") + std::string(key.name()) + std::string("is not defined in m_objects");
		throw std::runtime_error(error.c_str());
	}
}

#endif //GAME_ENGINE_ENGINE_H