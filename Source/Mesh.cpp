#include "Mesh.h"

Mesh::Mesh(std::vector<Vertex> &vertices, std::vector<unsigned int> &elements): vertices(vertices), elements(elements), VAO(), VBO(vertices), EBO(elements) {
    VAO::SetAttributeFormat();
    VAO::Unbind();
}

void Mesh::Draw() {
    this->VAO.Bind();
    glDrawElements(GL_TRIANGLES, this->elements.size(), GL_UNSIGNED_INT, 0);
    VAO::Unbind();
}