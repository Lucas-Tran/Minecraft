#ifndef VBO_H
#define VBO_H

class VBO {
public:
    VBO(float *vertices, unsigned int size);

    ~VBO();

    void Bind();

    static void Unbind();


private:
    unsigned int ID;
};

#endif