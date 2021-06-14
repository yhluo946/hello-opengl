
#ifndef _SHADER_H_
#define _SHADER_H_

#include <iostream>
#include <math.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Shader
{
public: 
  uint Id;
  Shader(std::string, std::string);
  void use();
  void setFloat(const std::string&, float);

private:
  Shader();

};

#endif