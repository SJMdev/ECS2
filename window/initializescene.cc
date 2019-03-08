#include "window.ih"

//@TODO: replace d_material by a vec4f.
// sets up:
// d_material
// d_lightTranslationMatrix
// d_lightColor;
// d_viewTranslationMatrix


void Window::initializeScene()
{
    d_material = std::vector<float>{ 0.4, 0.6, 0.8, 64 };
 	d_light.translationMatrix.toIdentity();
    d_light.rotationMatrix.toIdentity();
    d_light.scaleMatrix.toIdentity();


    //d_modelMatrix.toIdentity();
    
}