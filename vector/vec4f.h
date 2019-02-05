#ifndef INCLUDED_VEC4F_
#define INCLUDED_VEC4F_
#include "../utility/math.h"


//@Todo: implement move stuff in order for Vec4 to be aligned in memory to allow operator[] to access the correct thing. I still feel this is very dangerous.
//@Todo: fix normalization via inverse square root!


class Vec4f
{
    public:
    
    float d_x;
    float d_y;
    float d_z;
    float d_w;
    
    Vec4f() {};
    explicit Vec4f(float x, float y, float z, float w) { set( x , y, z, w)};
    explicit Vec4f(float x) { set(x, x, x, x)};
    
    float operator[](const int index) const;
    float &operator[](const int index);
    Vec4f operator+(const Vec4f &rhs) const;
    Vec4f operator-() const;
    Vec4f operator-(const Vec4f &rhs) const;
    float operator*(const Vec4f &rhs) const;
    Vec4f operator*(const float rhs) const;
    Vec4f operator/(const Vec4f &rhs) const;
    Vec4f &operator+=(const Vec4f &rhs);
    Vec4f &operator-=(const Vec4f &rhs);
    Vec4f &operator*=(const Vec4f &rhs);
    Vec4f &operator/=(const Vec4f &rhs);
    Vec4f &operator/=(const float rhs);
    Vec4f &operator*=(const float rhs);
      
    friend Vec4f operator*(const float lhs, const Vec4f rhs);
    
    bool operator==( const Vec4f &rhs) const;
    bool operator!=( const Vec4f &rhs) const;

    bool compare(const Vec4f &rhs) const;
    float Normalize();

    void zero(); //sets all values to 0
    void set();

    
    //linear interpolation between!
    //void lerp?
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

inline bool Vec4f::compare( const Vec4f &rhs) const
{
    return ( (d_x == rhs.d_x) &&
             (d_y == rhs.d_y) &&
             (d_z == rhs.d_z) &&
             (d_w == rhs.d_w)
            );
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

inline Vec4f Vec4f::operator-(const Vec4f &rhs) const
{
    return Vec4f(d_x - rhs.d_x, d_y - rhs.d_y, d_z - rhs.d_z, d_w - rhs.d_w);
}

inline float Vec4f::operator*(const Vec4f &rhs) const
{
    return d_x * rhs.d_x + d_y * rhs.d_y + d_z *rhs.d_z + d_w * rhs.d_w;  
}

inline Vec4f Vec4f::operator*(const float lhs, const Vec4f rhs)
{
    return Vec4f(lhs *d_x, lhs * d_y, lhs * d_z, lhs * d_w);
}

inline Vec4f Vec4f::operator*(const float rhs) const
{
    return Vec4f( d_x * rhs, d_y * rhs, d_z * rhs, d_w * rhs);
}

inline Vec4f Vec4f::operator/(const float rhs) const
{
    float inv_rhs = 1.0f / rhs;
    return Vec4f(d_x * inv_rhs, d_y * inv_rhs, d_z * inv_rhs, d_w * inv_rhs);
}

inline Vec4f &Vec4f::operator+=(const Vec4f &rhs)
{
    d_x += rhs.d_x;
    d_y += rhs.d_y;
    d_z += rhs.d_z;
    d_w += rhs.d_w;

    return *this;
}

inline Vec4f &Vec4f::operator-=(const Vec4f &rhs)
{
    d_x -= rhs.d_x;
    d_y -= rhs.d_y;
    d_z -= rhs.d_z;
    d_w -= rhs.d_w;

    return *this;
}

inline Vec4f &Vec4f::operator-=(const float rhs)
{
    d_x -= rhs;
    d_y -= rhs;
    d_z -= rhs;
    d_w -= rhs;

    return *this;
}


inline Vec4f &Vec4f::operator/=(const Vec4f &rhs)
{
    d_x /= rhs.d_x;
    d_y /= rhs.d_y;
    d_z /= rhs.d_z;
    d_w /= rhs.d_w;

    return *this;
}

inline Vec4f &Vec4f::operator/=(const float rhs)
{
    float inva = 1.0f/a;
    d_x *= rhs;
    d_y *= rhs;
    d_z *= rhs;
    d_w *= rhs;
    
    return *this;
}

inline Vec4f&Vec4f::operator*=(const float rhs)
{
    d_x *= rhs;
    d_y *= rhs;
    d_z *= rhs;
    d_w *= rhs;

    return *this;
}
inline bool Vec4f::operator==(const Vec4f &rhs)
{
    return compare(rhs);
}

inline bool Vec4f::operator!=(const Vec4f &rhs)
{
    return !compare(rhs);
}

inline float Vec4f::normalize()
{
    float squareLength, inverseLength;
    squareLength = d_x * d_x + d_y * d_y + d_z * d_z + d_w * d_w;
    inverseLength = Math::invSqrt(squareLength);
    d_x *= inverseLength;
    d_y *= inverseLength;
    d_z *= inverseLength;
    d_w *= inverseLength;
    return inverseLength * squareLength;
}









