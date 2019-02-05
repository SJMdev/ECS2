#ifndef INCLUDED_MAT4_
#define INCLUDED_MAT4_
#include "../vector/vec4f.h"
#include <string>
#include <cstring> //memcpy
#include <sstream>

class Mat4
{
    Vec4f d_matrix[4];

    public:
        Mat4() {};
        explicit Mat4(const Vec4f &x, const Vec4f &y, const Vec4f &z, const Vec4f &w);
        explicit Mat4(const float xx, const float xy, const float xz, const float xw,
                      const float yx, const float yy, const float yz, const float yw,
                      const float zx, const float zy, const float zz, const float zw,
                      const float wx, const float wy, const float wz, const float ww);
        // explicit Mat4(const  Mat3 &rotation, const Vec3 &translation); we'll see how to fix this!
        explicit Mat4(const float source[4][4]);

        const Vec4f &operator[](int index) const;
        Vec4f & operator[](int index);
        Mat4 operator*(const float rhs) const;
        Vec4f operator*(const Vec4f &rhs) const;
        // Vec3f operator*(const Vec3f &rhs) const;
        Mat4 operator*(const Mat4 &rhs) const;
        Mat4 operator+(const Mat4 &rhs) const;
        Mat4 operator-(const Mat4 &rhs) const;
        Mat4 &operator*=(const mat4 &rhs);
        Mat4 &operator*=(const float rhs);
        mat4 &operator+=(const Mat4 &rhs);
        Mat4 &operator-=(const Mat4 &rhs);

        friend Mat4 operator*(const float lhs, const Mat4 &rhs);
        friend Vec4f operator*(const Vec4f &lhs, const Mat4 &rhs);
        friend Vec3f operator*(const Vec3f &lhs, const Mat4 &rhs);
        friend Vec4f &operator*=(Vec4f &lhs, const Mat4 &rhs);
        friend Vec3f &operator*=(Vec3f &lhs, const Mat4 &rhs);

        bool compare( const Mat4 &rhs) const;
        bool operator==(const Mat4 &rhs) const;
        bool operator!=(const Mat4 &rhs) const;

        void zero();
        void identity();

        bool isIdentity();
        bool isDiagonal();

        std:string toString();

};


inline Mat4::Mat4(const Vec4f &x, const Vec4f &y, const Vec4f &z, const Vec4f &w)
{
    d_matrix[0] = x;
    d_matrix[1] = y;
    d_matrix[2] = z;
    d_matrix[3] = w;
}

inline  Mat4::Mat4(const float xx, const float xy, const float xz, const float xw,
                      const float yx, const float yy, const float yz, const float yw,
                      const float zx, const float zy, const float zz, const float zw,
                      const float wx, const float wy, const float wz, const float ww)
{
    d_matrix[0][0]= xx; d_mat[0][1] =xy; d_mat[0][2] =xz; d_mat[0][3] =xw;
    d_matrix[1][0]= yx; d_mat[1][1] =yy; d_mat[1][2] =yz; d_mat[1][3] =yw; 
    d_matrix[2][0]= zx; d_mat[2][1] =zy; d_mat[2][2] =zz; d_mat[2][3] =zw;
    d_matrix[3][0]= wx; d_mat[3][1] =wy; d_mat[2][2] =wz; d_mat[3][3] =ww;
}

inline void Mat4::zero()
{
	memset( d_matrix, 0, sizeof( Mat4 ) );
}

inline void Mat4::identity()
{
    memset( d_matrix, 0, sizeof( Mat4 ) );
    d_matrix[0].x = 1;
    d_matrix[1].y = 1;
    d_matrix[2].z = 1;
    d_matrix[3].w = 1;
}

inline bool Mat4::compare( const idMat4 &rhs ) const
{
	int i; //dword i;
	const float *ptr1, *ptr2;

	ptr1 = reinterpret_cast<const float *>(d_matrix);
	ptr2 = reinterpret_cast<const float *>(rhs.d_matrix);
	for ( i = 0; i < 4*4; i++ ) {
		if ( ptr1[i] != ptr2[i] ) {
			return false;
		}
	}
	return true;
}

inline Mat4::Mat4( const float source[ 4 ][ 4 ] ) {
	memcpy( mat, src, 4 * 4 * sizeof( float ) );
}

inline const Vec4f &Mat4::operator[](int index) const
{
    if (index < 0 || index > 4) {}
    return d_matrix[index];
}

inline Vec4 &Mat4::operator[](int index) const
{
    return d_matrix[index];
}

