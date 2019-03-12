#include "scene.ih"

void Scene::initializeLight(Light &light)
{	
	light.translationMatrix.toIdentity();
    light.rotationMatrix.toIdentity();
    light.scaleMatrix.toIdentity();
}