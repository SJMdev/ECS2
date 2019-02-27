#ifndef INCLUDED_MATERIAL_
#define INCLUDED_MATERIAL_

// data class.

// https://learnopengl.com/Lighting/Materials

class Material
{

	public:
		Material();
		Material(Vec3f &ambient, Vec3f &diffuse, Vec3f &specular);

		Vec3f d_ambient;
		Vec3f d_diffuse;
		Vec3f d_specular;




}