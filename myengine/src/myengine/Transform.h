#pragma once
#include "Component.h"
#include <rend/rend.h>


namespace myengine
{
	struct Transform : Component
	{
		Transform();
		void setPosition(glm::vec3 _position);
		glm::vec3 getPosition();
	private:
		glm::vec3 m_position;
		glm::vec3 m_rotation;
		glm::vec3 m_scale;
	};
}
