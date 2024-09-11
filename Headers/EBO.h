#ifndef EBO_H
#define EBO_H

#include "Engine.h"

class EBO {
public:
    EBO(std::vector<unsigned int> &elements);

    ~EBO();

    void Bind();

    static void Unbind();


private:
    unsigned int ID;
};

#endif