#version 460

out vec4 FragColor;

in vec4 vertexColor; // the input variable from the vertex shader (same name and same type)

void main()
{
    FragColor = vec4(0.4, vertexColor.y/32, 0.05, 1.0);
}