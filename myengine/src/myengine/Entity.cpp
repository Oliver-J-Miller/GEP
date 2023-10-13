#include "Entity.h"
#include "Component.h"
#include "Core.h"

namespace myengine
{
	
	void Entity::tick()
	{
		for (size_t ci = 0; ci < m_components.size(); ++ci)
		{
			m_components.at(ci)->tick();
		}
	}
	void Entity::display()
	{
		for (size_t ci = 0; ci < m_components.size(); ++ci)
		{
			m_components.at(ci)->display();
		}
	}
	bool Entity::alive()
	{
		std::cout << m_alive << std::endl;
		return m_alive;
	}
	void Entity::kill()
	{
		std::cout << "I kill" << std::endl;
		if (!m_alive) return;

		m_alive = false;

		for (size_t ci = 0; ci < m_components.size(); ++ci)
		{
			m_components.at(ci)->kill();
		}
	}
}
