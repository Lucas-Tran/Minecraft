#ifndef CAMERA_H
#define CAMERA_H

#include "Engine.h"

class Camera {
public:
    Camera(glm::vec3 position, float pitch, float yaw, float FOV, float near, float far);

    void UpdateDirectionVectors();
    void UpdateViewMatrix();

    void UpdateProjectionMatrix();

    glm::mat4 GetViewMatrix();

    glm::mat4 GetProjectionMatrix();

    void Update();


private:
    glm::vec3 position;
    float pitch;
    float yaw;

    glm::mat4 view;
    glm::mat4 projection;

    glm::vec3 right;
    glm::vec3 up;
    glm::vec3 forward;

    float FOV;
    float near;
    float far;
};

#endif