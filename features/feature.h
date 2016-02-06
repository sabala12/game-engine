#ifndef GAME_ENGINE_FEATURE_H
#define GAME_ENGINE_FEATURE_H

#include "components/game_object.h"
#include "common_structs/feature_operation_data.h"

namespace Engine
{
	class Feature
	{
	public:

		Feature(Object* object)
			: m_object(object)
		{
		}

	protected:
		Object* m_object;
	};
}

#endif //GAME_ENGINE_FEATURE_H