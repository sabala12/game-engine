#include "graphics/mesh.h"
#include "transform.h"

namespace Engine
{
	Mesh::Mesh(Vertex* vertices, GLushort* indices, GLuint numVertices, GLuint numIndices)
		: m_numVertices(numVertices), m_numIndices(numIndices), m_vertices(vertices), m_indices(indices)
	{
		glGenVertexArrays(1, &m_vertexArrayObjID);
		glBindVertexArray(m_vertexArrayObjID);

		glGenBuffers(1, &m_vertexBufferID);
		glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferID);
		glBufferData(GL_ARRAY_BUFFER, vertexBufferSize(), m_vertices, GL_STATIC_DRAW);

		glGenBuffers(1, &m_indexBufferID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBufferID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indicesBufferSize(), m_indices, GL_STATIC_DRAW); 
		
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (char*)(sizeof(float) * 3));
	}

	Mesh::~Mesh()
	{
		glDeleteBuffers(1, &m_vertexArrayObjID);
		glDeleteBuffers(1, &m_vertexBufferID);
		glDeleteBuffers(1, &m_indexBufferID);

		delete[] m_vertices;
		delete[] m_indices;
	}
}