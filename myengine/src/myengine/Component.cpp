#include "Component.h"

namespace myengine
{
	std::shared_ptr<Entity> Component::getEntity()
	{
		return m_entity.lock();
	}
	void Component::onTick()
	{
		std::cout << "I tick" << std::endl;
	}
	void Component::onDisplay()
	{
		std::cout << "I display" << std::endl;
	}
	void Component::tick()
	{
		onTick();
	}
	void Component::display()
	{
		onDisplay();
	}
	void Component::kill()
	{
	}
	void Component::onInitialize()
	{
		std::cout << "I initialize" << std::endl;
	}
}