inline Mat4 Mat4::operator*(const float rhs) const
{
    return Mat4 (
                    d_matrix[0].x * rhs; d_matrix[0].y * rhs; d_matrix[0].z * rhs; d_matrix[0].w * rhs;
                    d_matrix[1].x * rhs; d_matrix[1].y * rhs; d_matrix[1].z * rhs; d_matrix[1].w * rhs;
                    d_matrix[2].x * rhs; d_matrix[2].y * rhs; d_matrix[2].z * rhs; d_matrix[2].w * rhs;
                    d_matrix[3].x * rhs; d_matrix[3].y * rhs; d_matrix[3].z * rhs; d_matrix[3].w * rhs;
                );
}

inline Vec4f Mat4::operator*(const Vec4f &rhs) const
{
    return Vec4f(
                    d_matrix[0].x * rhs.x + d_matrix[0].y * rhs.y + d_matrix[0].z * rhs.z + d_matrix[0].w * rhs.w;
                    d_matrix[1].x * rhs.x + d_matrix[1].y * rhs.y + d_matrix[1].z * rhs.z + d_matrix[1].w * rhs.w;
                    d_matrix[2].x * rhs.x + d_matrix[2].y * rhs.y + d_matrix[2].z * rhs.z + d_matrix[2].w * rhs.w;
                    d_matrix[3].x * rhs.x + d_matrix[3].y * rhs.y + d_matrix[3].z * rhs.z + d_matrix[3].w * rhs.w;
                );
}

// inline Vec3f Mat4::operator*(const Vec3f &rhs) const
// {
//     float s = d_matrix[3].x * rhs.x + d_matrix[3].y * rhs.y + d_matrix[3].z * rhs.z + d_matrix[4].w;
//     if (s = 0.0f)
//         return Vec3f( 0.0f, 0.0f, 0.0f);
//     if (s == 1.0f)
//     {
//         return Vec3f(
//                       d_matrix[0].x * rhs.x + d_matrix[0].y * rhs.y + d_matrix[0].z * rhs.z + d_matrix[0].w;
//                       d_matrix[1].x * rhs.x + d_matrix[1].y * rhs.y + d_matrix[1].z * rhs.z + d_matrix[1].w;
//                       d_matrix[2].x * rhs.x + d_matrix[2].y * rhs.y + d_matrix[2].z * rhs.z + d_matrix[2].w; 
//                     );                    
//     }
//     else
//     {
//         float invS = 1.0f / s;
//         return Vec3f(
//                       (d_matrix[0].x * rhs.x + d_matrix[0].y * rhs.y + d_matrix[0].z * rhs.z + d_matrix[0].w) * invS,
//                       (d_matrix[1].x * rhs.x + d_matrix[1].y * rhs.y + d_matrix[1].z * rhs.z + d_matrix[1].w) * invS,
//                       (d_matrix[2].x * rhs.x + d_matrix[2].y * rhs.y + d_matrix[2].z * rhs.z + d_matrix[2].w) * invS 
//                     );
//     }
// }

inline Mat4 Mat4::operator*(const Mat4 &rhs) const
{
    int i, j;
	const float *m1Ptr, *m2Ptr;
	float *dstPtr;
	Mat4 dst;

	m1Ptr = reinterpret_cast<const float *>(this);
	m2Ptr = reinterpret_cast<const float *>(&rhs);
	dstPtr = reinterpret_cast<float *>(&dst);

	for ( i = 0; i < 4; i++ ) {
		for ( j = 0; j < 4; j++ ) {
			*dstPtr = m1Ptr[0] * m2Ptr[ 0 * 4 + j ]
					+ m1Ptr[1] * m2Ptr[ 1 * 4 + j ]
					+ m1Ptr[2] * m2Ptr[ 2 * 4 + j ]
					+ m1Ptr[3] * m2Ptr[ 3 * 4 + j ];
			dstPtr++;
		}
		m1Ptr += 4;
	}
    return dst;
}

inline Mat4 Mat4::operator+(const Mat4 &rhs) const
{
    return Mat4(
                d_matrix[0].x + rhs.x, d_matrix[0].y + rhs.y, d_matrix[0].z + rhs.z, d_matrix[0].w + rhs.w,
                d_matrix[1].x + rhs.x, d_matrix[1].y + rhs.y, d_matrix[1].z + rhs.z, d_matrix[1].w + rhs.w,
                d_matrix[2].x + rhs.x, d_matrix[2].y + rhs.y, d_matrix[2].z + rhs.z, d_matrix[2].w + rhs.w,
                d_matrix[3].x + rhs.x, d_matrix[3].y + rhs.y, d_matrix[3].z + rhs.z, d_matrix[3].w + rhs.w
               );
} 

