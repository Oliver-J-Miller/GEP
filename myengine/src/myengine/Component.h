#pragma once
#include <iostream>
#include <memory>
namespace myengine
{
	struct Entity;
	struct Component 
	{
		std::shared_ptr<Entity> getEntity();
	private:
		friend struct Entity;
		virtual void onTick();
		virtual void onDisplay();

		void tick();
		void display();
		void kill();
		void initialize();

		std::weak_ptr<Entity> m_entity;
	};
}
