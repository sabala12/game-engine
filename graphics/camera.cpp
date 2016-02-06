#include "graphics/camera.h"
#include "common_structs/camera_data.h"

namespace Engine
{
	Camera::Camera(const CameraData& cameraData)
		: m_pos(cameraData.m_pos), m_direction(cameraData.m_direction), m_up(cameraData.m_up),
		  m_ratio(cameraData.m_ratio), m_aspect(cameraData.m_aspect), m_zNear(cameraData.m_znear),
		  m_zFar(cameraData.m_zfar), m_mousePos(cameraData.m_mouse_pos)
	{
		m_strafeDirection = glm::cross(m_direction, m_up);
		UpdateViewProjection();
	}

	const glm::mat4& Camera::GetViewProjection() const
	{
		return m_viewProjection;
	}

	void Camera::mouseUpdate(const glm::vec2& position)
	{
		glm::vec2 delta = (m_mousePos - position) / ROTATION_SPEED;

		if (glm::length(delta) < 0.075f)
		{
			m_strafeDirection = glm::cross(m_direction, m_up);
			glm::mat4 rotation = glm::rotate(delta.x, m_up) *
				glm::rotate(delta.y, m_strafeDirection);
			m_direction = glm::mat3(rotation) * m_direction;
			UpdateViewProjection();
		}

		m_mousePos = position;
	}

	void Camera::moveForward()
	{
		m_pos += MOVEMENT_SPEED * m_direction;
		UpdateViewProjection();
	}

	void Camera::moveBackward()
	{
		m_pos -= MOVEMENT_SPEED * m_direction;
		UpdateViewProjection();
	}

	void Camera::strafeLeft()
	{
		m_pos -= MOVEMENT_SPEED * m_strafeDirection;
		UpdateViewProjection();
	}

	void Camera::strafeRight()
	{
		m_pos += MOVEMENT_SPEED * m_strafeDirection;
		UpdateViewProjection();
	}

	void Camera::moveUp()
	{
		m_pos += MOVEMENT_SPEED * m_up;
		UpdateViewProjection();
	}

	void Camera::moveDown()
	{
		m_pos -= MOVEMENT_SPEED * m_up;
		UpdateViewProjection();
	}

	void Camera::UpdateViewProjection()
	{
		m_viewProjection = glm::perspective(m_ratio, m_aspect, m_zNear, m_zFar) *
			glm::lookAt(m_pos, m_pos + m_direction, m_up);
	}
	
}