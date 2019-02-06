#ifndef INCLUDED_MAT3_
#define INCLUDED_MAT3_
#include "../vector/vec3f.h"
#include <string>
#include <cstring> //memcpy
#include <sstream>

#define MATRIX_INVERSE_EPSILON		1e-14
#define MATRIX_EPSILON				1e-6

class Mat3
{
    Vec3f d_matrix[3];

    public:
        Mat3() {};
        explicit Mat3(const Vec3f &x, const Vec3f &y, const Vec3f &z);

        explicit Mat3(const float xx, const float xy, const float xz,
                      const float yx, const float yy, const float yz, 
                      const float zx, const float zy, const float zz 
                     );
        // explicit Mat3(const  Mat3 &rotation, const Vec3 &translation); we'll see how to fix this!
        explicit Mat3(const float source[3][3]);

        const Vec3f &operator[](int index) const;
        Vec3f & operator[](int index);
        Mat3 operator*(const float rhs) const;
        Vec3f operator*(const Vec3f &rhs) const;
        // Vec3f operator*(const Vec3f &rhs) const;
        Mat3 operator*(const Mat3 &rhs) const;
        Mat3 operator+(const Mat3 &rhs) const;
        Mat3 operator-(const Mat3 &rhs) const;
        Mat3 operator-() const;
        Mat3 &operator*=(const Mat3 &rhs);
        Mat3 &operator*=(const float rhs);
        Mat3 &operator+=(const Mat3 &rhs);
        Mat3 &operator-=(const Mat3 &rhs);

        friend Mat3 operator*(const float lhs, const Mat3 &rhs);
        friend Vec3f operator*(const Vec3f &lhs, const Mat3 &rhs);
        friend Vec3f operator*(const Vec3f &lhs, const Mat3 &rhs);
        friend Vec3f &operator*=(Vec3f &lhs, const Mat3 &rhs);
        friend Vec3f &operator*=(Vec3f &lhs, const Mat3 &rhs);

        bool compare( const Mat3 &rhs) const;
        bool operator==(const Mat3 &rhs) const;
        bool operator!=(const Mat3 &rhs) const;

        void zero();
        void toIdentity();

        bool isIdentity();
        bool isDiagonal();

        Mat3 &transposeSelf();
        Mat3 inverse();
        //Mat3 transpose();
        bool inverseSelf();
        std::string toString();

        const float *data() const;
        float *data();

};


inline Mat3::Mat3(const Vec3f &x, const Vec3f &y, const Vec3f &z)
{
    d_matrix[0] = x;
    d_matrix[1] = y;
    d_matrix[2] = z;
}

inline  Mat3::Mat3(const float xx, const float xy, const float xz,
                   const float yx, const float yy, const float yz,
                   const float zx, const float zy, const float zz
                  )
{
    d_matrix[0][0]= xx; d_matrix[0][1] =xy; d_matrix[0][2] =xz;
    d_matrix[1][0]= yx; d_matrix[1][1] =yy; d_matrix[1][2] =yz;
    d_matrix[2][0]= zx; d_matrix[2][1] =zy; d_matrix[2][2] =zz;
}

inline Mat3::Mat3( const float source[ 3 ][ 3 ] ) {
	memcpy( d_matrix, source, 3 * 3 * sizeof( float ) );
}


inline bool Mat3::compare(const Mat3 &rhs) const
{
	if (d_matrix[0].compare(rhs[0]) &&
		d_matrix[1].compare(rhs[1]) &&
		d_matrix[2].compare(rhs[2])) 
    {
		return true;
	}
    return false;
}



inline const Vec3f &Mat3::operator[](int index) const
{
    if (index < 0 || index > 3) {}
    return d_matrix[index];
}

inline Vec3f &Mat3::operator[](int index)
{
    return d_matrix[index];
}

inline Mat3 Mat3::operator-() const
{
    return Mat3(	
                 -d_matrix[0][0], -d_matrix[0][1], -d_matrix[0][2],
				 -d_matrix[1][0], -d_matrix[1][1], -d_matrix[1][2],
                 -d_matrix[2][0], -d_matrix[2][1], -d_matrix[2][2]
               );
}

inline Vec3f Mat3::operator*(const Vec3f &rhs) const
{
    return Vec3f(
                    d_matrix[0].x * rhs.x + d_matrix[0].y * rhs.y + d_matrix[0].z * rhs.z,
                    d_matrix[1].x * rhs.x + d_matrix[1].y * rhs.y + d_matrix[1].z * rhs.z,
                    d_matrix[2].x * rhs.x + d_matrix[2].y * rhs.y + d_matrix[2].z * rhs.z
                );
}