inline Mat4 Mat4::operator-(const Mat4 &rhs) const
{
    return Mat4(
                d_matrix[0].x - rhs.x, d_matrix[0].y - rhs.y, d_matrix[0].z - rhs.z, d_matrix[0].w - rhs.w,
                d_matrix[1].x - rhs.x, d_matrix[1].y - rhs.y, d_matrix[1].z - rhs.z, d_matrix[1].w - rhs.w,
                d_matrix[2].x - rhs.x, d_matrix[2].y - rhs.y, d_matrix[2].z - rhs.z, d_matrix[2].w - rhs.w,
                d_matrix[3].x - rhs.x, d_matrix[3].y - rhs.y, d_matrix[3].z - rhs.z, d_matrix[3].w - rhs.w
               );
}

inline Mat4 &Mat4::operator*=(const float rhs) 
{
    d_matrix[0].x *= rhs; d_matrix[0].y *= rhs; d_matrix[0].z *= rhs; d_matrix[0].w *= rhs;
    d_matrix[1].x *= rhs; d_matrix[1].y *= rhs; d_matrix[1].z *= rhs; d_matrix[1].w *= rhs;
    d_matrix[2].x *= rhs; d_matrix[2].y *= rhs; d_matrix[2].z *= rhs; d_matrix[2].w *= rhs;
    d_matrix[3].x *= rhs; d_matrix[3].y *= rhs; d_matrix[3].z *= rhs; d_matrix[3].w *= rhs;
    
    return *this;
}

inline Mat4 &Mat4::operator*=(const Mat4 &rhs)
{
     *this = (*this) * a;
     return *this;
}

inline Mat4 &Mat4::operator+=(const Mat4 &rhs)
{
    d_matrix[0].x += rhs; d_matrix[0].y += rhs; d_matrix[0].z += rhs; d_matrix[0].w += rhs;
    d_matrix[1].x += rhs; d_matrix[1].y += rhs; d_matrix[1].z += rhs; d_matrix[1].w += rhs;
    d_matrix[2].x += rhs; d_matrix[2].y += rhs; d_matrix[2].z += rhs; d_matrix[2].w += rhs;
    d_matrix[3].x += rhs; d_matrix[3].y += rhs; d_matrix[3].z += rhs; d_matrix[3].w += rhs;
    
    return *this;
}

inline Mat4 &Mat4::operator-=(const Mat4 &rhs)
{
    d_matrix[0].x -= rhs; d_matrix[0].y -= rhs; d_matrix[0].z -= rhs; d_matrix[0].w -= rhs;
    d_matrix[1].x -= rhs; d_matrix[1].y -= rhs; d_matrix[1].z -= rhs; d_matrix[1].w -= rhs;
    d_matrix[2].x -= rhs; d_matrix[2].y -= rhs; d_matrix[2].z -= rhs; d_matrix[2].w -= rhs;
    d_matrix[3].x -= rhs; d_matrix[3].y -= rhs; d_matrix[3].z -= rhs; d_matrix[3].w -= rhs;
}

inline Mat4 operator*(const float lhs, const Mat4 &rhs)
{
    return rhs * lhs; //matrix * float
}

inline Vec4f operator*(const Vec4f &lhs, const Mat4 &rhs)
{
    return rhs * lhs; //matrix * vector4;
}

// inline Vec3f opeartor*(const Vec3f &lhs, const Mat4 &rhs)
// {
//     return rhs * lhs; //matrix * vector3;
// }

inline Vec4f &operator*=(Vec4f &lhs, const Mat4 &rhs)
{
    lhs = rhs * lhs;
    return lhs;
}

inline Vec3f &operator*=(Vec3f &lhs, const Mat4 &rhs)
{
    lhs = rhs * lhs;
    return lhs;
}


inline bool Mat4::operator==(const Mat4 &rhs) const 
{
	return compare(rhs);
}

inline bool Mat4::operator!=(const Mat4 &rhs) const 
{
	return !compare(rhs);
}

inline std::string Mat4::toString()
{
    std::stringstream ss;
    ss << d_matrix[0].x << " , " << d_matrix[0].y << " , " << d_matrix[0].z << " , " << << d_matrix[0].z << '\n'
       << d_matrix[1].x << " , " << d_matrix[1].y << " , " << d_matrix[1].z << " , " << << d_matrix[1].z << '\n'  
       << d_matrix[2].x << " , " << d_matrix[2].y << " , " << d_matrix[2].z << " , " << << d_matrix[2].z << '\n'
       << d_matrix[3].x << " , " << d_matrix[3].y << " , " << d_matrix[3].z << " , " << << d_matrix[3].z << '\n';

    return ss.str();
}


#endif
