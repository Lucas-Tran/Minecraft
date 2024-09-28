#ifndef DYNAMIC_VBO
#define DYNAMIC_VBO

#include "BaseVBO.h"

class DynamicVBO : public BaseVBO {
public:
    DynamicVBO();

    void UploadData(std::vector<Vertex> &vertices);
};

#endif