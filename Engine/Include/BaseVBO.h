#ifndef BASE_VBO_H
#define BASE_VBO_H

#include "Engine.h"

class BaseVBO {
public:
    ~BaseVBO();

    void Bind();

    static void Unbind();

protected:
    unsigned int ID;
};

#endif