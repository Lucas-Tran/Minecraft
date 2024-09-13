#include "StaticVBO.h"

StaticVBO::StaticVBO(const Vertex *vertices, const unsigned int vertexArraySize) {
    glGenBuffers(1, &this->ID);
    this->Bind();
    glBufferData(GL_ARRAY_BUFFER, vertexArraySize, vertices, GL_STATIC_DRAW);
}