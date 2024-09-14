#include "Chunk.h"


const Vertex cubeVertices[] = {
    // Back Face
    {glm::vec3(-0.5f, -0.5f,  0.5f),        glm::vec2(0.0f, 0.0f),         glm::vec3( 0.0f,  0.0f,  1.0f)},
    {glm::vec3( 0.5f, -0.5f,  0.5f),        glm::vec2(1.0f, 0.0f),         glm::vec3( 0.0f,  0.0f,  1.0f)},
    {glm::vec3( 0.5f,  0.5f,  0.5f),        glm::vec2(1.0f, 1.0f),         glm::vec3( 0.0f,  0.0f,  1.0f)},
    {glm::vec3(-0.5f,  0.5f,  0.5f),        glm::vec2(0.0f, 1.0f),         glm::vec3( 0.0f,  0.0f,  1.0f)},


    // Left Face
    {glm::vec3(-0.5f, -0.5f, -0.5f),        glm::vec2(0.0f, 0.0f),         glm::vec3(-1.0f,  0.0f,  0.0f)},
    {glm::vec3(-0.5f, -0.5f,  0.5f),        glm::vec2(1.0f, 0.0f),         glm::vec3(-1.0f,  0.0f,  0.0f)},
    {glm::vec3(-0.5f,  0.5f,  0.5f),        glm::vec2(1.0f, 1.0f),         glm::vec3(-1.0f,  0.0f,  0.0f)},
    {glm::vec3(-0.5f,  0.5f, -0.5f),        glm::vec2(0.0f, 1.0f),         glm::vec3(-1.0f,  0.0f,  0.0f)},


    // Front Face
    {glm::vec3( 0.5f, -0.5f, -0.5f),        glm::vec2(0.0f, 0.0f),         glm::vec3( 0.0f,  0.0f, -1.0f)},
    {glm::vec3(-0.5f, -0.5f, -0.5f),        glm::vec2(1.0f, 0.0f),         glm::vec3( 0.0f,  0.0f, -1.0f)},
    {glm::vec3(-0.5f,  0.5f, -0.5f),        glm::vec2(1.0f, 1.0f),         glm::vec3( 0.0f,  0.0f, -1.0f)},
    {glm::vec3( 0.5f,  0.5f, -0.5f),        glm::vec2(0.0f, 1.0f),         glm::vec3( 0.0f,  0.0f, -1.0f)},


    // Right Face
    {glm::vec3( 0.5f, -0.5f,  0.5f),        glm::vec2(0.0f, 0.0f),         glm::vec3( 1.0f,  0.0f,  0.0f)},
    {glm::vec3( 0.5f, -0.5f, -0.5f),        glm::vec2(1.0f, 0.0f),         glm::vec3( 1.0f,  0.0f,  0.0f)},
    {glm::vec3( 0.5f,  0.5f, -0.5f),        glm::vec2(1.0f, 1.0f),         glm::vec3( 1.0f,  0.0f,  0.0f)},
    {glm::vec3( 0.5f,  0.5f,  0.5f),        glm::vec2(0.0f, 1.0f),         glm::vec3( 1.0f,  0.0f,  0.0f)},


    // Top Face
    {glm::vec3(-0.5f,  0.5f,  0.5f),        glm::vec2(0.0f, 0.0f),         glm::vec3( 0.0f,  1.0f,  0.0f)},
    {glm::vec3( 0.5f,  0.5f,  0.5f),        glm::vec2(1.0f, 0.0f),         glm::vec3( 0.0f,  1.0f,  0.0f)},
    {glm::vec3( 0.5f,  0.5f, -0.5f),        glm::vec2(1.0f, 1.0f),         glm::vec3( 0.0f,  1.0f,  0.0f)},
    {glm::vec3(-0.5f,  0.5f, -0.5f),        glm::vec2(0.0f, 1.0f),         glm::vec3( 0.0f,  1.0f,  0.0f)},


    // Bottom Face
    {glm::vec3( 0.5f,  -0.5f,  0.5f),       glm::vec2(0.0f, 0.0f),         glm::vec3( 0.0f, -1.0f,  0.0f)},
    {glm::vec3(-0.5f,  -0.5f,  0.5f),       glm::vec2(1.0f, 0.0f),         glm::vec3( 0.0f, -1.0f,  0.0f)},
    {glm::vec3(-0.5f,  -0.5f, -0.5f),       glm::vec2(1.0f, 1.0f),         glm::vec3( 0.0f, -1.0f,  0.0f)},
    {glm::vec3( 0.5f,  -0.5f, -0.5f),       glm::vec2(0.0f, 1.0f),         glm::vec3( 0.0f, -1.0f,  0.0f)}
};

const unsigned int faceElements[] = {
    0, 1, 2,
    0, 2, 3
};

Chunk::Chunk() {
    srand(4940);
    for (unsigned int x = 0; x < CHUNK_WIDTH; x++) {
        for (unsigned int z = 0; z < CHUNK_DEPTH; z++) {
            unsigned int height = rand() % 8;
            for (unsigned int y = 0; y < CHUNK_HEIGHT; y++) {
                this->SetBlockAt(x, y, z, (y > height) ? AIR : SOLID);
            }
        }
    }

    this->RegenerateChunk();
}

void Chunk::RegenerateChunk() {
    this->mesh.vertices.clear();
    this->mesh.elements.clear();

    for (unsigned int x = 0; x < CHUNK_WIDTH; x++) {
        for (unsigned int y = 0; y < CHUNK_WIDTH; y++) {
            for (unsigned int z = 0; z < CHUNK_WIDTH; z++) {
                if (GetBlockAt(x, y, z).solid) {
                    int faceNormals[] = {
                        0, 0, 1,
                        -1, 0, 0,
                        0, 0, -1,
                        1, 0, 0,
                        0, 1, 0,
                        0, -1, 0
                    };
                    
                    for (unsigned int faceNumber = 0; faceNumber < 6; faceNumber++) {
                        if (!GetBlockAt(x + faceNormals[(faceNumber * 3)], y + faceNormals[(faceNumber * 3) + 1], z + faceNormals[(faceNumber * 3) + 2]).solid) {
                            unsigned int vertexCount = this->mesh.vertices.size();
                            for (unsigned int i = 0; i < 6; i++) {
                                this->mesh.elements.push_back(faceElements[i] + vertexCount);
                            }

                            for (unsigned int i = 0; i < 4; i++) {
                                Vertex cubeVertex = cubeVertices[i + (faceNumber * 4)];
                                cubeVertex.position += glm::vec3(x, y, z);
                                this->mesh.vertices.push_back(cubeVertex);
                            }
                        }
                    }
                }
                
            }
        }
    }

    this->mesh.UpdateBuffers();
}

void Chunk::Draw() {
    this->mesh.Draw();
}

Block Chunk::GetBlockAt(unsigned int x, unsigned int y, unsigned int z) {
    if (x >= 0 && x < CHUNK_WIDTH && y >= 0 && y < CHUNK_HEIGHT && z >= 0 && z < CHUNK_WIDTH) {
        return blockData[this->blockGrid[x][y][z]];
    }
    return blockData[AIR];
}

void Chunk::SetBlockAt(unsigned int x, unsigned int y, unsigned int z, unsigned int ID) {
    this->blockGrid[x][y][z] = ID;
}