#ifndef INCLUDED_MATERIAL_
#define INCLUDED_MATERIAL_
#include "vector/vec3f.h"
// data class.

// https://learnopengl.com/Lighting/Materials

class Material
{

	public:
		Material() {};
		Material(Vec3f &ambient, Vec3f &diffuse, Vec3f &specular, float shine_intensity);

		Vec3f d_ambient;
		Vec3f d_diffuse;
		Vec3f d_specular;
		float d_shine_intensity;




}