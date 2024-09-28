#ifndef BASE_EBO_H
#define BASE_EBO_H

#include "Engine.h"

class BaseEBO {
public:
    ~BaseEBO();

    void Bind();

    static void Unbind();


protected:
    unsigned int ID;
};

#endif