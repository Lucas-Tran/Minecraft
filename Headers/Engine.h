#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <string>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


namespace Window {
    extern GLFWwindow *window;
    void SetWindowCaption(std::string caption);
}

struct KeyStatus {
    bool pressed;
    bool firstPress;
};

namespace Input {
    extern KeyStatus keys[1024];
    extern double mouseX;
    extern double mouseY;
    extern double mouseChangeX;
    extern double mouseChangeY;

    void EnablePointerLock();
    void DisablePointerLock();

    bool IsPointerLocked();
}

namespace Time {
    extern float time;
    extern float deltaTime;
    extern unsigned int FPS;
}

struct Vertex {
    glm::vec3 position;
    glm::vec2 textureCoordinates;
    glm::vec3 normal;
};

#endif