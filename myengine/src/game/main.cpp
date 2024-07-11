// game.cpp : Defines the entry point for the application.
//
#include <myengine/myengine.h>
#include <myengine/TriangleRenderer.h>
#include <iostream>
#include "game.h"

using namespace myengine;

struct Player : Component
{
	void onTick()
	{
		//getEntity->getComponent<Transform>()->setRotation(...);
		std::cout << "I tick" << std::endl;
		m_count++;
		if (m_count == 100)
		{
			getEntity()->kill();
		}
	}
private:
	int m_count = 0;
};
#undef main
int main()
{
	std::shared_ptr<Core> core = Core::initialize();

	std::shared_ptr<Entity> entity = core->addEntity();
	//std::shared_ptr<Component> component = entity->addComponent<Component>();


	entity->addComponent<Player>();
	entity->addComponent<TriangleRenderer>();
	std::shared_ptr<Transform> t = entity->addComponent<Transform>();
	t->setPosition(glm::vec3{0,0,-20});

	core->start();

	return 0;
}
