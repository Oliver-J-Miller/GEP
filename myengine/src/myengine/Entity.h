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

			rtn->onInitialize();
			m_components.push_back(rtn);

			return rtn;
		}

		template <typename T>
		std::shared_ptr<T> getComponent()
		{
			for (int i = 0; i < m_components.size(); i++)
			{
				//find specified component using runtime type identification
				std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(m_components[i]);

				if (rtn)
				{
					return rtn;
				}
			}
			//throws if no matching component can be found
			throw std::runtime_error("failed to find specified component");
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