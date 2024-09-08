#include "ShaderProgramBuilder.h"

#include "FileReader.h"

unsigned int ShaderProgramBuilder::CompileShader(std::string source, GLenum type) {
    const char *sourceCStr = source.c_str();
    unsigned int shader = glCreateShader(type);
    glShaderSource(shader, 1, &sourceCStr, nullptr);
    glCompileShader(shader);

    return shader;
}

unsigned int ShaderProgramBuilder::BuildShaderProgram(std::string shaderName) {
    unsigned int vertexShader = CompileShader(ReadFile("Shaders/" + shaderName + ".VS"), GL_VERTEX_SHADER);
    unsigned int fragmentShader = CompileShader(ReadFile("Shaders/" + shaderName + ".FS"), GL_FRAGMENT_SHADER);

    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    return shaderProgram;
}