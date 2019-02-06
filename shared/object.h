#ifndef INCLUDED_OBJECT
#define INCLUDED_OBJECT
#include "texture.h"
#include "vecf.h"
#include "vertex.h"
#include "../matrix/mat4.h"
#include "rawdata.h"


struct Object
{
    //transformation
    Mat4 transformationMatrix;
    Mat4 locationMatrix;
    Mat4 rotationMatrix;
    Mat4 scaleMatrix;

    //drawing
    Texture texture;
    std::vector<Vertex> interleaved_vertices; //x,y,z,u,v,r,g,b
    RawData rawData;
};





#endif