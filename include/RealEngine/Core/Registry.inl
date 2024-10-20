#pragma once

namespace Re
{
    template<class T>
    inline void Registry<T>::Register(T* pItem)
    {
        pItem->OnRegister();
        items.push_back(pItem);
    }

    template <class T>
    inline void Registry<T>::Unregister(IRegistryItem* registryItem)
    {
        auto it = items.begin();
        while (it != items.end())
        {
            // Somehow this uses IRegistryItem(const IRegistryItem & old) ???
            // Like wtf?
            if (*registryItem == *it)
            {
                it = items.erase(it);
                break;
            }
        }
        // auto registryItemIt = std::find(items.begin(), items.end(), registryItem);
        // items.erase(registryItemIt);
    }
}
