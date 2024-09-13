#include "BaseEBO.h"

#include <glad/glad.h>

BaseEBO::~BaseEBO() {
    glDeleteBuffers(1, &this->ID);
}

void BaseEBO::Bind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ID);
}

void BaseEBO::Unbind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}