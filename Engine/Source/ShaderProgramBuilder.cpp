#include "ShaderProgramBuilder.h"

#include "FileReader.h"

std::string ShaderProgramBuilder::errorLog;

unsigned int ShaderProgramBuilder::CompileShader(std::string source, GLenum type) {
    const char *sourceCStr = source.c_str();
    unsigned int shader = glCreateShader(type);
    glShaderSource(shader, 1, &sourceCStr, nullptr);
    glCompileShader(shader);

    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        std::string shaderName;
        if (type == GL_VERTEX_SHADER) {
            shaderName = "VERTEX";
        } else if (type == GL_FRAGMENT_SHADER) {
            shaderName = "FRAGMENT";
        }
        errorLog = "ERROR::SHADER::" + shaderName + "::COMPILATION::FAILED\n";
        errorLog += infoLog;
        return 0;
    }

    return shader;
}

unsigned int ShaderProgramBuilder::BuildShaderProgram(std::string shaderName) {
    unsigned int vertexShader = CompileShader(ReadFile("Shaders/" + shaderName + ".VS"), GL_VERTEX_SHADER);
    unsigned int fragmentShader = CompileShader(ReadFile("Shaders/" + shaderName + ".FS"), GL_FRAGMENT_SHADER);
    if (fragmentShader == 0 || vertexShader == 0) {
        return 0;
    }

    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    int success;
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetProgramInfoLog(shaderProgram, 512, nullptr, infoLog);
        errorLog = "ERROR::SHADER::PROGRAM::LINKING::FAILED\n";
        errorLog += infoLog;
        return 0;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    return shaderProgram;
}