#include <SDL.h>
#include <SDL_vulkan.h>
#include <vulkan/vulkan.h>

#include <algorithm>
#include <cstring>
#include <vector>

namespace {

bool Check(VkResult result, const char* operation) {
    if (result == VK_SUCCESS) {
        return true;
    }
    SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
            "%s failed with VkResult %d", operation, result);
    return false;
}

bool HasDeviceExtension(VkPhysicalDevice device, const char* name) {
    uint32_t count = 0;
    if (vkEnumerateDeviceExtensionProperties(device, nullptr, &count, nullptr)
            != VK_SUCCESS) {
        return false;
    }

    std::vector<VkExtensionProperties> extensions(count);
    if (vkEnumerateDeviceExtensionProperties(
                device, nullptr, &count, extensions.data()) != VK_SUCCESS) {
        return false;
    }

    return std::any_of(extensions.begin(), extensions.end(),
            [name](const VkExtensionProperties& extension) {
                return std::strcmp(extension.extensionName, name) == 0;
            });
}

class VulkanTest {
public:
    explicit VulkanTest(SDL_Window* window) : window_(window) {}

    ~VulkanTest() {
        if (device_ != VK_NULL_HANDLE) {
            vkDeviceWaitIdle(device_);
            if (frameFence_ != VK_NULL_HANDLE) {
                vkDestroyFence(device_, frameFence_, nullptr);
            }
            if (renderFinished_ != VK_NULL_HANDLE) {
                vkDestroySemaphore(device_, renderFinished_, nullptr);
            }
            if (imageAvailable_ != VK_NULL_HANDLE) {
                vkDestroySemaphore(device_, imageAvailable_, nullptr);
            }
            if (commandPool_ != VK_NULL_HANDLE) {
                vkDestroyCommandPool(device_, commandPool_, nullptr);
            }
            for (VkFramebuffer framebuffer : framebuffers_) {
                vkDestroyFramebuffer(device_, framebuffer, nullptr);
            }
            if (renderPass_ != VK_NULL_HANDLE) {
                vkDestroyRenderPass(device_, renderPass_, nullptr);
            }
            for (VkImageView imageView : imageViews_) {
                vkDestroyImageView(device_, imageView, nullptr);
            }
            if (swapchain_ != VK_NULL_HANDLE) {
                vkDestroySwapchainKHR(device_, swapchain_, nullptr);
            }
            vkDestroyDevice(device_, nullptr);
        }
        if (instance_ != VK_NULL_HANDLE && surface_ != VK_NULL_HANDLE
                && destroySurface_ != nullptr) {
            destroySurface_(instance_, surface_, nullptr);
        }
        if (instance_ != VK_NULL_HANDLE) {
            vkDestroyInstance(instance_, nullptr);
        }
        SDL_DestroyWindow(window_);
    }

    bool Initialize() {
        if (!CreateInstanceAndSurface()
                || !SelectPhysicalDevice()
                || !CreateLogicalDevice()
                || !CreateSwapchain()
                || !CreateRenderPassAndFramebuffers()
                || !CreateCommandBuffers()
                || !CreateSynchronization()) {
            return false;
        }

        SDL_Log("Vulkan ready: %s (API %u.%u.%u), swapchain %ux%u, %u images",
                properties_.deviceName,
                VK_VERSION_MAJOR(properties_.apiVersion),
                VK_VERSION_MINOR(properties_.apiVersion),
                VK_VERSION_PATCH(properties_.apiVersion),
                extent_.width, extent_.height,
                static_cast<unsigned int>(framebuffers_.size()));
        return true;
    }

