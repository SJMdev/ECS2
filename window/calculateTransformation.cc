#include "window.ih"

void Window::calculateTransformation()
{
    // this is incorrect i think.
    d_lightModelMatrix = d_lightTranslationMatrix * d_rotationMatrix * d_scaleMatrix; //* QVector4D(0,0,0,1);
}

