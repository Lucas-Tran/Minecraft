#ifndef SHADER_PROGRAM_H
#define SHADER_PROGRAM_H

#include <string>

class ShaderProgram {
public:
    ShaderProgram(std::string shaderName);

    ~ShaderProgram();

    void Use();

    void SetUniformInteger(const char* uniformName, int value);
    

private:
    unsigned int ID;
};

#endif