#include "Camera.h"

const float SPEED = 5.0f;


Camera::Camera(glm::vec3 position, float pitch, float yaw, float FOV, float near, float far): position(position), pitch(pitch), yaw(yaw), FOV(FOV), near(near), far(far) {
    this->UpdateDirectionVectors();
    this->UpdateViewMatrix();
}

void Camera::UpdateDirectionVectors() {
    float pitch = glm::radians(this->pitch);
    float yaw = glm::radians(this->yaw);

    this->forward.x = cos(pitch) * sin(yaw);
    this->forward.y = -sin(pitch);
    this->forward.z = -cos(pitch) * cos(yaw);

    this->right = glm::normalize(glm::cross(this->forward, glm::vec3(0.0f, 1.0f, 0.0f)));
    this->up = glm::cross(this->right, this->forward);
}

void Camera::UpdateViewMatrix() {
    this->view = glm::mat4(glm::vec4(this->right, 0.0f), glm::vec4(this->up, 0.0f), glm::vec4(-this->forward, 0.0f), glm::vec4(this->position, 1.0f));
    this->view = glm::inverse(this->view);
}

void Camera::UpdateProjectionMatrix() {
    int width, height;
    glfwGetWindowSize(window, &width, &height);
    this->projection = glm::perspective(glm::radians(this->FOV), (float)width/height, this->near, this->far);
}

glm::mat4 Camera::GetViewMatrix() {
    return this->view;
}

glm::mat4 Camera::GetProjectionMatrix() {
    return this->projection;
}

void Camera::Update() {
    if (Input::keys[GLFW_KEY_ESCAPE].firstPress) {
        if (Input::IsPointerLocked()) {
            Input::DisablePointerLock();
        } else {
            Input::EnablePointerLock();
        }
    }
    if (Input::IsPointerLocked()) {
        this->yaw += Input::mouseChangeX;
        this->pitch += Input::mouseChangeY;
    }
    this->pitch = glm::clamp(this->pitch, -89.0f, 89.0f);

    UpdateDirectionVectors();
    float speed = SPEED * Time::deltaTime;
    if (Input::keys[GLFW_KEY_W].pressed) {
        this->position += this->forward * speed;
    }
    if (Input::keys[GLFW_KEY_S].pressed) {
        this->position -= this->forward * speed;
    }
    if (Input::keys[GLFW_KEY_A].pressed) {
        this->position -= this->right * speed;
    }
    if (Input::keys[GLFW_KEY_D].pressed) {
        this->position += this->right * speed;
    }
    if (Input::keys[GLFW_KEY_E].pressed) {
        this->position += this->up * speed;
    }
    if (Input::keys[GLFW_KEY_Q].pressed) {
        this->position -= this->up * speed;
    }

    UpdateViewMatrix();
}