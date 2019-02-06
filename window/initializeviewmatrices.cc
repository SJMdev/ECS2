#include "window.ih"

void Window::initializeViewMatrices()
{
    d_viewTranslationMatrix.toIdentity();
    d_viewTranslationMatrix[3][3] = -2;

    d_viewRotationMatrix.toIdentity();
    d_viewScaleMatrix.toIdentity();
}