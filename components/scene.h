//
// Created by eran on 2/8/16.
//

#ifndef GAME_ENGINE_SCENE_H
#define GAME_ENGINE_SCENE_H

#include "constraints/game_object_constraint.h"
#include "components/state.h"

#include <typeindex>
#include <vector>
#include <map>
#include <SDL2/SDL.h>
#include <graphics/camera.h>


namespace Engine
{
    class Object;
    class CameraData;

    class Scene
    {
    public:
        typedef std::vector<Object*> ObjectsVec;
        typedef std::map<std::string, Object*> ObjectsMap;
        typedef std::map<std::string, Camera> CamerasMap;

        Scene();

        template <class T>
        void AddObject(T* object);

        template <class T>
        void GetObjects(std::vector<T*>& objectsVec);

        void Awake();
        void Update();
        void Render();

        Camera& GetCamera() const;
        void SetWorkingCamera(const std::string& camera_key);
        void RemoveCamera(const std::string& camera_key);
        void AddCamera(const CameraData& camera, const std::string& camera_key);

        inline bool GetState() { return m_state.GetState(); }
        inline void Disactivate() { m_state.Stop(); }
        inline void Activate() { m_state.Start(); }

    private:
        State m_state;
        ObjectsMap m_objects;
        CamerasMap m_cameras;
        Camera* m_working_cmaera;
    };

    template <class T>
    void Scene::AddObject(T* object)
    {
        GameObjectConstraint<T>();
        typename ObjectsMap::iterator iter = m_objects.find(object->GetName());
        if (iter != m_objects.end()) {
            // throw runtime error
        } else {
            m_objects.insert(std::make_pair(object->GetName(), object));
        }
    }

    template <class T>
    void Scene::GetObjects(std::vector<T*>& objectsVec)
    {
        GameObjectConstraint<T>();
        std::type_index key(typeid(T));
        for (Scene::ObjectsMap::value_type& obj : m_objects)
        {
            if (key == std::type_index(typeid(*obj.second))) {
                objectsVec.push_back(static_cast<T*>(obj.second));
            }
        }
    }
}

#endif //GAME_ENGINE_SCENE_H
