#include <iostream>
#include <math.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <fstream>
#include <sstream>
#include "../include/shader.hpp"

Shader::Shader(const char* vertPath, const char* fragPath) {
  std::string vertCode, fragCode;

  std::ifstream vertFile, fragFile;
  try {
    vertFile.open(vertPath);
    fragFile.open(fragPath);
    std::stringstream vertStream, fragStream;
    vertStream << vertFile.rdbuf();
    fragStream << fragFile.rdbuf();
    vertFile.close();
    fragFile.close();
    vertCode = vertStream.str();
    fragCode = fragStream.str();
  } catch(std::ifstream::failure e) {
    std::cout << "Failed to read file" << std::endl;
  }
  const char *vertCharCode = vertCode.c_str();
  const char *fragCharCode = fragCode.c_str();

  uint vertShader, fragShader;
  vertShader = glCreateShader(GL_VERTEX_SHADER);
  fragShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(vertShader, 1, &vertCharCode, NULL);
  glShaderSource(fragShader, 1, &fragCharCode, NULL);
  glCompileShader(vertShader);
  glCompileShader(fragShader);

  Id = glCreateProgram();
  glAttachShader(Id, vertShader);
  glAttachShader(Id, fragShader);
  glLinkProgram(Id);
  glDeleteShader(vertShader);
  glDeleteShader(fragShader);
}

void Shader::use() {
  glUseProgram(Id);
}