#include "StaticMesh.h"

StaticMesh::StaticMesh(const Vertex *vertices, unsigned int vertexArraySize, const unsigned int *elements, unsigned int elementArraySize): vertices(vertices), elements(elements), VBO(vertices, vertexArraySize), EBO(elements, elementArraySize), vertexCount(vertexArraySize / sizeof(Vertex)), elementCount(elementArraySize / sizeof(unsigned int)) {
    VAO::SetAttributeFormat();
    VAO::Unbind();
    StaticVBO::Unbind();
    StaticEBO::Unbind();
}

void StaticMesh::Draw() {
    this->VAO.Bind();
    glDrawElements(GL_TRIANGLES, this->elementCount, GL_UNSIGNED_INT, 0);
    VAO::Unbind();
}