inline Mat3 Mat3::operator*(const Mat3 &rhs) const
{
    int i, j;
	const float *m1Ptr, *m2Ptr;
	float *dstPtr;
	Mat3 dst;

	m1Ptr = reinterpret_cast<const float *>(this);
	m2Ptr = reinterpret_cast<const float *>(&rhs);
	dstPtr = reinterpret_cast<float *>(&dst);

	for ( i = 0; i < 3; i++ ) {
		for ( j = 0; j < 3; j++ ) {
			*dstPtr = m1Ptr[0] * m2Ptr[ 0 * 3 + j ]
					+ m1Ptr[1] * m2Ptr[ 1 * 3 + j ]
					+ m1Ptr[2] * m2Ptr[ 2 * 3 + j ];
			dstPtr++;
		}
		m1Ptr += 3;
	}
    return dst;
}

inline Mat3 Mat3::operator*(const float rhs) const
{
    return Mat3 (
                    d_matrix[0].x * rhs, d_matrix[0].y * rhs, d_matrix[0].z * rhs,
                    d_matrix[1].x * rhs, d_matrix[1].y * rhs, d_matrix[1].z * rhs, 
                    d_matrix[2].x * rhs, d_matrix[2].y * rhs, d_matrix[2].z * rhs
                );
}



inline Mat3 Mat3::operator+(const Mat3 &rhs) const
{
    return Mat3(
                d_matrix[0].x + rhs[0].x, d_matrix[0].y + rhs[0].y, d_matrix[0].z + rhs[0].z,
                d_matrix[1].x + rhs[1].x, d_matrix[1].y + rhs[1].y, d_matrix[1].z + rhs[1].z,
                d_matrix[2].x + rhs[2].x, d_matrix[2].y + rhs[2].y, d_matrix[2].z + rhs[2].z
               );
} 

inline Mat3 Mat3::operator-(const Mat3 &rhs) const
{
    return Mat3(
                d_matrix[0].x - rhs[0].x, d_matrix[0].y - rhs[0].y, d_matrix[0].z - rhs[0].z,
                d_matrix[1].x - rhs[1].x, d_matrix[1].y - rhs[1].y, d_matrix[1].z - rhs[1].z,
                d_matrix[2].x - rhs[2].x, d_matrix[2].y - rhs[2].y, d_matrix[2].z - rhs[2].z
               );
}

inline Mat3 &Mat3::operator*=(const float rhs) 
{
    d_matrix[0].x *= rhs; d_matrix[0].y *= rhs; d_matrix[0].z *= rhs;
    d_matrix[1].x *= rhs; d_matrix[1].y *= rhs; d_matrix[1].z *= rhs; 
    d_matrix[2].x *= rhs; d_matrix[2].y *= rhs; d_matrix[2].z *= rhs;
    d_matrix[3].x *= rhs; d_matrix[3].y *= rhs; d_matrix[3].z *= rhs;

    return *this;
}

inline Mat3 &Mat3::operator*=(const Mat3 &rhs)
{
    int i, j;
	const float *m2Ptr;
	float *m1Ptr, dst[3];

	m1Ptr = reinterpret_cast<float *>(this);
	m2Ptr = reinterpret_cast<const float *>(&rhs);

	for ( i = 0; i < 3; i++ ) {
		for ( j = 0; j < 3; j++ ) {
			dst[j]  = m1Ptr[0] * m2Ptr[ 0 * 3 + j ]
					+ m1Ptr[1] * m2Ptr[ 1 * 3 + j ]
					+ m1Ptr[2] * m2Ptr[ 2 * 3 + j ];
		}
		m1Ptr[0] = dst[0]; m1Ptr[1] = dst[1]; m1Ptr[2] = dst[2];
		m1Ptr += 3;
	}
    return *this;
}

inline Mat3 &Mat3::operator+=(const Mat3 &rhs)
{
    d_matrix[0].x += rhs[0].x; d_matrix[0].y += rhs[0].y; d_matrix[0].z += rhs[0].z;
    d_matrix[1].x += rhs[1].x; d_matrix[1].y += rhs[1].y; d_matrix[1].z += rhs[1].z;
    d_matrix[2].x += rhs[2].x; d_matrix[2].y += rhs[2].y; d_matrix[2].z += rhs[2].z;
    
    return *this;
}

inline Mat3 &Mat3::operator-=(const Mat3 &rhs)
{
    d_matrix[0].x -= rhs[0].x; d_matrix[0].y -= rhs[0].y; d_matrix[0].z -= rhs[0].z;
    d_matrix[1].x -= rhs[1].x; d_matrix[1].y -= rhs[1].y; d_matrix[1].z -= rhs[1].z;
    d_matrix[2].x -= rhs[2].x; d_matrix[2].y -= rhs[2].y; d_matrix[2].z -= rhs[2].z;

    return *this;
}

inline Vec3f operator*(const Vec3f &lhs, const Mat3 &rhs)
{
    return rhs * lhs;
}

inline Mat3 operator*(const float lhs, const Mat3 &rhs)
{
    return rhs * lhs; //matrix * float
}


