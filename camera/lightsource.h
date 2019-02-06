#ifndef INCLUDED_LIGHTSOURCE_
#define INCLUDED_LIGHTSOURCE_
#include "../shared/vecf.h"

//@Todo: this uses the old Vec3f.
struct LightSource 
{
    Vec3f color; // r, g, b.
    Vec3f position;   
};



#endif