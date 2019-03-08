#include "scene.ih"

Scene::Scene()
//:
{
	initializeLight(&d_light);	
    d_lightColor = std::vector<float> { 1.0, 1.0, 1.0};


}