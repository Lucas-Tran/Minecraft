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

void ShaderProgram::SetUniform(const char* uniformName, int value) {
    unsigned int uniformLocation = glGetUniformLocation(this->ID, uniformName);
    glUniform1i(uniformLocation, value);
}

void ShaderProgram::SetUniform(const char* uniformName, float value) {
    unsigned int uniformLocation = glGetUniformLocation(this->ID, uniformName);
    glUniform1f(uniformLocation, value);
}

void ShaderProgram::SetUniform(const char* uniformName, glm::mat4 value) {
    unsigned int uniformLocation = glGetUniformLocation(this->ID, uniformName);
    glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(value));
}

void ShaderProgram::SetUniform(const char* uniformName, glm::vec3 value) {
    unsigned int uniformLocation = glGetUniformLocation(this->ID, uniformName);
    glUniform3fv(uniformLocation, 1, glm::value_ptr(value));
}