#include "core.h"
#include "core/Camera.h"

namespace Cookie
{
	Camera::Camera(glm::vec2 pos)
		:position(pos)
	{
	}

	void Camera::adjustProjection()
	{
		// Set projectionMatrix equal to the identity matrix
		projectionMatrix = glm::mat4(1.0f);
		projectionMatrix = glm::ortho(0.0f, projectionSize.x, 0.0f, projectionSize.y, 0.0f, 100.0f);
		projectionMatrix = glm::inverse(inverseProjection);
	}

	glm::mat4 Camera::getViewMatrix()
	{
		glm::vec3 cameraFront = { 0.0f, 0.0f, -1.0f };
		glm::vec3 cameraUp = { 0.0f, 1.0f, 0.0f };
		viewMatrix = glm::mat4(1.0f);
		glm::vec3 tmp = cameraFront + glm::vec3(position.x, position.y, 0.0f);
		viewMatrix = glm::lookAt(glm::vec3(position.x, position.y, 20.0f), tmp, cameraUp);
		viewMatrix = glm::inverse(inverseView);

		return viewMatrix;
	}
}