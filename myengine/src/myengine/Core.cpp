#include "Core.h"
#include "Entity.h"

namespace myengine
{
	std::shared_ptr<Core> Core::initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		rtn->m_self;
		//rtn->m_nativeWindow = SDL_CreateWindow();
		return rtn;
	}
	std::shared_ptr<Entity> Core::addEntity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();

		rtn->m_core = m_self;
		rtn->m_self = rtn;

		m_entities.push_back(rtn);

		return rtn;
	}
	void Core::start()
	{
		m_running = true;
		ticks = 0;
		while (m_running)
		{
			//SDL stuff
			
			//call display on all entities
			//remove "killed" entities

			for (size_t ei = 0; ei < m_entities.size(); ++ei)
			{
				m_entities[ei]->tick();
			}

			for (size_t ei = 0; ei < m_entities.size(); ++ei)
			{
				if (!m_entities[ei]->alive())
				{
					m_entities.erase(m_entities.begin() + ei);
					--ei;
				}
			}
			
		}
	}
	void Core::stop()
	{
		m_running = false;
	}
}