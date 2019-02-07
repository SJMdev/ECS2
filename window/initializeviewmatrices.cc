#include "window.ih"

void Window::initializeViewMatrices()
{
    d_viewTranslationMatrix.toIdentity();

    d_viewRotationMatrix.toIdentity();
    d_viewScaleMatrix.toIdentity();
}