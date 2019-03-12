#include "scene.ih"

Scene::Scene()
//:
{
	initializeLight(d_light);	
    d_light.color = { 1.0, 1.0, 1.0};
    // d_material = std::vector<float> {}


}