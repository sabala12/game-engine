#include "features/movement.h"
#include "components/game_object.h"

namespace Engine
{
	Movement::Movement(Object * father)
			: Feature(father)
	{
	}

	void Movement::Execute()
	{
		//m_father->m_transform->SetPos(m_father->m_transform->GetPos() + m_dir*m_speed);
	}
}