#ifndef GAME_ENGINE_CAMERA_DATA_H
#define GAME_ENGINE_CAMERA_DATA_H

#include <glm/glm.hpp>

namespace Engine
{
    struct CameraData {

        CameraData(const glm::vec3& pos, const glm::vec3& direction, const glm::vec3& up, const glm::vec2& mouse_pos, float ratio, float aspect, float znear, float zfar)
            : m_pos(pos),  m_direction(direction), m_up(up), m_mouse_pos(mouse_pos),
              m_ratio(ratio), m_aspect(aspect), m_znear(znear), m_zfar(zfar)
        {

        }

        const glm::vec3 m_pos;
        const glm::vec3 m_direction;
        const glm::vec3 m_up;
        const glm::vec2 m_mouse_pos;
        float m_ratio;
        float m_aspect;
        float m_znear;
        float m_zfar;
    };
}

#endif //GAME_ENGINE_CAMERA_DATA_H
