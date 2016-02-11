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
    struct ObjectData;
	class Engine;
	class Mesh;
	class Shader;
	class Feature;
	class Scene;

	class Object
	{
	public:
		friend class Feature;
		typedef std::map<std::type_index, Feature*> FeaturesMap;
        typedef std::vector<Object*> Listeners;

		Object(const ObjectData& objectData);
		virtual ~Object();

		virtual void Awake() = 0;
		virtual void Update() = 0;
		virtual void Render() = 0;

		template <class T>
		void AddFeature(T* feature);

		template <class T>
		T* GetFeature();


		const std::string& GetName() const;
		void SetScene(Scene* scene);
		// with some command oprition...
		//virtual void SubScribe(Object* obj);
		//virtual void UnSubScribe(Object* obj);

	Transform* m_transform;
	protected:
		Mesh* m_mesh;
		Shader* m_shader;

		Engine * m_father;
		Scene* m_scene;

	private:
        FeaturesMap m_features;
        Listeners m_listeners;
        const std::string m_name;
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
        FeaturesMap::iterator iter = m_features.begin();
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