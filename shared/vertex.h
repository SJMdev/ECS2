#ifndef INCLUDED_VERTEX_
#define INCLUDED_VERTEX_

struct Vertex
{
    union
    {
        float pos[3];
        struct
        {
            float pos_x;
            float pos_y;
            float pos_z;
        };
    };
    union 
    {
        float n[3];
        struct
        {
            float n_x;
            float n_y;
            float n_z;
        };
    };
    union
    {
        float uv[2];
        struct
        {
            float u;
            float v;
        };
    };
};

#endif