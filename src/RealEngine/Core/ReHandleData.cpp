#include <RealEngine/Core/ReHandleData.h>

namespace Re
{
    std::shared_ptr<ReHandleData> ReHandleData::GetEmptyObject()
    {
        static std::shared_ptr<ReHandleData> emptyData = std::make_shared<ReHandleData>(ReHandleData{});
        return emptyData;
    }
}
