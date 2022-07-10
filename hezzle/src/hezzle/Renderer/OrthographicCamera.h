#pragma once

#include <glm/glm.hpp>

namespace hezzle
{
	class OrthographicCamera
	{
	public:
		OrthographicCamera(float left, float right, float bottom, float top);



		void SetPosition(const glm::vec3& position) { m_Position = position; }
		void SetRotation(float rotation) { m_Rotation = rotation; }
	private:
		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ViewProjectionMatrix;

		glm::vec3 m_Position;
		float m_Rotation = 0.0f;
	};
}

