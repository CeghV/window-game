#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
bool windowKill=false;
void pollForKeys(GLFWwindow *window)  {
    if(glfwGetKey(window,GLFW_KEY_ESCAPE)==GLFW_PRESS)  {
        windowKill=true;
    }
};
int main()  {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER,1);
    glfwWindowHint(GLFW_FLOATING,1);
    glfwWindowHint(GLFW_DECORATED,false);
    glfwWindowHint(GLFW_RESIZABLE,false);
    GLFWwindow *window=     glfwCreateWindow(100,100,"window game",NULL,NULL);
    GLFWwindow *testWindow= glfwCreateWindow(100,100,"testingtest",NULL,window);
    if(window==NULL)    {
        std::cout<<"failed to initialize a window\n";
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwMakeContextCurrent(testWindow);
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout<<"failed to initialize glad\n";
        return -1;
    }
    glViewport(0,0,100,100);
    while(!windowKill)  {
        pollForKeys(window);
        pollForKeys(testWindow);
        glfwMakeContextCurrent(window);
        glClearColor(1.0f,0.0f,0.0f,0.1f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwMakeContextCurrent(testWindow);
        glClearColor(0.0f,0.0f,1.0f,0.1f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        float time=glfwGetTime()*10.0f;
        glfwSetWindowPos(window,(sin(time)*100)+200,(cos(time)*100)+200);
        glfwSetWindowPos(testWindow,(cos(time)*100)+200,(sin(time)*100)+200);

        glfwSwapBuffers(testWindow);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
};