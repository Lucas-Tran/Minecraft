#include "EngineProcessor.h"

#include <GLFW/glfw3.h>

double lastMouseX;
double lastMouseY;
float previousTime;

void EngineProcessor::Init() {
    glfwGetCursorPos(window, &lastMouseX, &lastMouseY);

    previousTime = glfwGetTime();
}

void EngineProcessor::TickPreProcess() {
    Time::time = glfwGetTime();
    Time::deltaTime = Time::time - previousTime;
    previousTime = Time::time;


    glfwGetCursorPos(window, &Input::mouseX, &Input::mouseY);
    Input::mouseChangeX = Input::mouseX - lastMouseX;
    Input::mouseChangeY = Input::mouseY - lastMouseY;

    for (unsigned int i = 0; i < 1024; i++) {
        if (glfwGetKey(window, i) == GLFW_PRESS) {
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

void EngineProcessor::TickPostProcess() {
    lastMouseX = Input::mouseX;
    lastMouseY = Input::mouseY;
}