#include "scene.ih"

void Window::initializeLight(Light &light)
{	
	light.translationMatrix.toIdentity();
    light.rotationMatrix.toIdentity();
    light.scaleMatrix.toIdentity();
}