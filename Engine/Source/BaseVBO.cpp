#include "BaseVBO.h"

#include <glad/glad.h>

BaseVBO::~BaseVBO() {
    glDeleteBuffers(1, &this->ID);
}

void BaseVBO::Bind() {
    glBindBuffer(GL_ARRAY_BUFFER, this->ID);
}

void BaseVBO::Unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}