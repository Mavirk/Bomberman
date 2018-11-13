#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h> // include glad to get all the required OpenGL headers
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
  

class Shader {
public:
    // the program ID
    unsigned int ID;
  
    // constructor reads and builds the shader
    Shader(const GLchar* vertexPath, const GLchar* fragmentPath);
    Shader();
    ~Shader();
    // use/activate the shader
    void use();
    // utility uniform functions
    void setBool(const std::string &name, bool value) const;  
    void setInt(const std::string &name, int value) const;   
    void setFloat(const std::string &name, float value) const;

    void    setVec2(const std::string &name, const glm::vec2 &value) const;
    void    setVec3(const std::string &name, const glm::vec3 &value) const;
    void    setVec4(const std::string &name, const glm::vec4 &value) const;  
    void    setMat2(const std::string &name, const glm::mat2 &mat) const;
    void    setMat3(const std::string &name, const glm::mat3 &mat) const;
    void    setMat4(const std::string &name, const glm::mat4 &mat) const;

    void    setVec2(const std::string &name,  float x, float y) const;
    void    setVec3(const std::string &name, float x, float y, float z) const;
    void    setVec4(const std::string &name, float x, float y, float z, float w) const;
};
  
#endif