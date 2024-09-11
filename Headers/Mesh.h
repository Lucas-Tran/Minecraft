#ifndef MESH_H
#define MESH_H

#include "Engine.h"
#include "VBO.h"
#include "VAO.h"
#include "EBO.h"

class Mesh {
public:
    Mesh(std::vector<Vertex> &vertices, std::vector<unsigned int> &elements);

    void Draw();

private:
    std::vector<Vertex> vertices;
    std::vector<unsigned int> elements;

    VBO VBO;
    VAO VAO;
    EBO EBO;
};

#endif