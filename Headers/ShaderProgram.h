#ifndef SHADER_PROGRAM_H
#define SHADER_PROGRAM_H

#include <string>
#include <glm/glm.hpp>
#include "ShaderProgramBuilder.h"

class ShaderProgram {
public:
    ShaderProgram(std::string shaderName);

    ~ShaderProgram();

    bool GetSuccess();

    void Use();

    void SetUniform(const char* uniformName, int value);

    void SetUniform(const char* uniformName, glm::mat4 value);

    void SetUniform(const char* uniformName, glm::vec3 value);
    

private:
    unsigned int ID;
};

#endif