#ifndef VAO_H
#define VAO_H

class VAO {
public:
    VAO();

    ~VAO();

    void Bind();

    static void Unbind();

    static void SetVertexAttribute(unsigned int location, unsigned int size, unsigned int stride, unsigned int depth);


private:
    unsigned int ID;
};

#endif