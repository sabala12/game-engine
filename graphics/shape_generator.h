#ifndef GAME_ENGINE_SHAPE_GENERATOR_H
#define GAME_ENGINE_SHAPE_GENERATOR_H

#include <glm/glm.hpp>
#include <GL/glew.h>

namespace Engine
{
	class Mesh;
	class Vertex;

	class ShapeGenerator
	{
	public:
		static Mesh* makeTriangle();
		static Mesh* makeCube();
		static Mesh* makeBall();
		static Mesh* makeBord();
		static void UpdataMesh(glm::vec3& v1, glm::vec3& v2, glm::vec3& v3);

		static Vertex* verticesT;
		static unsigned short* indicesT;
		static size_t counter;

		//static Mesh* makeReckt();
	};


}

#endif //GAME_ENGINE_SHAPE_GENERATOR_H