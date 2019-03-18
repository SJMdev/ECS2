#ifndef INCLUDED_MATERIAL_
#define INCLUDED_MATERIAL_
#include "../vector/vec3f.h"
#include "../color/color.h"
// data class.

// https://learnopengl.com/Lighting/Materials

class Material
{

	public:
		Material() {};
		// Vec3f d_ambient;
		// Vec3f d_diffuse;
		// Vec3f d_specular;


		std::string name;
		Color d_ambient_color;
		Color d_diffuse_color;
		Color d_specular_color;
		Color d_transmission_filter;
		float d_specular_exponent;

		float shine_intensity;




}