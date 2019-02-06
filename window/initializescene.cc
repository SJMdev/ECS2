#include "window.ih"
// sets up:
// d_material
// d_lightTranslationMatrix
// d_lightColor;
// d_viewTranslationMatrix


void Window::initializeScene()
{
    d_material = std::vector<float>{ 0.4, 0.6, 0.8, 64 };

    d_lightTranslationMatrix = {
                                1, 0, 0, 0,
        	                    0, 1, 0, 0,
                                0, 0, 1, 0,
                                0, 0, 0, 1
                                };
    
    d_lightColor = std::vector<float> { 1.0, 0.0, 0.0};


    d_viewTranslationMatrix.toIdentity();
    d_viewRotationMatrix.toIdentity();
    d_viewScaleMatrix.toIdentity();
}