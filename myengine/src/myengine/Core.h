#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include <SDL.h>
#include "NativeWindow.h"

namespace myengine
{
	struct Entity;

	struct Core
	{
		Core();
		~Core();
		
		static std::shared_ptr<Core> initialize();
		std::shared_ptr<Entity> addEntity();
		void start();
		void stop();

	private:
		NativeWindow m_native;
		std::vector<std::shared_ptr<Entity> > m_entities;
		bool m_running;
		int ticks;
		float INITIAL_HEIGHT;
		float INITIAL_WIDTH;

		std::weak_ptr<Core> m_self;
		
	};
}