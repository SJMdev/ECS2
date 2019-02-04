#include "window.ih"

void Window::setUniforms()
{
    // if(d_shaderMode != NORMAL)
    {
        d_lightPositionLocation   = current.uniformLocation("lightPosition");
        d_lightColorLocation      = current.uniformLocation("lightColor");
        d_materialLocation        = current.uniformLocation("material");
        d_textureLocation         = current.uniformLocation("textureUniform");
    }

    d_modelLocation           = current.uniformLocation("modelMatrix");
    d_viewMatrixLocation      = current.uniformLocation("viewMatrix");
    d_projectionLocation      = current.uniformLocation("modelProjection");
    d_normalTransformLocation = current.uniformLocation("normalTransform");
}
}