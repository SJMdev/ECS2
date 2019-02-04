#version 460 core
layout (location = 0) in vec3 position;
layout (location = 1) in vec2 uv;
layout (location = 2) in vec3 color;

uniform vec4 material;

out vec3 interpolatedColor;
out vec2 texCoordinates;

void main()
{ 

    vec4 pos = vec4(position, 1);
    gl_Position = pos;

    interpolatedColor = color;

    texCoordinates = uv;
}