#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
uniform float offsetX;
out vec4 color;
void main() {
  gl_Position = vec4(aPos.x + offsetX, aPos.y, aPos.z, 1.0);
  // color = vec4(aColor, 1.0f);
  color = vec4(aPos, 1.0f);
}