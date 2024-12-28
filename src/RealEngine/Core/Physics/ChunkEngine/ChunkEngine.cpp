#include <RealEngine/Core/Physics/ChunkEngine/ChunkEngine.h>

namespace Re
{
    ChunkEngine::ChunkEngine(const Vector2i& size)
    {
        for (int X = 0; X < size.X; ++X)
        {
            for (int Y = 0; Y < size.Y; ++Y)
            {
                Chunk* chunk = new Chunk();
                m_chunks.emplace(Vector2i(X, Y), chunk);
            }
        }
    }
}
