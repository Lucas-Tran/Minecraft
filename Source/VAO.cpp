#include "VAO.h"

#include <glad/glad.h>
#include <cstddef>


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

void VAO::SetAttributeFormat() {
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, position));

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, textureCoordinates));

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, normal));
}