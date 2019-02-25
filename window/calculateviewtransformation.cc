#include "window.ih"


void Window::calculateViewTransformation()
{
 	d_viewMatrix = d_viewRotationMatrix * d_viewScaleMatrix;
     d_viewMatrix = d_viewTranslationMatrix * d_viewMatrix;
    
     d_viewMatrix = d_viewScaleMatrix * d_viewRotationMatrix * d_viewTranslationMatrix;

    // SDL_Log("calculateViewTransformation: viewMatrix: %s", d_viewMatrix.toString().c_str());
}