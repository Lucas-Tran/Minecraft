#ifndef BASE_MESH_H
#define BASE_MESH_H

#include "Engine.h"
#include "VAO.h"

class BaseMesh {
public:
    virtual void Draw() = 0;

protected:
    VAO VAO;
};

#endif