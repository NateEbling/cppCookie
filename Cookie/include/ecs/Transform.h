#ifndef TRANSFORM_H
#define TRANSFORM_H
#include "core.h"

namespace Cookie
{
	class Transform
	{
	private:

	public:
		glm::vec2 position;
		glm::vec2 scale;
		Transform();
		Transform(glm::vec2 position);
		Transform(glm::vec2 position, glm::vec2 scale);
		void init(glm::vec2 position, glm::vec2 scale);
		Transform copy();
		void copy(Transform t);
		bool equals(void* obj);
	};
}

#endif