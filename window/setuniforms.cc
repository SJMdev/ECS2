#include "window.ih"

void Window::setUniforms(GLuint currentShaderProgram)
{
    // for gouraud.
    d_materialLocation        = glGetUniformLocation(currentShaderProgram, "material");
    d_lightPositionLocation   = glGetUniformLocation(currentShaderProgram, "lightPosition");
    d_lightColorLocation      = glGetUniformLocation(currentShaderProgram, "lightColor");
    d_textureLocation         = glGetUniformLocation(currentShaderProgram, "textureUniform");

    d_modelLocation           = glGetUniformLocation(currentShaderProgram, "modelMatrix");
    d_viewMatrixLocation      = glGetUniformLocation(currentShaderProgram, "viewMatrix");
    d_projectionLocation      = glGetUniformLocation(currentShaderProgram, "modelProjection");
    d_normalTransformLocation = glGetUniformLocation(currentShaderProgram, "normalTransform");
}