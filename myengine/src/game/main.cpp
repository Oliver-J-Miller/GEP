// game.cpp : Defines the entry point for the application.
//
#include <myengine/myengine.h>
#include <iostream>
#include "game.h"

using namespace myengine;

struct Player : Component
{
	void onTick()
	{
		std::cout << "I tick" << std::endl;
		m_count++;
		if (m_count == 10)
		{
			getEntity()->kill();
		}
	}
private:
	int m_count = 0;
};
int main()
{
	std::shared_ptr<Core> core = Core::initialize();

	//std::shared_ptr<Entity> entity = core->addEntity();
	//std::shared_ptr<Component> component = entity->addComponent<Component>();


	core->addEntity()->addComponent<Player>();
	core->start();
}
