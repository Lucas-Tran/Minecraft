#ifndef SHADER_PROGRAM_H
#define SHADER_PROGRAM_H

#include <string>
#include <glm/glm.hpp>

class ShaderProgram {
public:
    ShaderProgram(std::string shaderName);

    ~ShaderProgram();

    void Use();

    void SetUniformInteger(const char* uniformName, int value);

    void SetUniformMatrix4(const char* uniformName, glm::mat4 value);
    

private:
    unsigned int ID;
};

#endif