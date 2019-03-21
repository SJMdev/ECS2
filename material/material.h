// #v1

#ifndef INCLUDED_MATERIAL_
#define INCLUDED_MATERIAL_
#include "../vector/vec3f.h"
#include "../color/color.h"
// data class.

// https://learnopengl.com/Lighting/Materials

struct Material
{
		// key?
		std::string d_name;
		
		Color d_ambient_color;
		Color d_diffuse_color;
		Color d_specular_color;
		Color d_transmission_filter;
		float d_specular_exponent;
		float shine_intensity;
		float d_opacity;
};

#endif