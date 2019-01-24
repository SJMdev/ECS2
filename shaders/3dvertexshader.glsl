#version 460 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec3 color;

out vec3 interpolatedColor;

void main()
{ 
    interpolatedColor = color;
    vec4 pos = vec4(position, 1);
    gl_Position = pos;
}