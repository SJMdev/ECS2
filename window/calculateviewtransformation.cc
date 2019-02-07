#include "window.ih"


void Window::calculateViewTransformation()
{
    d_viewMatrix = d_viewTranslationMatrix * d_viewRotationMatrix * d_viewScaleMatrix;

    // SDL_Log("calculateViewTransformation: viewMatrix: %s", d_viewMatrix.toString().c_str());
}