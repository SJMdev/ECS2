#ifndef INCLUDED_VEC4F_
#define INCLUDED_VEC4F_
#include "../utility/math.h"
#include <string>
#include <sstream>

//@Todo: implement move stuff in order for Vec4 to be aligned in memory to allow operator[] to access the correct thing. I still feel this is very dangerous.


class Vec4f
{
    public:
    
    float x;
    float y;
    float z;
    float w;
    
    Vec4f() {}
    explicit Vec4f(float x, float y, float z, float w) { set( x , y, z, w);}

    explicit Vec4f(float x) { set(x, x, x, x);}
    
    float operator[](const int index) const;
    float &operator[](const int index);
    Vec4f operator+(const Vec4f &rhs) const;
    Vec4f operator-() const;
    Vec4f operator-(const Vec4f &rhs) const;
    float operator*(const Vec4f &rhs) const;
    Vec4f operator*(const float rhs) const;
    Vec4f operator/(const float rhs) const;
    Vec4f &operator+=(const Vec4f &rhs);
    Vec4f &operator-=(const Vec4f &rhs);
    Vec4f &operator-=(const float rhs);
    Vec4f &operator*=(const Vec4f &rhs);
    Vec4f &operator/=(const Vec4f &rhs);
    Vec4f &operator/=(const float rhs);
    Vec4f &operator*=(const float rhs);
      
    friend Vec4f operator*(const float lhs, const Vec4f rhs);
    
    bool operator==( const Vec4f &rhs) const;
    bool operator!=( const Vec4f &rhs) const;

    bool compare(const Vec4f &rhs) const;
    float normalize();

    void zero(); //sets all values to 0
    void set(float x, float y, float z, float w);

    std::string toString();
    //linear interpolation between!
    //void lerp?
};


inline void Vec4f::set( float x, float y ,float z, float w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

inline void Vec4f::zero()
{
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
    w = 0.0f;
}

inline bool Vec4f::compare( const Vec4f &rhs) const
{
    return ( (x == rhs.x) &&
             (y == rhs.y) &&
             (z == rhs.z) &&
             (w == rhs.w)
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
    return Vec4f(-x,-y,-z,-w);
}

inline Vec4f Vec4f::operator-(const Vec4f &rhs) const
{
    return Vec4f(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
}


inline float Vec4f::operator*(const Vec4f &rhs) const
{
    return x * rhs.x + y * rhs.y + z *rhs.z + w * rhs.w;  
}


inline Vec4f operator*(const float lhs, const Vec4f rhs)
{
    return Vec4f(lhs *rhs.x, lhs * rhs.y, lhs * rhs.z, lhs * rhs.w);
}

inline Vec4f Vec4f::operator*(const float rhs) const
{
    return Vec4f( x * rhs, y * rhs, z * rhs, w * rhs);
}

inline Vec4f Vec4f::operator/(const float rhs) const
{
    float inv_rhs = 1.0f / rhs;
    return Vec4f(x * inv_rhs, y * inv_rhs, z * inv_rhs, w * inv_rhs);
}

inline Vec4f &Vec4f::operator+=(const Vec4f &rhs)
{
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    w += rhs.w;

    return *this;
}

inline Vec4f &Vec4f::operator-=(const Vec4f &rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    w -= rhs.w;

    return *this;
}

inline Vec4f &Vec4f::operator-=(const float rhs)
{
    x -= rhs;
    y -= rhs;
    z -= rhs;
    w -= rhs;

    return *this;
}


inline Vec4f &Vec4f::operator/=(const Vec4f &rhs)
{
    x /= rhs.x;
    y /= rhs.y;
    z /= rhs.z;
    w /= rhs.w;

    return *this;
}

inline Vec4f &Vec4f::operator/=(const float rhs)
{
    float inv_rhs = 1.0f/rhs;
    x *= inv_rhs;
    y *= inv_rhs;
    z *= inv_rhs;
    w *= inv_rhs;
    
    return *this;
}

inline Vec4f&Vec4f::operator*=(const float rhs)
{
    x *= rhs;
    y *= rhs;
    z *= rhs;
    w *= rhs;

    return *this;
}
inline bool Vec4f::operator==(const Vec4f &rhs) const
{
    return compare(rhs);
}

inline bool Vec4f::operator!=(const Vec4f &rhs) const
{
    return !compare(rhs);
}

inline float Vec4f::normalize()
{
    float squareLength, inverseLength;
    squareLength = x * x + y * y + z * z+ w * w;
    inverseLength = Math::invSqrt(squareLength);
    x *= inverseLength;
    y *= inverseLength;
    z *= inverseLength;
    w *= inverseLength;
    return inverseLength * squareLength;
}

inline std::string Vec4f::toString()
{
    std::stringstream ss;
    ss << x <<  " , " << y << " , " << z << " , " << w << '\n';
    return ss.str();
}




#endif


