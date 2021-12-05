
#include "vulkan/vulkan.hpp"
#include "test.h"

#include <iostream>

static std::string AppName = "01_InitInstance";
static std::string EngineName = "Vulkan.hpp";

namespace vkge
{
    int doTest()
    {
        try
        {
            // initialize the vk::ApplicationInfo structure
            vk::ApplicationInfo applicationInfo(AppName.c_str(), 1, EngineName.c_str(), 1, VK_API_VERSION_1_1);

            // initialize the vk::InstanceCreateInfo
            vk::InstanceCreateInfo instanceCreateInfo({}, &applicationInfo);

            // create an Instance
            vk::Instance instance = vk::createInstance(instanceCreateInfo);
            
            std::cout << "extension count: " << instanceCreateInfo.enabledExtensionCount << std::endl;
            std::cout << "api version: " << applicationInfo.apiVersion << std::endl;
            // destroy it again
            instance.destroy();
        }
        catch (vk::SystemError& err)
        {
            std::cout << "vk::SystemError: " << err.what() << std::endl;
            exit(-1);
        }
        catch (std::exception& err)
        {
            std::cout << "std::exception: " << err.what() << std::endl;
            exit(-1);
        }
        catch (...)
        {
            std::cout << "unknown error\n";
            exit(-1);
        }

        return 0;
    }
}