//
// Created by eran on 2/8/16.
//

#ifndef GAME_ENGINE_OBJECT_DATA_H
#define GAME_ENGINE_OBJECT_DATA_H

#include "graphics/mesh.h"
#include "graphics/shader.h"
#include "graphics/transform.h"
#include "engine.h"

//#include <boost/optional.hpp>
//#include <boost/uuid/uuid.hpp>
//#include <boost/uuid/uuid_generators.hpp>

namespace Engine
{
    struct ObjectData {

        ObjectData(Engine * father, Mesh* mesh, Shader* shader, Transform* transform, const std::string& name)
                : m_father(father), m_mesh(mesh), m_shader(shader), m_transform(transform),
                  m_name(name)
        {
        }

        Engine* m_father;
        Mesh* m_mesh;
        Shader* m_shader;
        Transform* m_transform;
        const std::string m_name;
    };

//    union ObjectData::ID {
//        boost::optional<boost::uuids::uuid> m_uuid;
//        boost::optional<std::string> m_str_id;
//    };

}

#endif //GAME_ENGINE_OBJECT_DATA_H
