#include "Core.h"
#include "Entity.h"

namespace myengine
{
	Core::Core()
	{
		INITIAL_HEIGHT = 480;
		INITIAL_WIDTH = 640;
	}
	Core::~Core()
	{
		SDL_GL_DeleteContext(m_context);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
	}
	std::shared_ptr<Core> Core::initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		rtn->m_self;

		if ((SDL_Init(SDL_INIT_VIDEO) < 0))
		{
			throw std::runtime_error("Failed to initialize SDL");
		}

		if (!(rtn->m_window = SDL_CreateWindow("SDL2 Platform", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
				rtn->INITIAL_WIDTH, rtn->INITIAL_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL)))
		{
			SDL_Quit();
			throw std::runtime_error("Failed to create window");
		}

		if (!(rtn->m_context = SDL_GL_CreateContext(rtn->m_window)))
		{
			SDL_DestroyWindow(rtn->m_window);
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