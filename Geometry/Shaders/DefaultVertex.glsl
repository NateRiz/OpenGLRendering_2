#version 460

layout (location = 0) in vec3 aPos; // the position variable has attribute position 0

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

out vec4 vertexColor;

void main()
{
    // note that we read the multiplication from right to left
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    //gl_Color = vec4(1.0, 0.0, 0.2, 1.0);
    vertexColor = vec4(1.0, 0.0, 0.2, 1.0);
}