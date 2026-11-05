package dev.sporeport.cellstage;

import android.content.Context;
import android.opengl.GLSurfaceView;
import android.view.MotionEvent;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

public final class NativeCellView extends GLSurfaceView {
    static {
        System.loadLibrary("spore_native_cell");
    }

    private final Renderer renderer = new Renderer();

    public NativeCellView(Context context) {
        super(context);
        setEGLContextClientVersion(2);
        setRenderer(renderer);
        setRenderMode(GLSurfaceView.RENDERMODE_CONTINUOUSLY);
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        if (event.getAction() == MotionEvent.ACTION_DOWN ||
                event.getAction() == MotionEvent.ACTION_MOVE) {
            nativeInput(event.getX(), event.getY());
            return true;
        }
        return super.onTouchEvent(event);
    }

    private static final class Renderer implements GLSurfaceView.Renderer {
        private long previousNanos;

        @Override
        public void onSurfaceCreated(GL10 gl, EGLConfig config) {
            nativeSurfaceCreated();
        }

        @Override
        public void onSurfaceChanged(GL10 gl, int width, int height) {
            nativeSurfaceChanged(width, height);
        }

        @Override
        public void onDrawFrame(GL10 gl) {
            long now = System.nanoTime();
            float deltaSeconds = previousNanos == 0L
                    ? 1.0f / 60.0f
                    : Math.min(0.05f, (now - previousNanos) / 1e9f);
            previousNanos = now;
            nativeDraw(deltaSeconds);
        }
    }

    private static native void nativeSurfaceCreated();
    private static native void nativeSurfaceChanged(int width, int height);
    private static native void nativeInput(float x, float y);
    private static native void nativeDraw(float deltaSeconds);
}
