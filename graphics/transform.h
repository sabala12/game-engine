#ifndef GAME_ENGINE_TRANSFORM_H
#define GAME_ENGINE_TRANSFORM_H

#include "graphics/camera.h"

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <GL/glew.h>

namespace Engine
{
	class Transform
	{
	public:
		Transform(const glm::vec3& pos = glm::vec3(), const glm::vec3& rot = glm::vec3(), const glm::vec3& scale = glm::vec3(1.0f, 1.0f, 1.0f))
		{
			m_pos = pos;
			m_rot = rot;
			m_scale = scale;
		}

		inline glm::mat4 GetModel() const
		{
			glm::mat4 posMat = glm::translate(m_pos);
			glm::mat4 scaleMat = glm::scale(m_scale);
			glm::mat4 rotX = glm::rotate(m_rot.x, glm::vec3(1.0, 0.0, 0.0));
			glm::mat4 rotY = glm::rotate(m_rot.y, glm::vec3(0.0, 1.0, 0.0));
			glm::mat4 rotZ = glm::rotate(m_rot.z, glm::vec3(0.0, 0.0, 1.0));
			glm::mat4 rotMat = rotX * rotY * rotZ;

			return posMat * rotMat * scaleMat;
		}

		inline glm::mat4 GetMVP(const Camera& camera) const
		{
			glm::mat4 VP = camera.GetViewProjection();
			glm::mat4 M = GetModel();

			return VP * M;//camera.GetViewProjection() * GetModel();
		}
		
		inline const glm::vec3& GetPos() { return m_pos; }
		inline const glm::vec3& GetRot() { return m_rot; }
		inline const glm::vec3& GetScale() { return m_scale; }

		inline void SetPos(const glm::vec3& pos) { m_pos = pos; }
		inline void SetRot(const glm::vec3& rot) { m_rot = rot; }
		inline void SetScale(const glm::vec3& scale) { m_scale = scale; }

		inline GLuint GetWidth() const { return m_width; }
		inline GLuint GetHeight() const { return m_height; }

	private:
		//glm::translate(glm::mat4(), glm::vec3(-0.0f, -0.0f, -9.0f)) * glm::rotate(60.0f, glm::vec3(1.0f, 1.0f, 0.0f));
		glm::vec3 m_pos;
		glm::vec3 m_rot;
		glm::vec3 m_scale;

		GLuint m_width;
		GLuint m_height;
	};
}

#endif //GAME_ENGINE_TRANSFORM_H