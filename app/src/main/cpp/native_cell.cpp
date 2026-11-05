#include <jni.h>
#include <GLES2/gl2.h>
#include <android/log.h>

#include <array>
#include <cmath>
#include <cstdint>
#include <cstring>

namespace {
constexpr float kPlayerRadius = 38.0f;
constexpr int kFoodCount = 18;

struct Food {
    float x;
    float y;
    float radius;
    float hue;
};

struct Engine {
    float width = 1.0f;
    float height = 1.0f;
    float playerX = 0.0f;
    float playerY = 0.0f;
    float targetX = 0.0f;
    float targetY = 0.0f;
    float velocityX = 0.0f;
    float velocityY = 0.0f;
    float nutrients = 0.0f;
    std::array<Food, kFoodCount> food{};
    GLuint program = 0;
    GLint positionLocation = -1;
    GLint resolutionLocation = -1;
    GLint colorLocation = -1;
};

Engine g_engine;

GLuint compileShader(GLenum type, const char* source) {
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);
    GLint compiled = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
    if (!compiled) {
        __android_log_print(ANDROID_LOG_ERROR, "SporeNative",
                            "Shader compilation failed");
        glDeleteShader(shader);
        return 0;
    }
    return shader;
}

bool createProgram() {
    const char* vertexSource =
        "attribute vec2 position;\n"
        "uniform vec2 resolution;\n"
        "void main(){\n"
        " vec2 clip=(position/resolution)*2.0-1.0;\n"
        " clip.y=-clip.y;\n"
        " gl_Position=vec4(clip,0.0,1.0);\n"
        "}\n";
    const char* fragmentSource =
        "precision mediump float;\n"
        "uniform vec4 color;\n"
        "void main(){ gl_FragColor=color; }\n";

    GLuint vertex = compileShader(GL_VERTEX_SHADER, vertexSource);
    GLuint fragment = compileShader(GL_FRAGMENT_SHADER, fragmentSource);
    if (!vertex || !fragment) {
        return false;
    }

    g_engine.program = glCreateProgram();
    glAttachShader(g_engine.program, vertex);
    glAttachShader(g_engine.program, fragment);
    glLinkProgram(g_engine.program);
    glDeleteShader(vertex);
    glDeleteShader(fragment);

    GLint linked = 0;
    glGetProgramiv(g_engine.program, GL_LINK_STATUS, &linked);
    if (!linked) {
        glDeleteProgram(g_engine.program);
        g_engine.program = 0;
        return false;
    }

    g_engine.positionLocation = glGetAttribLocation(g_engine.program, "position");
    g_engine.resolutionLocation = glGetUniformLocation(g_engine.program, "resolution");
    g_engine.colorLocation = glGetUniformLocation(g_engine.program, "color");
    return true;
}

void seedFood() {
    uint32_t state = 0x5f3759dfu;
    for (auto& food : g_engine.food) {
        state = state * 1664525u + 1013904223u;
        float fx = static_cast<float>(state % 10000u) / 10000.0f;
        state = state * 1664525u + 1013904223u;
        float fy = static_cast<float>(state % 10000u) / 10000.0f;
        food.x = 20.0f + fx * (g_engine.width - 40.0f);
        food.y = 20.0f + fy * (g_engine.height - 40.0f);
        food.radius = 5.0f + (state % 5u);
        food.hue = 0.0f;
    }
}

void drawCircle(float x, float y, float radius, float r, float g, float b, float a) {
    std::array<GLfloat, 68> vertices{};
    vertices[0] = x;
    vertices[1] = y;
    for (int i = 0; i <= 32; ++i) {
        float angle = 6.28318530718f * static_cast<float>(i) / 32.0f;
        vertices[2 + i * 2] = x + std::cos(angle) * radius;
        vertices[3 + i * 2] = y + std::sin(angle) * radius;
    }
    glUniform2f(g_engine.resolutionLocation, g_engine.width, g_engine.height);
    glUniform4f(g_engine.colorLocation, r, g, b, a);
    glVertexAttribPointer(g_engine.positionLocation, 2, GL_FLOAT, GL_FALSE, 0, vertices.data());
    glEnableVertexAttribArray(g_engine.positionLocation);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 34);
}

float distanceSquared(float ax, float ay, float bx, float by) {
    float dx = ax - bx;
    float dy = ay - by;
    return dx * dx + dy * dy;
}
}

