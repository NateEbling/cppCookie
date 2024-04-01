#ifndef RENDER_BATCH_H
#define RENDER_BATCH_H

#include "core.h"
#include "rendering/Shader.h"
#include "ecs/Entity.h"
#include "rendering/SpriteRenderer.h"
#include "graphics/Texture.h"

namespace Cookie
{
	class RenderBatch
	{
	private:
		const int POS_SIZE = 2;
		const int COLOR_SIZE = 4;
		const int TEX_COORDS_SIZE = 2;
		const int TEX_ID_SIZE = 1;
		const int ENTITY_ID_SIZE = 1;
		const int POS_OFFSET = 0;
		const int COLOR_OFFSET = POS_OFFSET + POS_SIZE * 4;
		const int TEX_COORDS_OFFSET = COLOR_OFFSET + COLOR_SIZE * 4;
		const int TEX_ID_OFFSET = TEX_COORDS_OFFSET + TEX_COORDS_SIZE * 4;
		const int ENTITY_ID_OFFSET = TEX_ID_OFFSET + TEX_ID_SIZE * 4;
		const int VERTEX_SIZE = 10;
		const int VERTEX_SIZE_BYTES = VERTEX_SIZE * 4;
		SpriteRenderer* sprites;
		int numSprites;
		bool hasRoom;
		float* vertices;
		int texSlots[8] = { 0, 1, 2, 3, 4, 5, 6, 7 };
		std::vector<Texture*> textures;
		int vaoID, vboID;
		int maxBatchSize;
		int zIndex;
	public:
		RenderBatch(int maxBatchSize, int zIndex);
		void start();
		void addSprite(SpriteRenderer spr);
		void render();
		void loadVertexProperties(int index);
		int* generateIndices();
		void loadElementIndices(int* elements, int index);
		bool isThereRoom() { return this->hasRoom; }
		bool hasTextureRoom() { return this->textures.size() < 8; }
		bool hasTexture(Texture tex);
		int getzIndex() { return this->zIndex; }
		int compareTo(RenderBatch o);
	};
}

#endif
