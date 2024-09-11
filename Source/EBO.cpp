#include "EBO.h"

#include <glad/glad.h>

EBO::EBO(std::vector<unsigned int> &elements) {
    glGenBuffers(1, &this->ID);
    this->Bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, elements.size() * sizeof(unsigned int), &elements[0], GL_STATIC_DRAW);
}

EBO::~EBO() {
    glDeleteBuffers(1, &this->ID);
}

void EBO::Bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ID);
}

void EBO::Unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}