inline Vec3f &operator*=(Vec3f &lhs, const Mat3 &rhs)
{
    float x = rhs[ 0 ].x * lhs.x + rhs[ 1 ].x * lhs.y + rhs[ 2 ].x * lhs.z;
	float y = rhs[ 0 ].y * lhs.x + rhs[ 1 ].y * lhs.y + rhs[ 2 ].y * lhs.z;
	lhs.z = rhs[ 0 ].z * lhs.x + rhs[ 1 ].z * lhs.y + rhs[ 2 ].z * lhs.z;
	lhs.x = x;
	lhs.y = y;  

    return lhs;
}

inline bool Mat3::operator==(const Mat3 &rhs) const 
{
	return compare(rhs);
}

inline bool Mat3::operator!=(const Mat3 &rhs) const 
{
	return !compare(rhs);
}

inline std::string Mat3::toString()
{
    std::stringstream ss;
    ss << std::to_string(d_matrix[0].x) << " , " << std::to_string(d_matrix[0].y) << " , " << std::to_string(d_matrix[0].z) << " , " << '\n'
       << std::to_string(d_matrix[1].x) << " , " << std::to_string(d_matrix[1].y) << " , " << std::to_string(d_matrix[1].z) << " , " << '\n'  
       << std::to_string(d_matrix[2].x) << " , " << std::to_string(d_matrix[2].y) << " , " << std::to_string(d_matrix[2].z) << " , " << '\n';

    return ss.str();
}

inline void Mat3::zero()
{
	memset( d_matrix, 0, sizeof( Mat3 ) );
}

inline void Mat3::toIdentity()
{
    memset( d_matrix, 0, sizeof( Mat3 ) );
    d_matrix[0].x = 1;
    d_matrix[1].y = 1;
    d_matrix[2].z = 1;
}

inline Mat3 &Mat3::transposeSelf()
{
	float tmp0, tmp1, tmp2;

	tmp0 = d_matrix[0][1];
	d_matrix[0][1] = d_matrix[1][0];
	d_matrix[1][0] = tmp0;
	tmp1 = d_matrix[0][2];
	d_matrix[0][2] = d_matrix[2][0];
	d_matrix[2][0] = tmp1;
	tmp2 = d_matrix[1][2];
	d_matrix[1][2] = d_matrix[2][1];
	d_matrix[2][1] = tmp2;

	return *this;
}


inline bool Mat3::inverseSelf()
{
    // 18+3+9 = 30 multiplications
	//			 1 division
	Mat3 inverse;
	double det, invDet;

	inverse[0][0] = d_matrix[1][1] * d_matrix[2][2] - d_matrix[1][2] * d_matrix[2][1];
	inverse[1][0] = d_matrix[1][2] * d_matrix[2][0] - d_matrix[1][0] * d_matrix[2][2];
	inverse[2][0] = d_matrix[1][0] * d_matrix[2][1] - d_matrix[1][1] * d_matrix[2][0];

	det = d_matrix[0][0] * inverse[0][0] + d_matrix[0][1] * inverse[1][0] + d_matrix[0][2] * inverse[2][0];

	if ( fabs(det) < MATRIX_INVERSE_EPSILON ) {
		return false;
	}

	invDet = 1.0f / det;

	inverse[0][1] = d_matrix[0][2] * d_matrix[2][1] - d_matrix[0][1] * d_matrix[2][2];
	inverse[0][2] = d_matrix[0][1] * d_matrix[1][2] - d_matrix[0][2] * d_matrix[1][1];
	inverse[1][1] = d_matrix[0][0] * d_matrix[2][2] - d_matrix[0][2] * d_matrix[2][0];
	inverse[1][2] = d_matrix[0][2] * d_matrix[1][0] - d_matrix[0][0] * d_matrix[1][2];
	inverse[2][1] = d_matrix[0][1] * d_matrix[2][0] - d_matrix[0][0] * d_matrix[2][1];
	inverse[2][2] = d_matrix[0][0] * d_matrix[1][1] - d_matrix[0][1] * d_matrix[1][0];

	d_matrix[0][0] = inverse[0][0] * invDet;
	d_matrix[0][1] = inverse[0][1] * invDet;
	d_matrix[0][2] = inverse[0][2] * invDet;

	d_matrix[1][0] = inverse[1][0] * invDet;
	d_matrix[1][1] = inverse[1][1] * invDet;
	d_matrix[1][2] = inverse[1][2] * invDet;

	d_matrix[2][0] = inverse[2][0] * invDet;
	d_matrix[2][1] = inverse[2][1] * invDet;
	d_matrix[2][2] = inverse[2][2] * invDet;

	return true;
}

inline const float *Mat3::data() const
{
    return d_matrix[0].data();
} 

inline float *Mat3::data()
{
    return d_matrix[0].data();
}




#endif
