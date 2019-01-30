#ifndef _INCLUDED_XFORM_STATE_
#define _INCLUDED_XFORM_STATE_
#include "vecf.h"


// this allows for easier interpolation between two Xform_states.

struct Xform_state
{
    Vec3f translation;
    //Quaternion rotation;
    Vec3f Scale;
};


#endif