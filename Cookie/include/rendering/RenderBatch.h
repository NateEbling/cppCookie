#ifndef RENDER_BATCH_H
#define RENDER_BATCH_H

#include "core.h"
#include "rendering/Shader.h"
#include "ecs/Entity.h"

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
		
	public:
		
	};
}

#endif
