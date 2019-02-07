#version 330 core

// Define constants
#define M_PI 3.141593

// Specify the input locations of attributes
layout (location = 0) in vec3 vertCoordinates_in;
layout (location = 1) in vec2 texCoordinates_in;
layout (location = 2) in vec3 vertNormal_in;

// Specify the Uniforms of the vertex shader
// uniform mat4 modelTransform; for example

uniform mat4 modelMatrix;
uniform mat4 modelProjection;
uniform mat4 viewMatrix;
uniform mat3 normalTransform;



uniform vec4 lightPosition;
uniform vec3 lightColor;
uniform vec4 material;      // w = ka, x = kd, y = ks, z = n


// Specify the output of the vertex stage
out vec3 vertColor;
out vec2 texCoordinates;

void main()
{
    vec4 worldPosVertex = modelMatrix * vec4(vertCoordinates_in, 1.0); // MV
    gl_Position = modelProjection * viewMatrix * worldPosVertex;                    // MVP


    vec3 worldPosLight = lightPosition.xyz; // modelMatrix *


    vec3 N = normalize(normalTransform * vertNormal_in);
    vec3 L = normalize(worldPosLight.xyz - worldPosVertex.xyz);
    vec3 R = normalize(reflect(L, N));

    vec3 V = normalize(worldPosVertex.xyz - vec3(0));

    vec3 matColor = vec3(0.82, 0.82, 0.82);

    vec3 i_A =  matColor * material.x;
    vec3 i_D = max(0, dot(N, L)) * matColor * material.y;
    vec3 i_S = pow(max(0, dot(R, V)), material.w) * lightColor * material.z;

    vertColor = i_A + i_D + i_S;
    texCoordinates = texCoordinates_in;
}