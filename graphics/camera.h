#ifndef GAME_ENGINE_CAMERA_H
#define GAME_ENGINE_CAMERA_H

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <common_structs/camera_data.h>

namespace Engine
{
	struct CameraData;

	class Camera
	{
	public:
		Camera(const CameraData& cameraData);

		const glm::mat4& GetViewProjection() const;

		void mouseUpdate(const glm::vec2& position);

		void moveForward();
		void moveBackward();
		void strafeLeft();
		void strafeRight();
		void moveUp();
		void moveDown();

	private:

		void UpdateViewProjection();

		const float MOVEMENT_SPEED = 0.025f;
		const float ROTATION_SPEED = 50.0f;

		float m_ratio;
		float m_fov;
		float m_zNear;
		float m_zFar;

		glm::vec2 m_mousePos;
		glm::vec3 m_strafeDirection;

		glm::vec3 m_pos;
		glm::vec3 m_direction;
		glm::vec3 m_up;

		glm::mat4 m_viewProjection;
	};
}

#endif //GAME_ENGINE_CAMERA_H