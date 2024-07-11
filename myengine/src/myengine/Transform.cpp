#include "Transform.h"


namespace myengine 
{
	Transform::Transform()
	{
		m_scale = glm::vec3{ 1.0,1.0,1.0 };
	}
	void Transform::setPosition(glm::vec3 _position) 
	{
		m_position = _position;
	}
	glm::vec3 Transform::getPosition()
	{
		return m_position;
	}


}