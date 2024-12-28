#pragma once

#include <map>
#include <RealEngine/Core/Export.h>
#include <RealEngine/Core/Physics/ChunkEngine/Chunk.h>
#include <RealEngine/Core/Structs/Vector2i.h>

namespace Re
{
	class RE_CORE_API ChunkEngine
	{
		public:
			ChunkEngine(const Vector2i& size);
			ChunkEngine(const ChunkEngine&) = delete;
			ChunkEngine(ChunkEngine&&) = delete;
			~ChunkEngine() = default;

			ChunkEngine& operator=(const ChunkEngine&) = delete;
			ChunkEngine& operator=(ChunkEngine&&) = delete;

		private:
			std::map<Vector2i, Chunk*> m_chunks;
	};
}

#include <RealEngine/Core/Physics/ChunkEngine/ChunkEngine.inl>
