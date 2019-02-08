#include "window.ih"


void Window::calculateViewTransformation()
{
	d_viewMatrix = d_viewRotationMatrix * d_viewScaleMatrix;
    d_viewMatrix = d_viewTranslationMatrix * d_viewMatrix;

    // SDL_Log("calculateViewTransformation: viewMatrix: %s", d_viewMatrix.toString().c_str());
}