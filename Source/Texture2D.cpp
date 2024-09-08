#include "Texture2D.h"

#include "stb_image.h"


Texture2D::Texture2D(std::string path, GLenum S_WRAPPING, GLenum T_WRAPPING, GLenum MIN_FILETERING, GLenum MAG_FILTERING) {
    glGenTextures(1, &this->ID);
    glBindTexture(GL_TEXTURE_2D, this->ID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, S_WRAPPING);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, T_WRAPPING);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, MIN_FILETERING);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, MAG_FILTERING);
    
    int width, height, channelCount;
    stbi_set_flip_vertically_on_load(true);
    std::string fullPath = "Resources/Textures/" + path;
    unsigned char *imageData = stbi_load(fullPath.c_str(), &width, &height, &channelCount, 0);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, imageData);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(imageData);
    glBindTexture(GL_TEXTURE_2D, 0);
}

Texture2D::~Texture2D() {
    glDeleteTextures(GL_TEXTURE_2D, &this->ID);
}

void Texture2D::BindWithSlot(GLenum slot) {
    glActiveTexture(slot);
    glBindTexture(GL_TEXTURE_2D, this->ID);
}