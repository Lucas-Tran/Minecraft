#include "Engine.h"

GLFWwindow *window;


KeyStatus Input::keys[1024];
double Input::mouseX;
double Input::mouseY;
double Input::mouseChangeX;
double Input::mouseChangeY;


float Time::time;
float Time::deltaTime;


void Input::EnablePointerLock() {
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}


void Input::DisablePointerLock() {
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    mouseChangeX = 0.0f;
    mouseChangeY = 0.0f;
    glfwGetCursorPos(window, &mouseX, &mouseY);
}

bool Input::IsPointerLocked() {
    return glfwGetInputMode(window, GLFW_CURSOR) == GLFW_CURSOR_DISABLED;
}