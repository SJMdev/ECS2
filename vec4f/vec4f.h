#ifndef INCLUDED_VEC4F_
#define INCLUDED_VEC4F_


//@Todo: implement move stuff in order for Vec4 to be aligned in memory to allow operator[] to access the correct thing. I still feel this is very dangerous.

class Vec4f
{
    public:
    
    float d_x;
    float d_y;
    float d_z;
    float d_w;
    
    
    
    Vec4f() {};
    explicit Vec4f(float x, float y, float z, float w) { set( x , y, z, w)};
    explicit Vec4f(float x) { set(x, x, x, z)};
    
    float operator[](const int index) const;
    float &operator[](const int index);
    Vec4f operator-() const;
    float operator*(const Vec4f &rhs) const;
    Vec4f operator*(const float rhs) const;
    Vec4f operator-(const Vec4f &rhs) const;
    
    
    Vec4f operator+(const Vec4f &rhs) const;
    Vec4f operator/(const Vec4f &rhs) const;
    
    friend Vec4f operator*(const float lhs, const Vec4f rhs);
    
    void zero(); //sets all values to 0
    
    
    void set();
    
};


inline void Vec4f::set( float x, float y ,float z, float w)
{
    d_x = x;
    d_y = y;
    d_z = z;
    d_w = w;
}

inline void Vec4f::zero()
{
    d_x = 0.0f;
    d_y = 0.0f;
    d_z = 0.0f;
    d_w = 0.0f;
}

inline float Vec4f::operator[](int index) const
{
    return ( &x )[index]; //this is really dangerous.
    
    // I don't know whether an allocated object is aligned contiguously in memory.
    // we need 
}

inline float &Vec4f::operator[](int index)
{
    return ( &x )[index];
}

inline Vec4f Vec4f::operator-() const
{
    return Vec4f(-d_x,-d_y,-d_z,-d_w);
}


inline float Vec4f::operator*(const Vec4f &rhs) const
{
    return d_x * rhs.d_x + d_y * rhs.d_y + d_z *rhs.d_z + d_w * rhs.d_w;  
}





