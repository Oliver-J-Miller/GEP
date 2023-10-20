#include "Core.h"
#include "Entity.h"
#include <rend/rend.h>

namespace myengine
{
	Core::Core()
	{
		INITIAL_HEIGHT = 480;
		INITIAL_WIDTH = 640;
	}
	Core::~Core()
	{
		//SDL_GL_DeleteContext(m_native.m_context);
		//SDL_DestroyWindow(m_native.m_window);
		//SDL_Quit();
	}
	std::shared_ptr<Core> Core::initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		rtn->m_self;

		if ((SDL_Init(SDL_INIT_VIDEO) < 0))
		{
			throw std::runtime_error("Failed to initialize SDL");
		}

		if (!(rtn->m_native.m_window = SDL_CreateWindow("SDL2 Platform", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
				rtn->INITIAL_WIDTH, rtn->INITIAL_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_REND)))
		{
			SDL_Quit();
			throw std::runtime_error("Failed to create window");
		}

		if (!(rtn->m_native.m_context = SDL_Rend_CreateContext(rtn->m_native.m_window)))
		{
			SDL_DestroyWindow(rtn->m_native.m_window);
			SDL_Quit();
			throw std::runtime_error("Failed to create OpenGL context");
		}

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
			SDL_Event event = { 0 };

			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					m_running = false;
				}
			}
			for (size_t ei = 0; ei < m_entities.size(); ++ei)
			{
				m_entities[ei]->tick();
			}
			//call display on all entities
			SDL_Rend_ClearWindow(m_native.m_window);

			for (size_t ei = 0; ei < m_entities.size(); ++ei)
			{
				m_entities[ei]->display();
			}

			SDL_Rend_SwapWindow(m_native.m_window);

		
			//remove "killed" entities
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