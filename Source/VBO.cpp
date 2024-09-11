#include "VBO.h"

#include <glad/glad.h>

VBO::VBO(std::vector<Vertex> &vertices) {
    glGenBuffers(1, &this->ID);
    this->Bind();
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);
}

VBO::~VBO() {
    glDeleteBuffers(1, &this->ID);
}

void VBO::Bind() {
    glBindBuffer(GL_ARRAY_BUFFER, this->ID);
}

void VBO::Unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}