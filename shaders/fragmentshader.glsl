#version 460 core
        
in vec3 interpolatedColor;
out vec4 rgba;
        
void main()
{
    rgba = vec4(interpolatedColor, 1);
}