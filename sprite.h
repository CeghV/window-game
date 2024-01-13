#ifndef SPRITE_H
#define SPRITE_H
#include "glad/glad.h"
#include "stb_image.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
class Sprite    {
    public:
        unsigned int texture;
        glm::vec2 position;
        glm::vec2 scale;
        float rotation;
        Sprite()    {
            return;
        };
        Sprite(const char *filename,GLuint colorformat)    {
            glGenTextures(1,&texture);
            glBindTexture(GL_TEXTURE_2D,texture);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
            int width,height,nrChannels;
            stbi_set_flip_vertically_on_load(true);
            unsigned char *data=stbi_load(filename,&width,&height,&nrChannels,0);
            if(data)    {
                glTexImage2D(GL_TEXTURE_2D,0,colorformat,width,height,0,colorformat,GL_UNSIGNED_BYTE,data);
                glGenerateMipmap(GL_TEXTURE_2D);
            }else   {
                std::cout<<"unable to load texture\n";
            }
            stbi_image_free(data);
        };
};
#endif