#version 330 core
out vec4 FragColor;
// uniform vec4 inputColor;
in vec4 color;
void main(){
  FragColor = color;
}