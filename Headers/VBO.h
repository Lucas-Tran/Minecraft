#ifndef VBO_H
#define VBO_H

#include "Engine.h"

class VBO {
public:
    VBO(std::vector<Vertex> &vertices);

    ~VBO();

    void Bind();

    static void Unbind();


private:
    unsigned int ID;
};

#endif