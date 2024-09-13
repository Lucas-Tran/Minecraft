#ifndef STATIC_VBO_H
#define STATIC_VBO_H

#include "BaseVBO.h"

class StaticVBO : public BaseVBO {
public:
    StaticVBO(const Vertex *vertices, const unsigned int vertexArraySize);
};

#endif