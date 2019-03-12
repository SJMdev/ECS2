#include "window.ih"

void Window::prepareToRender()
{
	  // clear the screen!
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0,0,0,1); 
    // bind shader program (set_shader?)
    glUseProgram(d_gProgramID);
    
    calculateViewTransformation();
    // shader mode stuff:

    //if shadermode is something:
    d_lightPositionVector = {0, 0, 0.5, 1};
    d_light.color = {1.0f, 1.0f, 1.0f};
    glUniform4fv(d_lightPositionLocation, 1, d_lightPositionVector.data());
    glUniform3fv(d_lightColorLocation,    1, d_light.color.data()); //this is not yet fixed!
    glUniform4fv(d_materialLocation,      1, d_material.data());
    
    // glActiveTexture(GL_TEXTURE0);
    // bind the view matrix to the uniform. 
    glUniformMatrix4fv(d_viewMatrixLocation,      1, false, d_viewMatrix.data());
    //use the projection matrix, set in the beginning:
    glUniformMatrix4fv(d_projectionMatrixLocation,      1, false, d_projectionMatrix.data());
}