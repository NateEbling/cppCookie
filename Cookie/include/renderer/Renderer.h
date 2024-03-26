#pragma once
#include "core.h"

namespace Cookie
{
	class Renderer
	{
	private:
		const int MAX_BATCH_SIZE = 1000;
		//std::vector<RenderBatch> batches;
		//void addSprite(SpriteRenderer sprite);
	public:
		//void addGameObject(GameObject go);
		void render();
	};
}