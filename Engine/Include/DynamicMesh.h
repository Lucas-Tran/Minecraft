#ifndef DYNAMIC_MESH_H
#define DYNAMIC_MESH_H

#include "BaseMesh.h"
#include "DynamicVBO.h"
#include "DynamicEBO.h"


class DynamicMesh : public BaseMesh {
public:
    std::vector<Vertex> vertices;
    std::vector<unsigned int> elements;
    
    DynamicMesh();

    void Draw() override;

    void UpdateBuffers();
private:

    DynamicVBO VBO;
    DynamicEBO EBO;
};

#endif