#ifndef RENDERER_H
#define RENDERER_H
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "sprite.h"
#include "shader.h"
float square[]={
    0.0f,1.0f,1.0f,0.0f,
    1.0f,0.0f,1.0f,0.0f,
    0.0f,0.0f,1.0f,0.0f,
    0.0f,1.0f,1.0f,0.0f,
    1.0f,1.0f,1.0f,0.0f,
    1.0f,0.0f,1.0f,0.0f
};
class Renderer  {
    public:
        unsigned int VBO,VAO;
        Renderer(Shader *shader)  {
            return;
        };
        void DrawSprite(Sprite drawing)    {
            return;
        };
};
#endif