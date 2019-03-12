#include "window.ih"

void Window::setUniforms(GLuint currentShaderProgram)
{
    // for gouraud.
    d_materialLocation               = glGetUniformLocation(currentShaderProgram, "material");
    d_lightPositionLocation          = glGetUniformLocation(currentShaderProgram, "lightPosition");
    d_lightColorLocation             = glGetUniformLocation(currentShaderProgram, "lightColor");


    
    // some stuff that will be edited later!
    d_textureLocation                = glGetUniformLocation(currentShaderProgram, "textureUniform");
    d_modelMatrixLocation            = glGetUniformLocation(currentShaderProgram, "modelMatrix");
    d_viewMatrixLocation             = glGetUniformLocation(currentShaderProgram, "viewMatrix");
    d_projectionMatrixLocation       = glGetUniformLocation(currentShaderProgram, "modelProjection");
    d_normalTransformMatrixLocation  = glGetUniformLocation(currentShaderProgram, "normalTransform");
}