#pragma once
#include "core.h"

namespace Cookie
{
	class Camera
	{
	private:
		glm::mat4 projectionMatrix, viewMatrix, inverseProjection, inverseView;
		glm::vec2 projectionSize = { 32.0f * 40.0f, 32.0f * 40.0f };
	public:
		glm::vec2 position;
		Camera(glm::vec2 position);
		void adjustProjection();
		glm::mat4 getViewMatrix();
		glm::mat4 getInverseProjection() { return inverseProjection; }
		glm::mat4 getInverseView() { return inverseView; }
		glm::mat4 getProjectionMatrix() { return projectionMatrix; }
		glm::vec2 getProjectionSize() { return projectionSize; }
	};
}
