#include "ShaderProgram.h"

#include "ShaderProgramBuilder.h"

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