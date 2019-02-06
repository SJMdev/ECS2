#include "window.ih"

void Window::calculateTransformation()
{
    d_lightPosition     = d_lightTranslationMatrix * d_rotationMatrix * d_scaleMatrix; //* QVector4D(0,0,0,1);


}

