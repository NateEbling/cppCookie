#include "core.h"
#include "rendering/RenderBatch.h"

namespace Cookie
{
	

	RenderBatch::RenderBatch(int maxBatchSize, int zIndex)
		:maxBatchSize(maxBatchSize),
		zIndex(zIndex)
	{
		this->sprites = new SpriteRenderer[maxBatchSize];
		this->vertices = new float[maxBatchSize * 4 * VERTEX_SIZE];

		this->numSprites = 0;
		this->hasRoom = true;

		this->textures = std::vector<Texture*>();
		
		this->vaoID = NULL;
		this->vboID = NULL;
	}

	void RenderBatch::start()
	{

	}

	void RenderBatch::addSprite(SpriteRenderer spr)
	{

	}

	void RenderBatch::render()
	{

	}

	void RenderBatch::loadVertexProperties(int index)
	{

	}

	int* RenderBatch::generateIndices()
	{
		int* elements = new int[6 * maxBatchSize];
		for (int i = 0; i < maxBatchSize; i++)
		{
			loadElementIndices(elements, i);
		}

		return elements;
	}

	void RenderBatch::loadElementIndices(int* elements, int index)
	{
		int offsetArrayIndex = 6 * index;
		int offset = 4 * index;

		// Triangle 1 
		elements[offsetArrayIndex] = offset + 3;
		elements[offsetArrayIndex + 1] = offset + 2;
		elements[offsetArrayIndex + 2] = offset + 0;

		// Triangle 2
		elements[offsetArrayIndex + 3] = offset + 0;
		elements[offsetArrayIndex + 4] = offset + 2;
		elements[offsetArrayIndex + 5] = offset + 1;

		delete elements;
	}

	// TODO: RenderBatch::hasTexture
	bool RenderBatch::hasTexture(Texture tex)
	{
		
	}

	// TODO: RenderBatch::compareTo
	int RenderBatch::compareTo(RenderBatch o)
	{

	}
}