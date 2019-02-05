#ifndef INCLUDED_Vec3f_
#define INCLUDED_Vec3f_
#include "../utility/math.h"


//@Todo: implement move stuff in order for Vec4 to be aligned in memory to allow operator[] to access the correct thing. I still feel this is very dangerous.
//@Todo: fix normalization via inverse square root!


class Vec3f
{
    public:
    
    float d_x;
    float d_y;
    float d_z;
    
    Vec3f() {};
    explicit Vec3f(float x, float y, float z,) { set( x , y, z,)};
    explicit Vec3f(float xyz) { set(xyz, xyz, xyz)};
    
    float operator[](const int index) const;
    float &operator[](const int index);
    Vec3f operator+(const Vec3f &rhs) const;
    Vec3f operator-() const;
    Vec3f operator-(const Vec3f &rhs) const;
    float operator*(const Vec3f &rhs) const;
    Vec3f operator*(const float rhs) const;
    Vec3f operator/(const Vec3f &rhs) const;
    Vec3f &operator+=(const Vec3f &rhs);
    Vec3f &operator-=(const Vec3f &rhs);
    Vec3f &operator*=(const Vec3f &rhs);
    Vec3f &operator/=(const Vec3f &rhs);
    Vec3f &operator/=(const float rhs);
    Vec3f &operator*=(const float rhs);
      
    friend Vec3f operator*(const float lhs, const Vec3f rhs);
    
    bool operator==( const Vec3f &rhs) const;
    bool operator!=( const Vec3f &rhs) const;
    bool compare(const Vec3f &rhs) const;

    float Normalize();

    void zero(); //sets all values to 0
    void set();

    //linear interpolation between!
    //void lerp?
};


inline void Vec3f::set( float x, float y ,float z)
{
    d_x = x;
    d_y = y;
    d_z = z;
}

inline void Vec3f::zero()
{
    d_x = 0.0f;
    d_y = 0.0f;
    d_z = 0.0f;
}

inline bool Vec3f::compare( const Vec3f &rhs) const
{
    return ( (d_x == rhs.d_x) &&
             (d_y == rhs.d_y) &&
             (d_z == rhs.d_z)
            );
}

inline float Vec3f::operator[](int index) const
{
    return ( &x )[index]; //this is really dangerous.
    
    // I don't know whether an allocated object is aligned contiguously in memory.
    // we need 
}

inline float &Vec3f::operator[](int index)
{
    return ( &x )[index];
}

inline Vec3f Vec3f::operator-() const
{
    return Vec3f(-d_x,-d_y,-d_z);
}

inline Vec3f Vec3f::operator-(const Vec3f &rhs) const
{
    return Vec3f(d_x - rhs.d_x, d_y - rhs.d_y, d_z - rhs.d_z);
}

inline float Vec3f::operator*(const Vec3f &rhs) const
{
    return d_x * rhs.d_x + d_y * rhs.d_y + d_z *rhs.d_z;  
}

inline Vec3f Vec3f::operator*(const float lhs, const Vec3f rhs)
{
    return Vec3f(lhs *d_x, lhs * d_y, lhs * d_z);
}

inline Vec3f Vec3f::operator*(const float rhs) const
{
    return Vec3f(d_x * rhs, d_y * rhs, d_z * rhs);
}

inline Vec3f Vec3f::operator/(const float rhs) const
{
    float inv_rhs = 1.0f / rhs;
    return Vec3f(d_x * inv_rhs, d_y * inv_rhs, d_z * inv_rhs);
}

inline Vec3f &Vec3f::operator+=(const Vec3f &rhs)
{
    d_x += rhs.d_x;
    d_y += rhs.d_y;
    d_z += rhs.d_z;

    return *this;
}

inline Vec3f &Vec3f::operator-=(const Vec3f &rhs)
{
    d_x -= rhs.d_x;
    d_y -= rhs.d_y;
    d_z -= rhs.d_z;

    return *this;
}

inline Vec3f &Vec3f::operator-=(const float rhs)
{
    d_x -= rhs;
    d_y -= rhs;
    d_z -= rhs;

    return *this;
}


inline Vec3f &Vec3f::operator/=(const Vec3f &rhs)
{
    d_x /= rhs.d_x;
    d_y /= rhs.d_y;
    d_z /= rhs.d_z;

    return *this;
}

inline Vec3f &Vec3f::operator/=(const float rhs)
{
    float inva = 1.0f/a;
    d_x *= rhs;
    d_y *= rhs;
    d_z *= rhs;
    
    return *this;
}

inline Vec3f&Vec3f::operator*=(const float rhs)
{
    d_x *= rhs;
    d_y *= rhs;
    d_z *= rhs;

    return *this;
}
inline bool Vec3f::operator==(const Vec3f &rhs)
{
    return compare(rhs);
}

inline bool Vec3f::operator!=(const Vec3f &rhs)
{
    return !compare(rhs);
}

inline float Vec3f::normalize()
{
    float squareLength, inverseLength;
    squareLength = d_x * d_x + d_y * d_y + d_z * d_z;
    inverseLength = Math::invSqrt(inverseLength);
    d_x *= inverseLength;
    d_y *= inverseLength;
    d_z *= inverseLength;

    return inverseLength * squareLength;
}









