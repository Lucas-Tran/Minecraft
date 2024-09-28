#ifndef STATIC_EBO_H
#define STATIC_EBO_H

#include "BaseEBO.h"

class StaticEBO : public BaseEBO {
public:
    StaticEBO(const unsigned int *elements, const unsigned int elementArraySize);
};

#endif