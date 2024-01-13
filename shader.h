#ifndef SHADER_H
#define SHADER_H
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"
class Shader {
    public:
        unsigned int ID;
        Shader()    {
            return;
        };
        Shader(const char *vertexPath,const char *fragmentPath) {
            std::string vertexCode;
            std::string fragmentCode;
            std::ifstream vShaderFile;
            std::ifstream fShaderFile;
            vShaderFile.exceptions(std::ifstream::failbit|std::ifstream::badbit);
            fShaderFile.exceptions(std::ifstream::failbit|std::ifstream::badbit);
            try {
                vShaderFile.open(vertexPath);
                fShaderFile.open(fragmentPath);
                std::stringstream vShaderStream,fShaderStream;
                vShaderStream<<vShaderFile.rdbuf();
                fShaderStream<<fShaderFile.rdbuf();
                vShaderFile.close();
                fShaderFile.close();
                vertexCode=vShaderStream.str();
                fragmentCode=fShaderStream.str();
            }catch(std::ifstream::failure e)    {
                std::cout<<"unable to read shader files\n";
            }
            const char *vShaderCode=vertexCode.c_str();
            const char *fShaderCode=fragmentCode.c_str();
            unsigned int vertex,fragment;
            int success;
            char infoLog[512];
            vertex=glCreateShader(GL_VERTEX_SHADER);
            glShaderSource(vertex,1,&vShaderCode,NULL);
            glCompileShader(vertex);
            glGetShaderiv(vertex,GL_COMPILE_STATUS,&success);
            if(!success)    {
                glGetShaderInfoLog(vertex,512,NULL,infoLog);
                std::cout<<"unable to compile the vertex shader\n"<<infoLog<<"\n";
            }
            fragment=glCreateShader(GL_FRAGMENT_SHADER);
            glShaderSource(fragment,1,&fShaderCode,NULL);
            glCompileShader(fragment);
            glGetShaderiv(fragment,GL_COMPILE_STATUS,&success);
            if(!success)    {
                glGetShaderInfoLog(fragment,512,NULL,infoLog);
                std::cout<<"unable to compile the fragment shader\n"<<infoLog<<"\n";
            }
            ID=glCreateProgram();
            glAttachShader(ID,vertex);
            glAttachShader(ID,fragment);
            glLinkProgram(ID);
            glGetProgramiv(ID,GL_LINK_STATUS,&success);
            if(!success)    {
                glGetProgramInfoLog(ID,512,NULL,infoLog);
                std::cout<<"unable to link the shaders\n"<<infoLog<<"\n";
            }
            glDeleteShader(vertex);
            glDeleteShader(fragment);
        };
        void use()  {
            glUseProgram(ID);
        };
        void setBool(const std::string &name,bool value) const  {
            glUniform1i(glGetUniformLocation(ID,name.c_str()),(int)value);
        };
        void setInt(const std::string &name,int value) const    {
            glUniform1i(glGetUniformLocation(ID,name.c_str()),value);
        };
        void setFloat(const std::string &name,float value) const    {
            glUniform1f(glGetUniformLocation(ID,name.c_str()),value);
        };
        void setMat4(const std::string &name,const glm::mat4 &mat) const{
            glUniformMatrix4fv(glGetUniformLocation(ID,name.c_str()),1,GL_FALSE,&mat[0][0]);
        };
        void setVec3(const std::string &name,const glm::vec3 &vec) const{
            glUniform3fv(glGetUniformLocation(ID,name.c_str()),1,&vec[0]);
        };
        void setVec2(const std::string &name,const glm::vec2 &vec) const{
            glUniform2fv(glGetUniformLocation(ID,name.c_str()),1,&vec[0]);
        };
};
#endif