package dev.sporeport.cellstage;

import org.libsdl.app.SDLActivity;

public final class SDLDirect3D9TestActivity extends SDLActivity {
    @Override
    protected String[] getArguments() {
        return new String[]{"--spore-d3d9-test"};
    }
}
