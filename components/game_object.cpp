#include <common_structs/object_data.h>
#include "components/game_object.h"
#include "components/scene.h"

namespace Engine
{
	Object::Object(const ObjectData& objectData)
		: m_father(objectData.m_father), m_mesh(objectData.m_mesh),
		  m_shader(objectData.m_shader), m_transform(objectData.m_transform),
		  m_name(objectData.m_name)
	{

	}

	Object::~Object()
	{
		delete m_transform;
		delete m_mesh;
		delete m_shader;
	}

	const std::string& Object::GetName() const {
		return m_name;
	}

	void Object::SetScene(Scene* scene) {
		m_scene = scene;
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