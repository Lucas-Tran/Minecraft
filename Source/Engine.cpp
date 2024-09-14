#include "Engine.h"

GLFWwindow *Window::window;

void Window::SetWindowCaption(std::string caption) {
    glfwSetWindowTitle(window, caption.c_str());
}


KeyStatus Input::keys[1024];
double Input::mouseX;
double Input::mouseY;
double Input::mouseChangeX;
double Input::mouseChangeY;


float Time::time;
float Time::deltaTime;
unsigned int Time::FPS;


void Input::EnablePointerLock() {
    glfwSetInputMode(Window::window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}


void Input::DisablePointerLock() {
    glfwSetInputMode(Window::window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    mouseChangeX = 0.0f;
    mouseChangeY = 0.0f;
    glfwGetCursorPos(Window::window, &mouseX, &mouseY);
}

bool Input::IsPointerLocked() {
    return glfwGetInputMode(Window::window, GLFW_CURSOR) == GLFW_CURSOR_DISABLED;
}