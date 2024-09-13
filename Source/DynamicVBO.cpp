#include "DynamicVBO.h"

DynamicVBO::DynamicVBO() {
    glGenBuffers(1, &this->ID);
    this->Bind();
    glBufferData(GL_ARRAY_BUFFER, 0, nullptr, GL_DYNAMIC_DRAW);
}

void DynamicVBO::UploadData(std::vector<Vertex> &vertices) {
    this->Bind();
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_DYNAMIC_DRAW);
}