extern "C" JNIEXPORT void JNICALL
Java_dev_sporeport_cellstage_NativeCellView_nativeSurfaceCreated(JNIEnv*, jclass) {
    glDisable(GL_DEPTH_TEST);
    glClearColor(0.027f, 0.078f, 0.118f, 1.0f);
    createProgram();
}

extern "C" JNIEXPORT void JNICALL
Java_dev_sporeport_cellstage_NativeCellView_nativeSurfaceChanged(
    JNIEnv*, jclass, jint width, jint height) {
    g_engine.width = static_cast<float>(width);
    g_engine.height = static_cast<float>(height);
    g_engine.playerX = width * 0.5f;
    g_engine.playerY = height * 0.58f;
    g_engine.targetX = g_engine.playerX;
    g_engine.targetY = g_engine.playerY;
    glViewport(0, 0, width, height);
    seedFood();
}

extern "C" JNIEXPORT void JNICALL
Java_dev_sporeport_cellstage_NativeCellView_nativeInput(
    JNIEnv*, jclass, jfloat x, jfloat y) {
    g_engine.targetX = x;
    g_engine.targetY = y;
}

void updateEngine(float deltaSeconds) {
    float dx = g_engine.targetX - g_engine.playerX;
    float dy = g_engine.targetY - g_engine.playerY;
    float distance = std::sqrt(dx * dx + dy * dy);
    if (distance > 3.0f) {
        float nx = dx / distance;
        float ny = dy / distance;
        float acceleration = 760.0f;
        g_engine.velocityX += nx * acceleration * deltaSeconds;
        g_engine.velocityY += ny * acceleration * deltaSeconds;
    }

    float speed = std::sqrt(g_engine.velocityX * g_engine.velocityX +
                            g_engine.velocityY * g_engine.velocityY);
    if (speed > 330.0f) {
        g_engine.velocityX *= 330.0f / speed;
        g_engine.velocityY *= 330.0f / speed;
    }
    float damping = std::pow(0.985f, deltaSeconds * 60.0f);
    g_engine.velocityX *= damping;
    g_engine.velocityY *= damping;
    g_engine.playerX += g_engine.velocityX * deltaSeconds;
    g_engine.playerY += g_engine.velocityY * deltaSeconds;

    for (auto& food : g_engine.food) {
        if (distanceSquared(g_engine.playerX, g_engine.playerY, food.x, food.y) <
            (kPlayerRadius + food.radius) * (kPlayerRadius + food.radius)) {
            g_engine.nutrients += 1.0f;
            uint32_t seed = static_cast<uint32_t>(g_engine.nutrients * 9187.0f);
            food.x = static_cast<float>(seed % 10000u) / 10000.0f * g_engine.width;
            seed = seed * 1664525u + 1013904223u;
            food.y = static_cast<float>(seed % 10000u) / 10000.0f * g_engine.height;
        }
    }
}

extern "C" JNIEXPORT void JNICALL
Java_dev_sporeport_cellstage_NativeCellView_nativeStep(JNIEnv*, jclass, jfloat deltaSeconds) {
    updateEngine(deltaSeconds);
}

extern "C" JNIEXPORT void JNICALL
Java_dev_sporeport_cellstage_NativeCellView_nativeDraw(JNIEnv*, jclass, jfloat deltaSeconds) {
    updateEngine(deltaSeconds);
    glClear(GL_COLOR_BUFFER_BIT);
    if (!g_engine.program) {
        return;
    }
    glUseProgram(g_engine.program);

    for (int i = 0; i < 28; ++i) {
        float x = std::fmod(static_cast<float>(i * 137 + 31), g_engine.width);
        float y = std::fmod(static_cast<float>(i * 211 + 73), g_engine.height);
        drawCircle(x, y, 2.5f + (i % 3), 0.20f, 0.42f, 0.51f, 0.55f);
    }
    for (const auto& food : g_engine.food) {
        drawCircle(food.x, food.y, food.radius * 1.45f, 0.20f, 0.55f, 0.43f, 0.22f);
        drawCircle(food.x, food.y, food.radius, 0.40f, 0.82f, 0.48f, 1.0f);
    }
    drawCircle(g_engine.playerX, g_engine.playerY, kPlayerRadius * 1.08f,
               0.12f, 0.48f, 0.50f, 0.35f);
    drawCircle(g_engine.playerX, g_engine.playerY, kPlayerRadius,
               0.35f, 0.84f, 0.78f, 1.0f);
}
