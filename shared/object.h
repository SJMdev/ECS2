#ifndef INCLUDED_OBJECT
#define INCLUDED_OBJECT
#include "texture.h"
#include "vertex.h"
#include "../matrix/mat4.h"
#include "rawdata.h"


struct Object
{
    //transformation
    Mat4 modelMatrix; //for MVP!
    Mat4 translationMatrix;
    Mat4 rotationMatrix;
    Mat4 scaleMatrix;
    //
    Mat3 normalTransformMatrix;

    //drawing
    Texture texture;
    std::vector<Vertex> interleaved_vertices; //x,y,z,u,v,r,g,b
    RawData rawData;
    
    //openGL texture;
    unsigned int TBO;
    
};





#endif