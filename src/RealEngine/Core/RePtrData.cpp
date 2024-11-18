#include <RealEngine/Core/RePtrData.h>

namespace Re
{
    std::shared_ptr<RePtrData> RePtrData::GetEmptyObject()
    {
        static std::shared_ptr<RePtrData> emptyData = std::make_shared<RePtrData>(RePtrData{});
        return emptyData;
    }
}
