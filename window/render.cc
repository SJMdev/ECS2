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
	//d_viewMatrix[3][2] = 1.0f;

	SDL_Log("viewmatrix: %s", d_viewMatrix.toString().c_str());
	
	
    // shader mode stuff:
    //if shadermode is something:
    d_lightPositionVector = {0, 0, 0.5, 1};
    glUniform4fv(d_lightPositionLocation, 1, d_lightPositionVector.data());
    glUniform3fv(d_lightColorLocation,    1, d_lightColor.data());
    glUniform4fv(d_materialLocation,      1, d_material.data());
    
    glActiveTexture(GL_TEXTURE0);

    // set the view matrix 
    glUniformMatrix4fv(d_viewMatrixLocation,      1, false, d_viewMatrix.data());
	
	// what if we reset projection matrix?
	d_projectionMatrix.toIdentity();
     	
    //use the projection matrix, set in the beginning:
    glUniformMatrix4fv(d_projectionMatrixLocation,      1, false, d_projectionMatrix.data());


    //for all objects, c:
    for (auto &object : d_objects)
    {
        //calculate object model matrix
        object.modelMatrix = object.translationMatrix * object.rotationMatrix * object.scaleMatrix;
        //SDL_Log("obj modelmatrix: %s", object.modelMatrix.toString().c_str());
        object.normalTransformMatrix = object.modelMatrix.normalMatrix();

        glUniformMatrix4fv(d_modelMatrixLocation, 1, false, object.modelMatrix.data());
        glUniformMatrix3fv(d_normalTransformMatrixLocation, 1, false, object.normalTransformMatrix.data());

        glBindVertexArray(gVAO);
        glBindTexture(GL_TEXTURE_2D, gTBO);


        glUniform1i(d_textureLocation, 0);
        glDrawArrays(GL_TRIANGLES, 0, d_objects.at(0).interleaved_vertices.size());
    }

  

    // this is very naive.
    
    //unbind program
    glUseProgram(0); // NULL?

}