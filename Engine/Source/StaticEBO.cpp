#include "StaticEBO.h"

StaticEBO::StaticEBO(const unsigned int *elements, const unsigned int elementArraySize) {
    glGenBuffers(1, &this->ID);
    this->Bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, elementArraySize, elements, GL_STATIC_DRAW);
}