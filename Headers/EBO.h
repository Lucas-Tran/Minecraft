#ifndef EBO_H
#define EBO_H

class EBO {
public:
    EBO(unsigned int *elements, unsigned int size);

    ~EBO();

    void Bind();

    static void Unbind();


private:
    unsigned int ID;
};

#endif