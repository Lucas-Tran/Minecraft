#ifndef CHUNK_H
#define CHUNK_H

#include "DynamicMesh.h"

#define CHUNK_WIDTH 16
#define CHUNK_HEIGHT 16
#define CHUNK_DEPTH 16

class Chunk {
public:
    Chunk();

    void RegenerateChunk();

    void Draw();
private:
    DynamicMesh mesh;
};

#endif