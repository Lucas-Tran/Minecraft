#include "EngineProcessor.h"

#include <GLFW/glfw3.h>

void EngineProcessor::Init() {
    glfwGetCursorPos(Window::window, &Input::mouseX, &Input::mouseY);

    Time::time = glfwGetTime();
}

void EngineProcessor::TickPreProcess() {
    double previousTime = Time::time;
    Time::time = glfwGetTime();
    Time::deltaTime = Time::time - previousTime;
    Time::FPS = round(1 / Time::deltaTime);
    previousTime = Time::time;


    double lastMouseX = Input::mouseX;
    double lastMouseY = Input::mouseY;
    glfwGetCursorPos(Window::window, &Input::mouseX, &Input::mouseY);
    Input::mouseChangeX = Input::mouseX - lastMouseX;
    Input::mouseChangeY = Input::mouseY - lastMouseY;

    for (unsigned int i = 0; i < 1024; i++) {
        if (glfwGetKey(Window::window, i) == GLFW_PRESS) {
            if (Input::keys[i].pressed) {
                Input::keys[i].firstPress = false;
            } else {
                Input::keys[i].firstPress = true;
            }
            Input::keys[i].pressed = true;
        } else {
            Input::keys[i].pressed = false;
            Input::keys[i].firstPress = false;
        }
    }
}