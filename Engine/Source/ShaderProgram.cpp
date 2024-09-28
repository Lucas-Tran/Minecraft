#include "ShaderProgram.h"

#include <glm/gtc/type_ptr.hpp>

ShaderProgram::ShaderProgram(std::string shaderName) {
    this->ID = ShaderProgramBuilder::BuildShaderProgram(shaderName);
}

ShaderProgram::~ShaderProgram() {
    glDeleteProgram(this->ID);
}

bool ShaderProgram::GetSuccess() {
    return this->ID != 0;
}

void ShaderProgram::Use() {
    glUseProgram(this->ID);
}

void ShaderProgram::SetUniform(std::string uniformName, int value) {
    unsigned int uniformLocation = glGetUniformLocation(this->ID, uniformName.c_str());
    glUniform1i(uniformLocation, value);
}

void ShaderProgram::SetUniform(std::string uniformName, float value) {
    unsigned int uniformLocation = glGetUniformLocation(this->ID, uniformName.c_str());
    glUniform1f(uniformLocation, value);
}

void ShaderProgram::SetUniform(std::string uniformName, glm::mat4 value) {
    unsigned int uniformLocation = glGetUniformLocation(this->ID, uniformName.c_str());
    glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(value));
}

void ShaderProgram::SetUniform(std::string uniformName, glm::vec3 value) {
    unsigned int uniformLocation = glGetUniformLocation(this->ID, uniformName.c_str());
    glUniform3fv(uniformLocation, 1, glm::value_ptr(value));
}