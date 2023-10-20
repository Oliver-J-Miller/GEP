#include "NativeWindow.h"

namespace myengine
{
	NativeWindow::~NativeWindow()
	{
		SDL_GL_DeleteContext(m_context);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
	}
}

