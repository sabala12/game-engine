#ifndef GAME_ENGINE_GAME_OBJECT_H
#define GAME_ENGINE_GAME_OBJECT_H

#include "graphics/transform.h"
#include "constraints/feature_constraint.h"

#include <vector>
#include <map>
#include <typeinfo>
#include <typeindex>

namespace Engine
{
	class Engine;
	class Mesh;
	class Shader;
	class Feature;

	class Object
	{
	public:
		friend class Feature;
		typedef std::map<std::type_index, Feature*> features_map;

        Object(){

        }
		Object(Engine * father, Mesh* mesh, Shader* shader, Transform* transform);
		virtual ~Object();

		virtual void Awake() = 0;
		virtual void Update() = 0;
		virtual void Render() = 0;

		template <class T>
		void AddFeature(T* feature);

		template <class T>
		T* GetFeature();

		// with some command oprition...
		//virtual void SubScribe(Object* obj);
		//virtual void UnSubScribe(Object* obj);

	protected:
		Mesh* m_mesh;
		Shader* m_shader;
		Engine * m_father;
        Transform* m_transform;

	private:
        features_map m_features;
		//std::vector<Object*> m_listenrs;
	};

	template <class T>
	void Object::AddFeature(T* feature) {
        FeatureConstraint<T>();
		m_features[std::type_index(typeid(T))] = feature;
	}

	template<class T>
	T*Object::GetFeature()
	{
        FeatureConstraint<T>();
        features_map::iterator iter = m_features.begin();
		std::type_index key(typeid(T));
		for (iter; iter != m_features.end(); iter++)
		{
			if (iter->first == key)
				return static_cast<T*>(iter->second);
		}

		std::string error = std::string("type ") + std::string(key.name()) + std::string("is not defined in m_features");
		throw std::runtime_error(error.c_str());
	}

}

#endif //GAME_ENGINE_GAME_OBJECT_H