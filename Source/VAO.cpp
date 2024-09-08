#include "VAO.h"

#include <glad/glad.h>


VAO::VAO() {
    glGenVertexArrays(1, &this->ID);
    this->Bind();
}

VAO::~VAO() {
    glDeleteVertexArrays(1, &this->ID);
}

void VAO::Bind() {
    glBindVertexArray(this->ID);
}

void VAO::Unbind() {
    glBindVertexArray(0);
}

void VAO::SetVertexAttribute(unsigned int location, unsigned int size, unsigned int stride, unsigned int depth) {
    glEnableVertexAttribArray(location);
    glVertexAttribPointer(location, size, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void *)(depth * sizeof(float)));
}