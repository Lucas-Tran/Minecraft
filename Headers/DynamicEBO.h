#ifndef DYNAMIC_EBO_H
#define DYNAMIC_EBO_H

#include "BaseEBO.h"

class DynamicEBO : public BaseEBO {
public:
    DynamicEBO();
    void UpdateData(std::vector<unsigned int> &elements);
};

#endif