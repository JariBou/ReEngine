#include <RealEngine/Core/ReLevelBase.h>

namespace Re
{
    void ReLevelBase::LoadLevelInWorld(World* World)
    {
        PreLevelLoad(World);
        LevelLoad(World);
        PostLevelLoad(World);
    }
}
