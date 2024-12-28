#pragma once

#include <RealEngine/Core/Export.h>
#include <RealEngine/Core/ObjectHandling/ReHandledObject.h>

namespace Re
{
	class RE_CORE_API Chunk : ReHandledObject<Chunk>
	{
		public:
			Chunk() = default;
			Chunk(const Chunk&) = delete;
			Chunk(Chunk&&) = delete;
			~Chunk() = default;

			Chunk& operator=(const Chunk&) = delete;
			Chunk& operator=(Chunk&&) = delete;

		private:
	};
}

#include <RealEngine/Core/Physics/ChunkEngine/Chunk.inl>
