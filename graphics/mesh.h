#ifndef GAME_ENGINE_MESH_H
#define GAME_ENGINE_MESH_H

#include <GL/glew.h>
#include <glm/glm.hpp>

namespace Engine
{
	class Transform;

	struct Vertex
	{
	public:
		glm::vec3 position;
		glm::vec3 color;
		//glm::vec3 normal;
	};

	class Mesh
	{
	public:
		Mesh(Vertex* vertices, GLushort* indices, GLuint numVertices, GLuint numIndices);
		~Mesh();

		inline GLsizeiptr vertexBufferSize() const
		{
			return m_numVertices * sizeof(Vertex);
		}
		inline GLsizeiptr indicesBufferSize() const
		{
			return m_numIndices * sizeof(GLushort);
		}

		inline GLuint GetVertexArrayObjID() { return m_vertexArrayObjID; }

		inline GLuint GetNumVertices() { return m_numVertices; }
		inline GLuint GetNumIndices() { return m_numIndices; }

	private:
		GLuint m_vertexArrayObjID;
		GLuint m_vertexBufferID;
		GLuint m_indexBufferID;
		//GLuint m_transformationMatrixBufferID;

		Vertex* m_vertices;
		GLushort* m_indices;
		GLuint m_numVertices;
		GLuint m_numIndices;
	};
}

#endif //GAME_ENGINE_MESH_H