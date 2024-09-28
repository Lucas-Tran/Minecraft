#ifndef VAO_H
#define VAO_H

#include "Engine.h"

class VAO {
public:
    VAO();

    ~VAO();

    void Bind();

    static void Unbind();

    static void SetAttributeFormat();



private:
    unsigned int ID;
};

#endif