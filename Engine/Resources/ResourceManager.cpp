#include "pch.h"
#include "ResourceManager.h"

namespace Engine
{

    bool ResourceManager::Startup()
    {
        return true;
    }
    
    void ResourceManager::Shutdown()
    {
        RemoveAll();
    }
    
    void ResourceManager::Update()
    {
    }
    void ResourceManager::RemoveAll()
    {
        //std::pair < int, std::string> o;
        for (auto resource : resources)
        {
            resource.second->Destroy();
            delete resource.second;
        }

        resources.clear();
    }
}
