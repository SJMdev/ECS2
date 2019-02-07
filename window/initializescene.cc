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

    d_lightTranslationMatrix = {
                                1, 0, 0, 0,
        	                    0, 1, 0, 0,
                                0, 0, 1, -0.5,
                                0, 0, 0, 1
                                };
    d_lightRotationMatrix = {
                                1, 0, 0, 0,
        	                    0, 1, 0, 0,
                                0, 0, 1, 0,
                                0, 0, 0, 1
                                };
    d_lightScaleMatrix = {
                                1, 0, 0, 0,
        	                    0, 1, 0, 0,
                                0, 0, 1, 0,
                                0, 0, 0, 1
                                };
                                
    
    d_lightColor = std::vector<float> { 1.0, 0.0, 0.0};

    d_modelMatrix.toIdentity();
    
    setUniforms(d_gProgramID);


}