
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
  Shader(const char*, const char*);
  void use();

private:
  Shader();

};

#endif