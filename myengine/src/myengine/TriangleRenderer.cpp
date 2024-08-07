#include "TriangleRenderer.h"
#include "Entity.h"
#include "Transform.h"

namespace myengine
{
	TriangleRenderer::TriangleRenderer()
	{
		//onInitialize();
	}

	void TriangleRenderer::onInitialize()
	{
		m_mesh.load(rend::TRIANGLE_MESH);
		m_shader.load(rend::COLOR_SHADER);


	}

	void TriangleRenderer::onDisplay()
	{
		m_shader.attribute("a_Position", *m_mesh.positions());

		m_shader.uniform("u_Projection", rend::perspective(rend::radians(45.0f), 1.0f, 0.1f, 100.0f));


		std::shared_ptr<Transform> t = getEntity()->getComponent<Transform>();
		m_shader.uniform("u_Model", rend::translate(rend::mat4(1.0f), t->getPosition()));

		m_shader.uniform("u_Color", rend::vec4(0.0f, 0.0f, 1.0f, 1.0f));

		m_shader.render();
	}
}

