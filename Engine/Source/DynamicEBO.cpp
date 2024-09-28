#include "DynamicEBO.h"

DynamicEBO::DynamicEBO() {
    glGenBuffers(1, &this->ID);
    this->Bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, 0, nullptr, GL_DYNAMIC_DRAW);
}

void DynamicEBO::UpdateData(std::vector<unsigned int> &elements) {
    this->Bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, elements.size() * sizeof(unsigned int), &elements[0], GL_DYNAMIC_DRAW);
}