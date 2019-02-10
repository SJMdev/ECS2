#include "window.ih"

// clear the color & depth buffer
// state which program to use 
// calculate the view transformation
// set up the light position vector (currently at 0,0, -0.5, 1)/


void Window::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // clear color buffer
    glClearColor(0,0,0,1); // r,g,b,a
    // bind shader program (set_shader?)
    glUseProgram(d_gProgramID);
    calculateViewTransformation();
	
	
	//SDL_Log("viewmatrix: %s", d_viewMatrix.toString().c_str());
	
	
    // shader mode stuff:
    //if shadermode is something:
    d_lightPositionVector = {0, 0, 0.5, 1};
    glUniform4fv(d_lightPositionLocation, 1, d_lightPositionVector.data());
    glUniform3fv(d_lightColorLocation,    1, d_lightColor.data());
    glUniform4fv(d_materialLocation,      1, d_material.data());
    
    glActiveTexture(GL_TEXTURE0);

    // bind the view matrix to the uniform. 
    glUniformMatrix4fv(d_viewMatrixLocation,      1, false, d_viewMatrix.data());
	
	
    //SDL_Log("projection matrix; %s", d_projectionMatrix.toString().c_str());	
    //use the projection matrix, set in the beginning:
    glUniformMatrix4fv(d_projectionMatrixLocation,      1, false, d_projectionMatrix.data());


    //for all objects, draw:
    for (auto &object : d_objects)
    {
        //calculate object model matrix
        object.modelMatrix = object.translationMatrix * object.rotationMatrix * object.scaleMatrix;
        //SDL_Log("obj modelmatrix: %s", object.modelMatrix.toString().c_str());
        //object.modelMatrix.transposeSelf()
        object.normalTransformMatrix = object.modelMatrix.normalMatrix();

        glUniformMatrix4fv(d_modelMatrixLocation, 1, false, object.modelMatrix.data());
        glUniformMatrix3fv(d_normalTransformMatrixLocation, 1, false, object.normalTransformMatrix.data());

        glBindVertexArray(gVAO);
        glBindTexture(GL_TEXTURE_2D, object.TBO);


        glUniform1i(d_textureLocation, 0);
        glDrawArrays(GL_TRIANGLES, 0, d_objects.at(0).interleaved_vertices.size());
    }

  

    // this is very naive.
    
    //unbind program
    glUseProgram(0); // NULL?

}