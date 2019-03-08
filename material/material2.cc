#include "material.ih"


Material::Material(Vec3f &ambient, Vec3f &diffuse, Vec3f &specular, float shine_intensity
:
	d_ambient(ambient),
	d_diffuse(diffuse),
	d_specular(specular)
{

}