#ifndef SHADER_PROGRAM_BUILDER_H
#define SHADER_PROGRAM_BUILDER_H

#include <string>
#include <glad/glad.h>

namespace ShaderProgramBuilder {
    unsigned int CompileShader(std::string source, GLenum type);

    unsigned int BuildShaderProgram(std::string shaderName);
}

#endif