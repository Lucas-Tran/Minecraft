#include "Light.h"
#include <string>

void Light::UniformLight(ShaderProgram &shaderProgram, DirectionalLight &directionalLight) {
    shaderProgram.SetUniform("directionalLight.direction", directionalLight.direction);
    shaderProgram.SetUniform("directionalLight.color", directionalLight.color);
    shaderProgram.SetUniform("directionalLight.ambientIntensity", directionalLight.ambientIntensity);
    shaderProgram.SetUniform("directionalLight.diffuseIntensity", directionalLight.diffuseIntensity);
    shaderProgram.SetUniform("directionalLight.specularIntensity", directionalLight.specularIntensity);
}

void Light::UniformLight(ShaderProgram &shaderProgram, unsigned int ID, PointLight &pointLight) {
    std::string uniformLight = "pointLights[" + std::to_string(ID) + "]";
    shaderProgram.SetUniform(uniformLight + ".position", pointLight.position);
    shaderProgram.SetUniform(uniformLight + ".color", pointLight.color);
    shaderProgram.SetUniform(uniformLight + ".ambientIntensity", pointLight.ambientIntensity);
    shaderProgram.SetUniform(uniformLight + ".diffuseIntensity", pointLight.diffuseIntensity);
    shaderProgram.SetUniform(uniformLight + ".specularIntensity", pointLight.specularIntensity);
    shaderProgram.SetUniform(uniformLight + ".quadratic", pointLight.quadratic);
    shaderProgram.SetUniform(uniformLight + ".linear", pointLight.linear);
    shaderProgram.SetUniform(uniformLight + ".constant", pointLight.constant);
}

void Light::UniformLight(ShaderProgram &shaderProgram, unsigned int ID, SpotLight &spotLight) {
    std::string uniformLight = "spotLights[" + std::to_string(ID) + "]";
    shaderProgram.SetUniform(uniformLight + ".position", spotLight.position);
    shaderProgram.SetUniform(uniformLight + ".direction", spotLight.direction);
    shaderProgram.SetUniform(uniformLight + ".innerCutOff", cos(glm::radians(spotLight.innerCutOffDegrees)));
    shaderProgram.SetUniform(uniformLight + ".outerCutOff", cos(glm::radians(spotLight.outerCutOffDegrees)));
    shaderProgram.SetUniform(uniformLight + ".color", spotLight.color);
    shaderProgram.SetUniform(uniformLight + ".ambientIntensity", spotLight.ambientIntensity);
    shaderProgram.SetUniform(uniformLight + ".diffuseIntensity", spotLight.diffuseIntensity);
    shaderProgram.SetUniform(uniformLight + ".specularIntensity", spotLight.specularIntensity);
    shaderProgram.SetUniform(uniformLight + ".quadratic", spotLight.quadratic);
    shaderProgram.SetUniform(uniformLight + ".linear", spotLight.linear);
    shaderProgram.SetUniform(uniformLight + ".constant", spotLight.constant);
}