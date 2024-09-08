#include "ShaderProgram.h"

#include "ShaderProgramBuilder.h"

#include <glm/gtc/type_ptr.hpp>

ShaderProgram::ShaderProgram(std::string shaderName) {
    this->ID = ShaderProgramBuilder::BuildShaderProgram(shaderName);
}

ShaderProgram::~ShaderProgram() {
    glDeleteProgram(this->ID);
}

void ShaderProgram::Use() {
    glUseProgram(this->ID);
}

void ShaderProgram::SetUniformInteger(const char* uniformName, int value) {
    unsigned int uniformLocation = glGetUniformLocation(this->ID, uniformName);
    glUniform1i(uniformLocation, value);
}

void ShaderProgram::SetUniformMatrix4(const char* uniformName, glm::mat4 value) {
    unsigned int uniformLocation = glGetUniformLocation(this->ID, uniformName);
    glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(value));
}