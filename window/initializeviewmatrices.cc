#include "window.ih"

void Window::initializeViewMatrices()
{
    d_viewTranslationMatrix.toIdentity();
    d_viewTranslationMatrix.translate(0.0f, 0.5f, 0.0f);
    d_viewRotationMatrix.toIdentity();
    d_viewScaleMatrix.toIdentity();
}