#pragma once
#include "Component.h"

#include <rend/rend.h>

namespace myengine
{
	struct TriangleRenderer : Component
	{
		TriangleRenderer();
		void onInitialize();

	private:
		rend::Mesh m_mesh;
		rend::Shader m_shader;

		void onDisplay();
	};

}