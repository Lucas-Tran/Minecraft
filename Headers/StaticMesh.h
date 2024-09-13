#ifndef STATIC_MESH_H
#define STATIC_MESH_H

#include "BaseMesh.h"

#include "StaticVBO.h"
#include "StaticEBO.h"

class StaticMesh : public BaseMesh {
public:
    StaticMesh(const Vertex *vertices, unsigned int vertexArraySize, const unsigned int *elements, unsigned int elementArraySize);

    void Draw() override;
private:
    const Vertex *vertices;
    const unsigned int *elements;
    
    const unsigned int vertexCount;
    const unsigned int elementCount;

    StaticVBO VBO;
    StaticEBO EBO;
};

#endif