#pragma once
#include <iostream>
#include <vector>
#include <memory>

namespace myengine
{
	struct Core;
	struct Component;
	struct Entity
	{
		template <typename T>
		std::shared_ptr<T> addComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();

			rtn->m_entity = m_self;

			rtn->initialize();
			m_components.push_back(rtn);

			return rtn;
		}
		bool alive();
		void kill();

	private:
		friend struct Core;
		void tick();
		void display();

		std::vector<std::shared_ptr<Component> > m_components;
		
		bool m_alive = true;
		std::weak_ptr<Core> m_core;
		std::weak_ptr<Entity> m_self;
	};
	
}