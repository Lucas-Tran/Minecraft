#include "DynamicMesh.h"

DynamicMesh::DynamicMesh() {
    VAO::SetAttributeFormat();
    VAO::Unbind();
    DynamicVBO::Unbind();
    DynamicEBO::Unbind();
}

void DynamicMesh::Draw() {
    this->VAO.Bind();
    glDrawElements(GL_TRIANGLES, this->elements.size(), GL_UNSIGNED_INT, 0);
    VAO::Unbind();
}

void DynamicMesh::UpdateBuffers() {
    VAO.Bind();
    VBO.UploadData(vertices);
    EBO.UpdateData(elements);
    VAO::Unbind();
}