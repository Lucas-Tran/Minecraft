#ifndef CHUNK_H
#define CHUNK_H

#include "DynamicMesh.h"

#define CHUNK_WIDTH 16
#define CHUNK_HEIGHT 16
#define CHUNK_DEPTH 16

#include "BlockData.h"

class Chunk {
public:
    Chunk();

    void RegenerateChunk();

    void Draw();

    Block GetBlockAt(unsigned int x, unsigned int y, unsigned int z);

    void SetBlockAt(unsigned int x, unsigned int y, unsigned int z, unsigned int ID);
    
private:
    DynamicMesh mesh;
    unsigned char blockGrid[CHUNK_WIDTH][CHUNK_HEIGHT][CHUNK_DEPTH];
};

#endif