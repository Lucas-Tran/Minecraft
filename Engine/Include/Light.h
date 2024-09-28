#ifndef LIGHT_H
#define LIGHT_H

#include "Engine.h"
#include "ShaderProgram.h"

namespace Light {
    struct DirectionalLight {
        glm::vec3 direction;

        glm::vec3 color;

        float ambientIntensity;
        float diffuseIntensity;
        float specularIntensity;
    };
    
    struct PointLight {
        glm::vec3 position;

        glm::vec3 color;

        float ambientIntensity;
        float diffuseIntensity;
        float specularIntensity;
    
        float quadratic;
        float linear;
        float constant;
    };
    
    struct SpotLight {
        glm::vec3 position;
        glm::vec3 direction;

        float innerCutOffDegrees;
        float outerCutOffDegrees;

        glm::vec3 color;

        float ambientIntensity;
        float diffuseIntensity;
        float specularIntensity;

        float quadratic;
        float linear;
        float constant;
    };

    void UniformLight(ShaderProgram &shaderProgram, DirectionalLight &directionalLight);
    void UniformLight(ShaderProgram &shaderProgram, unsigned int ID, PointLight &pointLight);
    void UniformLight(ShaderProgram &shaderProgram, unsigned int ID, SpotLight &spotLight);
}

#endif