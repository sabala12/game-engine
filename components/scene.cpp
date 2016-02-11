//
// Created by eran on 2/8/16.
//

#include "scene.h"
#include "components/game_object.h"

#include <algorithm>

namespace Engine
{
    Scene::Scene()
        : m_state(false), m_working_cmaera(NULL)
    {
    }

    void Scene::Awake() {
        std::for_each(m_objects.begin(), m_objects.end(), [](ObjectsMap::value_type& object){
            (&object)->second->Awake();
        });
    }

    void Scene::Update() {
        std::for_each(m_objects.begin(), m_objects.end(), [](ObjectsMap::value_type& object){
            (&object)->second->Update();
        });
    }

    void Scene::Render() {
        std::for_each(m_objects.begin(), m_objects.end(), [](ObjectsMap::value_type& object){
            (&object)->second->Render();
        });
    }

    Camera& Scene::GetCamera() const {
        if (m_working_cmaera != NULL) {
            return *m_working_cmaera;
        } else {
            // throw runtime error
        }
    }

    void Scene::SetWorkingCamera(const std::string& camera_key) {
        CamerasMap::iterator iter = m_cameras.find(camera_key);
        if (iter != m_cameras.end()) {
            m_working_cmaera = &(iter->second);
        } else {
            // throw runtime error
        }
    }

    void Scene::RemoveCamera(const std::string& camera_key) {
        CamerasMap::iterator iter = m_cameras.find(camera_key);
        if (iter != m_cameras.end()) {
            m_cameras.erase(iter);
        } else {
            // throw runtime error
        }
    }

    void Scene::AddCamera(const CameraData& camera, const std::string& camera_key) {
        CamerasMap::iterator iter = m_cameras.find(camera_key);
        if (iter != m_cameras.end()) {
            // throw runtime error
        } else {
            m_cameras.insert(std::make_pair(camera_key, camera));
        }
    }
}