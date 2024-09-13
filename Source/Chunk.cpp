#include "Chunk.h"


const Vertex cubeVertices[] = {
    {glm::vec3(-0.5f, -0.5f,  0.5f),        glm::vec2(0.0f, 0.0f),         glm::vec3( 0.0f,  0.0f,  1.0f)},
    {glm::vec3( 0.5f, -0.5f,  0.5f),        glm::vec2(1.0f, 0.0f),         glm::vec3( 0.0f,  0.0f,  1.0f)},
    {glm::vec3( 0.5f,  0.5f,  0.5f),        glm::vec2(1.0f, 1.0f),         glm::vec3( 0.0f,  0.0f,  1.0f)},
    {glm::vec3(-0.5f,  0.5f,  0.5f),        glm::vec2(0.0f, 1.0f),         glm::vec3( 0.0f,  0.0f,  1.0f)},


    {glm::vec3(-0.5f, -0.5f, -0.5f),        glm::vec2(0.0f, 0.0f),         glm::vec3(-1.0f,  0.0f,  0.0f)},
    {glm::vec3(-0.5f, -0.5f,  0.5f),        glm::vec2(1.0f, 0.0f),         glm::vec3(-1.0f,  0.0f,  0.0f)},
    {glm::vec3(-0.5f,  0.5f,  0.5f),        glm::vec2(1.0f, 1.0f),         glm::vec3(-1.0f,  0.0f,  0.0f)},
    {glm::vec3(-0.5f,  0.5f, -0.5f),        glm::vec2(0.0f, 1.0f),         glm::vec3(-1.0f,  0.0f,  0.0f)},


    {glm::vec3( 0.5f, -0.5f, -0.5f),        glm::vec2(0.0f, 0.0f),         glm::vec3( 0.0f,  0.0f, -1.0f)},
    {glm::vec3(-0.5f, -0.5f, -0.5f),        glm::vec2(1.0f, 0.0f),         glm::vec3( 0.0f,  0.0f, -1.0f)},
    {glm::vec3(-0.5f,  0.5f, -0.5f),        glm::vec2(1.0f, 1.0f),         glm::vec3( 0.0f,  0.0f, -1.0f)},
    {glm::vec3( 0.5f,  0.5f, -0.5f),        glm::vec2(0.0f, 1.0f),         glm::vec3( 0.0f,  0.0f, -1.0f)},


    {glm::vec3( 0.5f, -0.5f,  0.5f),        glm::vec2(0.0f, 0.0f),         glm::vec3( 1.0f,  0.0f,  0.0f)},
    {glm::vec3( 0.5f, -0.5f, -0.5f),        glm::vec2(1.0f, 0.0f),         glm::vec3( 1.0f,  0.0f,  0.0f)},
    {glm::vec3( 0.5f,  0.5f, -0.5f),        glm::vec2(1.0f, 1.0f),         glm::vec3( 1.0f,  0.0f,  0.0f)},
    {glm::vec3( 0.5f,  0.5f,  0.5f),        glm::vec2(0.0f, 1.0f),         glm::vec3( 1.0f,  0.0f,  0.0f)},


    {glm::vec3(-0.5f,  0.5f,  0.5f),        glm::vec2(0.0f, 0.0f),         glm::vec3( 0.0f,  1.0f,  0.0f)},
    {glm::vec3( 0.5f,  0.5f,  0.5f),        glm::vec2(1.0f, 0.0f),         glm::vec3( 0.0f,  1.0f,  0.0f)},
    {glm::vec3( 0.5f,  0.5f, -0.5f),        glm::vec2(1.0f, 1.0f),         glm::vec3( 0.0f,  1.0f,  0.0f)},
    {glm::vec3(-0.5f,  0.5f, -0.5f),        glm::vec2(0.0f, 1.0f),         glm::vec3( 0.0f,  1.0f,  0.0f)},


    {glm::vec3( 0.5f,  -0.5f,  0.5f),       glm::vec2(0.0f, 0.0f),         glm::vec3( 0.0f, -1.0f,  0.0f)},
    {glm::vec3(-0.5f,  -0.5f,  0.5f),       glm::vec2(1.0f, 0.0f),         glm::vec3( 0.0f, -1.0f,  0.0f)},
    {glm::vec3(-0.5f,  -0.5f, -0.5f),       glm::vec2(1.0f, 1.0f),         glm::vec3( 0.0f, -1.0f,  0.0f)},
    {glm::vec3( 0.5f,  -0.5f, -0.5f),       glm::vec2(0.0f, 1.0f),         glm::vec3( 0.0f, -1.0f,  0.0f)}
};

const unsigned int cubeElements[] = {
    0, 1, 2,
    0, 2, 3,


    4, 5, 6,
    4, 6, 7,


    8, 9, 10,
    8, 10, 11,


    12, 13, 14,
    12, 14, 15,


    16, 17, 18,
    16, 18, 19,


    20, 21, 22,
    20, 22, 23
};


Chunk::Chunk() {
    this->RegenerateChunk();
}

void Chunk::RegenerateChunk() {
    this->mesh.vertices.clear();
    this->mesh.elements.clear();

    for (unsigned int x = 0; x < CHUNK_WIDTH; x++) {
        for (unsigned int y = 0; y < CHUNK_WIDTH; y++) {
            for (unsigned int z = 0; z < CHUNK_WIDTH; z++) {

                unsigned int vertexCount = this->mesh.vertices.size();
                for (unsigned int i = 0; i < 36; i++) {
                    this->mesh.elements.push_back(cubeElements[i] + vertexCount);
                }

                for (unsigned int i = 0; i < 24; i++) {
                    Vertex cubeVertex = cubeVertices[i];
                    cubeVertex.position += glm::vec3(x, y, z);
                    this->mesh.vertices.push_back(cubeVertex);
                }
                
            }
        }
    }

    this->mesh.UpdateBuffers();
}

void Chunk::Draw() {
    this->mesh.Draw();
}