package dev.sporeport.cellstage;

import org.libsdl.app.SDLActivity;

public final class SDLVulkanTestActivity extends SDLActivity {
    @Override
    protected String[] getArguments() {
        return new String[]{"--spore-vulkan-test"};
    }
}
