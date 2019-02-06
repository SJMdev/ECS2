#ifndef INCLUDED_VEC3F_
#define INCLUDED_VEC3F_
#include "../utility/math.h"
#include <string>
#include <sstream>

//@Todo: implement move stuff in order for Vec3 to be aligned in memory to allow operator[] to access the correct thing. I still feel this is very dangerous.


class Vec3f
{
    public:
    
    float x;
    float y;
    float z;
    
    Vec3f() {}
    explicit Vec3f(float x, float y, float z) { set(x , y, z);}
    explicit Vec3f(float x) { set(x, x, x);}
    
    float operator[](const int index) const;
    float &operator[](const int index);
    Vec3f operator+(const Vec3f &rhs) const;
    Vec3f operator-() const;
    Vec3f operator-(const Vec3f &rhs) const;
    float operator*(const Vec3f &rhs) const;
    Vec3f operator*(const float rhs) const;
    Vec3f operator/(const float rhs) const;
    Vec3f &operator+=(const Vec3f &rhs);
    Vec3f &operator-=(const Vec3f &rhs);
    Vec3f &operator-=(const float rhs);
    Vec3f &operator*=(const Vec3f &rhs);
    Vec3f &operator/=(const Vec3f &rhs);
    Vec3f &operator/=(const float rhs);
    Vec3f &operator*=(const float rhs);
      
    friend Vec3f operator*(const float lhs, const Vec3f rhs);
    
    bool operator==( const Vec3f &rhs) const;
    bool operator!=( const Vec3f &rhs) const;

    bool compare(const Vec3f &rhs) const;
    float normalize();

    void zero(); //sets all values to 0
    void set(float x, float y, float z);

    std::string toString();
    //linear interpolation between!
    //void lerp?
};


inline void Vec3f::set( float x, float y ,float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

inline void Vec3f::zero()
{
    x = 0.0f;
    y = 0.0f;
    z = 0.0f;
}

inline bool Vec3f::compare( const Vec3f &rhs) const
{
    return ( (x == rhs.x) &&
             (y == rhs.y) &&
             (z == rhs.z)
            );
}

inline float Vec3f::operator[](int index) const
{
    return ( &x )[index]; //this is really dangerous.
    
    // I don't know whether an allocated object is aligned contiguously in memory.
}

inline float &Vec3f::operator[](int index)
{
    return ( &x )[index];
}

inline Vec3f Vec3f::operator-() const
{
    return Vec3f(-x,-y,-z);
}

inline Vec3f Vec3f::operator-(const Vec3f &rhs) const
{
    return Vec3f(x - rhs.x, y - rhs.y, z - rhs.z);
}

inline float Vec3f::operator*(const Vec3f &rhs) const
{
    return x * rhs.x + y * rhs.y + z *rhs.z;  
}


inline Vec3f operator*(const float lhs, const Vec3f rhs)
{
    return Vec3f(lhs *rhs.x, lhs * rhs.y, lhs * rhs.z);
}

inline Vec3f Vec3f::operator*(const float rhs) const
{
    return Vec3f( x * rhs, y * rhs, z * rhs);
}

inline Vec3f Vec3f::operator/(const float rhs) const
{
    float inv_rhs = 1.0f / rhs;
    return Vec3f(x * inv_rhs, y * inv_rhs, z * inv_rhs);
}

inline Vec3f &Vec3f::operator+=(const Vec3f &rhs)
{
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;

    return *this;
}

inline Vec3f &Vec3f::operator-=(const Vec3f &rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;

    return *this;
}

inline Vec3f &Vec3f::operator-=(const float rhs)
{
    x -= rhs;
    y -= rhs;
    z -= rhs;

    return *this;
}


inline Vec3f &Vec3f::operator/=(const Vec3f &rhs)
{
    x /= rhs.x;
    y /= rhs.y;
    z /= rhs.z;

    return *this;
}

inline Vec3f &Vec3f::operator/=(const float rhs)
{
    float inv_rhs = 1.0f/rhs;
    x *= inv_rhs;
    y *= inv_rhs;
    z *= inv_rhs;
    
    return *this;
}

inline Vec3f&Vec3f::operator*=(const float rhs)
{
    x *= rhs;
    y *= rhs;
    z *= rhs;

    return *this;
}
inline bool Vec3f::operator==(const Vec3f &rhs) const
{
    return compare(rhs);
}

inline bool Vec3f::operator!=(const Vec3f &rhs) const
{
    return !compare(rhs);
}

inline float Vec3f::normalize()
{
    float squareLength, inverseLength;
    squareLength = x * x + y * y + z * z;
    inverseLength = Math::invSqrt(squareLength);
    x *= inverseLength;
    y *= inverseLength;
    z *= inverseLength;

    return inverseLength * squareLength;
}

inline std::string Vec3f::toString()
{
    std::stringstream ss;
    ss << x <<  " , " << y << " , " << z '\n';
    return ss.str();
}




#endif


