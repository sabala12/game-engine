#include "components/game_object.h"
#include "graphics/shader.h"
#include "graphics/mesh.h"

namespace Engine
{
	Object::Object(Engine * father, Mesh* mesh, Shader* shader, Transform* transform)
		: m_father(father), m_mesh(mesh), m_shader(shader), m_transform(transform)
	{

	}

	Object::~Object()
	{
		delete m_transform;
		delete m_mesh;
		delete m_shader;
	}

//	void Object::SubScribe(Object* obj)
//	{
//		m_listenrs.push_back(obj);
//	}
//
//	void Object::UnSubScribe(Object* obj)
//	{
//		// find the object and remove..
//		// change to map
//		m_listenrs.push_back(obj);
//	}
}