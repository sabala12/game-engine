#include "graphics/shape_generator.h"
#include "graphics/mesh.h"

#include <string.h>

#define NUM_ARRAY_ELEMENTS(a) sizeof(a) / sizeof(*a);

namespace Engine 
{
	Mesh* ShapeGenerator::makeTriangle()
	{
		const float RED_TRI_DEPTH = -0.5f;

		Vertex triangle[] =
		{
			glm::vec3(+0.0f, +0.0f, RED_TRI_DEPTH),
			glm::vec3(+1.0f, +0.0f, +0.0f),

			glm::vec3(+1.0f, +1.0f, RED_TRI_DEPTH),
			glm::vec3(+0.0f, +1.0f, +0.0f),

			glm::vec3(-1.0f, +1.0f, RED_TRI_DEPTH),
			glm::vec3(+0.0f, +0.0f, +1.0f),
		};

		size_t vertices_count = NUM_ARRAY_ELEMENTS(triangle);
		Vertex* vertices_arr = new Vertex[vertices_count];
		memcpy(vertices_arr, triangle, sizeof(triangle));

		GLushort indices[] = { 0, 1, 2 };
		size_t indices_count = NUM_ARRAY_ELEMENTS(indices);
		GLushort* indices_arr = new GLushort[indices_count];
		memcpy(indices_arr, indices, sizeof(indices));

		return new Mesh(vertices_arr, indices_arr, vertices_count, indices_count);
	}

	Mesh* ShapeGenerator::makeCube()
	{
		Vertex triangle[] =
		{
			glm::vec3(-1.0f, +1.0f, +1.0f), // 0
			glm::vec3(+1.0f, +1.0f, +1.0f), // color
			glm::vec3(+1.0f, +1.0f, +1.0f), // 1
			glm::vec3(+1.0f, +1.0f, +1.0f), // color
			glm::vec3(+1.0f, +1.0f, -1.0f), // 2
			glm::vec3(+1.0f, +1.0f, +1.0f), // color
			glm::vec3(-1.0f, +1.0f, -1.0f), // 3
			glm::vec3(+1.0f, +1.0f, +1.0f), // color

			glm::vec3(-1.0f, +1.0f, -1.0f), // 4
			glm::vec3(+0.3f, +1.0f, +0.5f), // color
			glm::vec3(+1.0f, +1.0f, -1.0f), // 5
			glm::vec3(+0.3f, +1.0f, +0.5f), // color
			glm::vec3(+1.0f, -1.0f, -1.0f), // 6
			glm::vec3(+0.3f, +1.0f, +0.5f), // color
			glm::vec3(-1.0f, -1.0f, -1.0f), // 7
			glm::vec3(+0.3f, +1.0f, +0.5f), // color

			glm::vec3(+1.0f, +1.0f, -1.0f), // 8
			glm::vec3(+0.5f, +0.7f, +0.5f), // color
			glm::vec3(+1.0f, +1.0f, +1.0f), // 9
			glm::vec3(+0.5f, +0.7f, +0.5f), // color
			glm::vec3(+1.0f, -1.0f, +1.0f), // 10
			glm::vec3(+0.5f, +0.7f, +0.5f), // color
			glm::vec3(+1.0f, -1.0f, -1.0f), // 11
			glm::vec3(+0.5f, +0.7f, +0.5f), // color

			glm::vec3(-1.0f, +1.0f, +1.0f), // 12
			glm::vec3(+0.2f, +0.5f, +1.0f), // color
			glm::vec3(-1.0f, +1.0f, -1.0f), // 13
			glm::vec3(+0.2f, +0.5f, +1.0f), // color
			glm::vec3(-1.0f, -1.0f, -1.0f), // 14
			glm::vec3(+0.2f, +0.5f, +1.0f), // color
			glm::vec3(-1.0f, -1.0f, +1.0f), // 15
			glm::vec3(+0.2f, +0.5f, +1.0f), // color

			glm::vec3(+1.0f, +1.0f, +1.0f), // 16
			glm::vec3(+0.2f, +0.7f, +1.0f), // color
			glm::vec3(-1.0f, +1.0f, +1.0f), // 17
			glm::vec3(+0.2f, +0.7f, +1.0f), // color
			glm::vec3(-1.0f, -1.0f, +1.0f), // 18
			glm::vec3(+0.2f, +0.7f, +1.0f), // color
			glm::vec3(+1.0f, -1.0f, +1.0f), // 19
			glm::vec3(+0.2f, +0.7f, +1.0f), // color

			glm::vec3(+1.0f, -1.0f, -1.0f), // 20
			glm::vec3(+0.9f, +1.0f, +0.2f), // color
			glm::vec3(-1.0f, -1.0f, -1.0f), // 21
			glm::vec3(+0.9f, +1.0f, +0.2f), // color
			glm::vec3(-1.0f, -1.0f, +1.0f), // 22
			glm::vec3(+0.9f, +1.0f, +0.2f), // color
			glm::vec3(+1.0f, -1.0f, +1.0f), // 23
			glm::vec3(+0.9f, +1.0f, +0.2f), // color
		};

		GLushort indices[] = { 
			0,  1,  2,  0,  2,  3,  // Top
			4,  5,  6,  4,  6,  7,  // Front
			8,  9,  10, 8,  10, 11, // Right
			12, 13, 14, 12, 14, 15, // Left
			16, 17, 18, 16, 18, 19, // Back
			20, 22, 21, 20, 23, 22, // Bottom
		};

		size_t vertices_count = NUM_ARRAY_ELEMENTS(triangle);
		Vertex* vertices_arr = new Vertex[vertices_count];
		memcpy(vertices_arr, triangle, sizeof(triangle));

		size_t indices_count = NUM_ARRAY_ELEMENTS(indices);
		GLushort* indices_arr = new GLushort[indices_count];
		memcpy(indices_arr, indices, sizeof(indices));

		return new Mesh(vertices_arr, indices_arr, vertices_count, indices_count);
	}
}