    bool Run() {
        bool running = true;
        while (running) {
            SDL_Event event;
            while (SDL_PollEvent(&event) != 0) {
                if (event.type == SDL_QUIT
                        || (event.type == SDL_KEYDOWN
                            && (event.key.keysym.sym == SDLK_ESCAPE
                                || event.key.keysym.sym == SDLK_AC_BACK))) {
                    running = false;
                }
            }
            if (running && !RenderFrame()) {
                return false;
            }
        }
        SDL_Log("Vulkan swapchain test stopped");
        return true;
    }

private:
    bool CreateInstanceAndSurface() {
        unsigned int extensionCount = 0;
        if (SDL_Vulkan_GetInstanceExtensions(
                    window_, &extensionCount, nullptr) != SDL_TRUE) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                    "SDL_Vulkan_GetInstanceExtensions: %s", SDL_GetError());
            return false;
        }

        std::vector<const char*> extensions(extensionCount);
        if (SDL_Vulkan_GetInstanceExtensions(
                    window_, &extensionCount, extensions.data()) != SDL_TRUE) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                    "SDL_Vulkan_GetInstanceExtensions: %s", SDL_GetError());
            return false;
        }

        VkApplicationInfo applicationInfo{
            VK_STRUCTURE_TYPE_APPLICATION_INFO
        };
        applicationInfo.pApplicationName = "Spore ARM64 Vulkan test";
        applicationInfo.applicationVersion = VK_MAKE_VERSION(0, 1, 0);
        applicationInfo.pEngineName = "SDL2";
        applicationInfo.engineVersion = VK_MAKE_VERSION(
                SDL_MAJOR_VERSION, SDL_MINOR_VERSION, SDL_PATCHLEVEL);
        applicationInfo.apiVersion = VK_API_VERSION_1_0;

        VkInstanceCreateInfo instanceInfo{
            VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO
        };
        instanceInfo.pApplicationInfo = &applicationInfo;
        instanceInfo.enabledExtensionCount = extensionCount;
        instanceInfo.ppEnabledExtensionNames = extensions.data();
        if (!Check(vkCreateInstance(&instanceInfo, nullptr, &instance_),
                "vkCreateInstance")) {
            return false;
        }

        destroySurface_ = reinterpret_cast<PFN_vkDestroySurfaceKHR>(
                vkGetInstanceProcAddr(instance_, "vkDestroySurfaceKHR"));
        if (destroySurface_ == nullptr) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                    "vkDestroySurfaceKHR is unavailable");
            return false;
        }
        if (SDL_Vulkan_CreateSurface(window_, instance_, &surface_) != SDL_TRUE) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                    "SDL_Vulkan_CreateSurface: %s", SDL_GetError());
            return false;
        }
        return true;
    }

    bool SelectPhysicalDevice() {
        uint32_t deviceCount = 0;
        if (!Check(vkEnumeratePhysicalDevices(
                           instance_, &deviceCount, nullptr),
                "vkEnumeratePhysicalDevices")) {
            return false;
        }
        if (deviceCount == 0) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                    "Vulkan reported no physical devices");
            return false;
        }

        std::vector<VkPhysicalDevice> devices(deviceCount);
        if (!Check(vkEnumeratePhysicalDevices(
                           instance_, &deviceCount, devices.data()),
                "vkEnumeratePhysicalDevices")) {
            return false;
        }

        for (VkPhysicalDevice candidate : devices) {
            if (!HasDeviceExtension(
                        candidate, VK_KHR_SWAPCHAIN_EXTENSION_NAME)) {
                continue;
            }

            uint32_t familyCount = 0;
            vkGetPhysicalDeviceQueueFamilyProperties(
                    candidate, &familyCount, nullptr);
            std::vector<VkQueueFamilyProperties> families(familyCount);
            vkGetPhysicalDeviceQueueFamilyProperties(
                    candidate, &familyCount, families.data());

            for (uint32_t index = 0; index < familyCount; ++index) {
                VkBool32 supportsPresent = VK_FALSE;
                if ((families[index].queueFlags & VK_QUEUE_GRAPHICS_BIT) != 0
                        && vkGetPhysicalDeviceSurfaceSupportKHR(
                                   candidate, index, surface_, &supportsPresent)
                                == VK_SUCCESS
                        && supportsPresent == VK_TRUE) {
                    physicalDevice_ = candidate;
                    queueFamily_ = index;
                    vkGetPhysicalDeviceProperties(candidate, &properties_);
                    return true;
                }
            }
        }

        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                "No Vulkan graphics queue supports the SDL surface and swapchain");
        return false;
    }

    bool CreateLogicalDevice() {
        const float priority = 1.0f;
        VkDeviceQueueCreateInfo queueInfo{
            VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO
        };
        queueInfo.queueFamilyIndex = queueFamily_;
        queueInfo.queueCount = 1;
        queueInfo.pQueuePriorities = &priority;

        const char* extensions[] = {VK_KHR_SWAPCHAIN_EXTENSION_NAME};
        VkDeviceCreateInfo deviceInfo{
            VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO
        };
        deviceInfo.queueCreateInfoCount = 1;
        deviceInfo.pQueueCreateInfos = &queueInfo;
        deviceInfo.enabledExtensionCount = 1;
        deviceInfo.ppEnabledExtensionNames = extensions;
        if (!Check(vkCreateDevice(
                           physicalDevice_, &deviceInfo, nullptr, &device_),
                "vkCreateDevice")) {
            return false;
        }
        vkGetDeviceQueue(device_, queueFamily_, 0, &queue_);
        return true;
    }

    bool CreateSwapchain() {
        VkSurfaceCapabilitiesKHR capabilities{};
        if (!Check(vkGetPhysicalDeviceSurfaceCapabilitiesKHR(
                           physicalDevice_, surface_, &capabilities),
                "vkGetPhysicalDeviceSurfaceCapabilitiesKHR")) {
            return false;
        }
        if ((capabilities.supportedUsageFlags
                    & VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT) == 0) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                    "Vulkan surface images do not support color attachments");
            return false;
        }

        uint32_t formatCount = 0;
        if (!Check(vkGetPhysicalDeviceSurfaceFormatsKHR(
                           physicalDevice_, surface_, &formatCount, nullptr),
                "vkGetPhysicalDeviceSurfaceFormatsKHR")) {
            return false;
        }
        std::vector<VkSurfaceFormatKHR> formats(formatCount);
        if (formatCount == 0
                || !Check(vkGetPhysicalDeviceSurfaceFormatsKHR(
                                  physicalDevice_, surface_, &formatCount,
                                  formats.data()),
                        "vkGetPhysicalDeviceSurfaceFormatsKHR")) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                    "Vulkan surface has no usable formats");
            return false;
        }

        VkSurfaceFormatKHR format = formats.front();
        for (const VkSurfaceFormatKHR& candidate : formats) {
            if (candidate.format == VK_FORMAT_B8G8R8A8_UNORM
                    && candidate.colorSpace
                            == VK_COLOR_SPACE_SRGB_NONLINEAR_KHR) {
                format = candidate;
                break;
            }
        }
        swapchainFormat_ = format.format;

        extent_ = capabilities.currentExtent;
        if (extent_.width == UINT32_MAX) {
            int width = 0;
            int height = 0;
            SDL_Vulkan_GetDrawableSize(window_, &width, &height);
            extent_.width = static_cast<uint32_t>(std::clamp(
                    width,
                    static_cast<int>(capabilities.minImageExtent.width),
                    static_cast<int>(capabilities.maxImageExtent.width)));
            extent_.height = static_cast<uint32_t>(std::clamp(
                    height,
                    static_cast<int>(capabilities.minImageExtent.height),
                    static_cast<int>(capabilities.maxImageExtent.height)));
        }

        uint32_t imageCount = capabilities.minImageCount + 1;
        if (capabilities.maxImageCount > 0) {
            imageCount = std::min(imageCount, capabilities.maxImageCount);
        }

        const VkCompositeAlphaFlagBitsKHR alphaOptions[] = {
            VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR,
            VK_COMPOSITE_ALPHA_PRE_MULTIPLIED_BIT_KHR,
            VK_COMPOSITE_ALPHA_POST_MULTIPLIED_BIT_KHR,
            VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR
        };
        VkCompositeAlphaFlagBitsKHR compositeAlpha =
                VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
        bool foundCompositeAlpha = false;
        for (VkCompositeAlphaFlagBitsKHR option : alphaOptions) {
            if ((capabilities.supportedCompositeAlpha & option) != 0) {
                compositeAlpha = option;
                foundCompositeAlpha = true;
                break;
            }
        }
        if (!foundCompositeAlpha) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                    "Vulkan surface has no supported composite alpha mode");
            return false;
        }

        VkSwapchainCreateInfoKHR swapchainInfo{
            VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR
        };
        swapchainInfo.surface = surface_;
        swapchainInfo.minImageCount = imageCount;
        swapchainInfo.imageFormat = format.format;
        swapchainInfo.imageColorSpace = format.colorSpace;
        swapchainInfo.imageExtent = extent_;
        swapchainInfo.imageArrayLayers = 1;
        swapchainInfo.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
        swapchainInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
        swapchainInfo.preTransform = capabilities.currentTransform;
        swapchainInfo.compositeAlpha = compositeAlpha;
        swapchainInfo.presentMode = VK_PRESENT_MODE_FIFO_KHR;
        swapchainInfo.clipped = VK_TRUE;
        if (!Check(vkCreateSwapchainKHR(
                           device_, &swapchainInfo, nullptr, &swapchain_),
                "vkCreateSwapchainKHR")) {
            return false;
        }

        uint32_t actualImageCount = 0;
        if (!Check(vkGetSwapchainImagesKHR(
                           device_, swapchain_, &actualImageCount, nullptr),
                "vkGetSwapchainImagesKHR")) {
            return false;
        }
        std::vector<VkImage> images(actualImageCount);
        if (actualImageCount == 0
                || !Check(vkGetSwapchainImagesKHR(
                                  device_, swapchain_, &actualImageCount,
                                  images.data()),
                        "vkGetSwapchainImagesKHR")) {
            SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                    "Vulkan swapchain has no images");
            return false;
        }

        imageViews_.resize(images.size(), VK_NULL_HANDLE);
        for (size_t index = 0; index < images.size(); ++index) {
            VkImageViewCreateInfo viewInfo{
                VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO
            };
            viewInfo.image = images[index];
            viewInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
            viewInfo.format = format.format;
            viewInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
            viewInfo.subresourceRange.levelCount = 1;
            viewInfo.subresourceRange.layerCount = 1;
            if (!Check(vkCreateImageView(
                               device_, &viewInfo, nullptr, &imageViews_[index]),
                    "vkCreateImageView")) {
                return false;
            }
        }
        return true;
    }

    bool CreateRenderPassAndFramebuffers() {
        VkAttachmentDescription colorAttachment{};
        colorAttachment.format = swapchainFormat_;
        colorAttachment.samples = VK_SAMPLE_COUNT_1_BIT;
        colorAttachment.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
        colorAttachment.storeOp = VK_ATTACHMENT_STORE_OP_STORE;
        colorAttachment.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
        colorAttachment.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
        colorAttachment.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
        colorAttachment.finalLayout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;

        VkAttachmentReference colorReference{};
        colorReference.attachment = 0;
        colorReference.layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

        VkSubpassDescription subpass{};
        subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
        subpass.colorAttachmentCount = 1;
        subpass.pColorAttachments = &colorReference;

        VkRenderPassCreateInfo renderPassInfo{
            VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO
        };
        renderPassInfo.attachmentCount = 1;
        renderPassInfo.pAttachments = &colorAttachment;
        renderPassInfo.subpassCount = 1;
        renderPassInfo.pSubpasses = &subpass;
        if (!Check(vkCreateRenderPass(
                           device_, &renderPassInfo, nullptr, &renderPass_),
                "vkCreateRenderPass")) {
            return false;
        }

        framebuffers_.resize(imageViews_.size(), VK_NULL_HANDLE);
        for (size_t index = 0; index < imageViews_.size(); ++index) {
            VkFramebufferCreateInfo framebufferInfo{
                VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO
            };
            framebufferInfo.renderPass = renderPass_;
            framebufferInfo.attachmentCount = 1;
            framebufferInfo.pAttachments = &imageViews_[index];
            framebufferInfo.width = extent_.width;
            framebufferInfo.height = extent_.height;
            framebufferInfo.layers = 1;
            if (!Check(vkCreateFramebuffer(
                               device_, &framebufferInfo, nullptr,
                               &framebuffers_[index]),
                    "vkCreateFramebuffer")) {
                return false;
            }
        }
        return true;
    }

    bool CreateCommandBuffers() {
        VkCommandPoolCreateInfo poolInfo{
            VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO
        };
        poolInfo.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
        poolInfo.queueFamilyIndex = queueFamily_;
        if (!Check(vkCreateCommandPool(
                           device_, &poolInfo, nullptr, &commandPool_),
                "vkCreateCommandPool")) {
            return false;
        }

        commandBuffers_.resize(framebuffers_.size(), VK_NULL_HANDLE);
        VkCommandBufferAllocateInfo allocationInfo{
            VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO
        };
        allocationInfo.commandPool = commandPool_;
        allocationInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
        allocationInfo.commandBufferCount =
                static_cast<uint32_t>(commandBuffers_.size());
        if (!Check(vkAllocateCommandBuffers(
                           device_, &allocationInfo, commandBuffers_.data()),
                "vkAllocateCommandBuffers")) {
            return false;
        }

        for (size_t index = 0; index < commandBuffers_.size(); ++index) {
            VkCommandBufferBeginInfo beginInfo{
                VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO
            };
            beginInfo.flags = VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT;
            if (!Check(vkBeginCommandBuffer(commandBuffers_[index], &beginInfo),
                    "vkBeginCommandBuffer")) {
                return false;
            }

            VkClearValue clear{};
            clear.color.float32[0] = 0.06f;
            clear.color.float32[1] = 0.72f;
            clear.color.float32[2] = 0.68f;
            clear.color.float32[3] = 1.0f;
            VkRenderPassBeginInfo renderBegin{
                VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO
            };
            renderBegin.renderPass = renderPass_;
            renderBegin.framebuffer = framebuffers_[index];
            renderBegin.renderArea.extent = extent_;
            renderBegin.clearValueCount = 1;
            renderBegin.pClearValues = &clear;
            vkCmdBeginRenderPass(
                    commandBuffers_[index], &renderBegin,
                    VK_SUBPASS_CONTENTS_INLINE);
            vkCmdEndRenderPass(commandBuffers_[index]);
            if (!Check(vkEndCommandBuffer(commandBuffers_[index]),
                    "vkEndCommandBuffer")) {
                return false;
            }
        }
        return true;
    }

    bool CreateSynchronization() {
        VkSemaphoreCreateInfo semaphoreInfo{
            VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO
        };
        if (!Check(vkCreateSemaphore(
                           device_, &semaphoreInfo, nullptr, &imageAvailable_),
                "vkCreateSemaphore(imageAvailable)")
                || !Check(vkCreateSemaphore(
                                  device_, &semaphoreInfo, nullptr,
                                  &renderFinished_),
                        "vkCreateSemaphore(renderFinished)")) {
            return false;
        }

        VkFenceCreateInfo fenceInfo{
            VK_STRUCTURE_TYPE_FENCE_CREATE_INFO
        };
        fenceInfo.flags = VK_FENCE_CREATE_SIGNALED_BIT;
        return Check(vkCreateFence(
                             device_, &fenceInfo, nullptr, &frameFence_),
                "vkCreateFence");
    }

    bool RenderFrame() {
        if (!Check(vkWaitForFences(
                           device_, 1, &frameFence_, VK_TRUE, UINT64_MAX),
                "vkWaitForFences")) {
            return false;
        }

        uint32_t imageIndex = 0;
        VkResult acquireResult = vkAcquireNextImageKHR(
                device_, swapchain_, UINT64_MAX, imageAvailable_,
                VK_NULL_HANDLE, &imageIndex);
        if (acquireResult != VK_SUCCESS && acquireResult != VK_SUBOPTIMAL_KHR) {
            return Check(acquireResult, "vkAcquireNextImageKHR");
        }
        if (!Check(vkResetFences(device_, 1, &frameFence_), "vkResetFences")) {
            return false;
        }

        const VkPipelineStageFlags waitStage =
                VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
        VkSubmitInfo submitInfo{VK_STRUCTURE_TYPE_SUBMIT_INFO};
        submitInfo.waitSemaphoreCount = 1;
        submitInfo.pWaitSemaphores = &imageAvailable_;
        submitInfo.pWaitDstStageMask = &waitStage;
        submitInfo.commandBufferCount = 1;
        submitInfo.pCommandBuffers = &commandBuffers_[imageIndex];
        submitInfo.signalSemaphoreCount = 1;
        submitInfo.pSignalSemaphores = &renderFinished_;
        if (!Check(vkQueueSubmit(queue_, 1, &submitInfo, frameFence_),
                "vkQueueSubmit")) {
            return false;
        }

        VkPresentInfoKHR presentInfo{VK_STRUCTURE_TYPE_PRESENT_INFO_KHR};
        presentInfo.waitSemaphoreCount = 1;
        presentInfo.pWaitSemaphores = &renderFinished_;
        presentInfo.swapchainCount = 1;
        presentInfo.pSwapchains = &swapchain_;
        presentInfo.pImageIndices = &imageIndex;
        const VkResult presentResult = vkQueuePresentKHR(queue_, &presentInfo);
        if (presentResult != VK_SUCCESS && presentResult != VK_SUBOPTIMAL_KHR) {
            return Check(presentResult, "vkQueuePresentKHR");
        }
        return true;
    }

    SDL_Window* window_;
    VkInstance instance_ = VK_NULL_HANDLE;
    PFN_vkDestroySurfaceKHR destroySurface_ = nullptr;
    VkSurfaceKHR surface_ = VK_NULL_HANDLE;
    VkPhysicalDevice physicalDevice_ = VK_NULL_HANDLE;
    VkPhysicalDeviceProperties properties_{};
    uint32_t queueFamily_ = 0;
    VkDevice device_ = VK_NULL_HANDLE;
    VkQueue queue_ = VK_NULL_HANDLE;
    VkSwapchainKHR swapchain_ = VK_NULL_HANDLE;
    VkFormat swapchainFormat_ = VK_FORMAT_UNDEFINED;
    VkExtent2D extent_{};
    std::vector<VkImageView> imageViews_;
    VkRenderPass renderPass_ = VK_NULL_HANDLE;
    std::vector<VkFramebuffer> framebuffers_;
    VkCommandPool commandPool_ = VK_NULL_HANDLE;
    std::vector<VkCommandBuffer> commandBuffers_;
    VkSemaphore imageAvailable_ = VK_NULL_HANDLE;
    VkSemaphore renderFinished_ = VK_NULL_HANDLE;
    VkFence frameFence_ = VK_NULL_HANDLE;
};

}  // namespace

int RunVulkanTest() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                "SDL_Init: %s", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow(
            "Spore ARM64 - Vulkan",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            0,
            0,
            SDL_WINDOW_FULLSCREEN | SDL_WINDOW_SHOWN
                    | SDL_WINDOW_VULKAN | SDL_WINDOW_ALLOW_HIGHDPI);
    if (window == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                "Vulkan window: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    int result = 1;
    {
        VulkanTest test(window);
        if (test.Initialize() && test.Run()) {
            result = 0;
        }
    }
    SDL_Quit();
    return result;
}
