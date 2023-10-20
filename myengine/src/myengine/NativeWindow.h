//#pragma
#include <SDL.h>
#include <sys/memory.h>

namespace myengine
{
	struct NativeWindow
	{
		~NativeWindow();

	
		sys::zero<SDL_Window*> m_window;
		sys::zero<SDL_GLContext> m_context;
	};

}
