#ifndef TEXTURE_2D_H
#define TEXTURE_2D_H

#include <string>
#include <glad/glad.h>

class Texture2D {
public:
    Texture2D(std::string path, GLenum S_WRAPPING, GLenum T_WRAPPING, GLenum MIN_FILETERING, GLenum MAG_FILTERING);

    ~Texture2D();

    void BindWithSlot(GLenum slot);

private:
    unsigned int ID;
};

#endif