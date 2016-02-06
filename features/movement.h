#ifndef GAME_ENGINE_MOVEMENT_H
#define GAME_ENGINE_MOVEMENT_H

#include "features/feature.h"
#include <glm/glm.hpp>

namespace Engine
{
	class Object;

	class Movement : public Feature
	{
	public:
		Movement(Object * object);

		virtual void Execute();

		//inline const glm::vec3& GetDirection() const { return m_dir; }
		//inline void SetDirection(const glm::vec3& dir) { m_dir = dir; }
		//inline void NormalizeVelocity(float facrot) { m_dir *= facrot; }

	private:
		const float m_speed = 2.0f;
		glm::vec3 m_dir;
	};
}

#endif //GAME_ENGINE_MOVEMENT_H