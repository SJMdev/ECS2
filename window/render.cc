#include "window.ih"

void Window::render()
{
   // bind shader program (set_shader?)
    glUseProgram(d_gProgramID);
    // clear color buffer
    glClearColor(0,0,0,1); // r,g,b,a
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // shader mode stuff:
    //if shadermode is something:
    d_lightPositionVector = {0, 0, 0, 1};
    glUniform4fv(d_lightPositionLocation, 1, d_lightPositionVector.data());
    glUniform4fv(d_materialLocation,      1, d_material.data());
    glUniform3fv(d_lightColorLocation,    1, d_lightColor.data());

    glActiveTexture(GL_TEXTURE0);
    
    glUniformMatrix4fv(d_viewMatrixLocation,      1, false, d_viewMatrix.data());
    glUniformMatrix4fv(d_projectionLocation,      1, false, d_projectionTransformation.data());


    //for all objects, c:
    for (auto &object : d_objects)
    {
        object.modelMatrix = object.translationMatrix * object.rotationMatrix * object.scaleMatrix;
        glUniformMatrix4fv(d_modelLocation, 1, false, &object.modelMatrix.d_matrix) // I have no idea whether this will work or not.
        //glUniformMatrix3fv(somestuff)
    }

    glBindVertexArray(gVAO);
    glBindTexture(GL_TEXTURE_2D, gTBO);


    // this is very naive.
    glDrawArrays(GL_TRIANGLES, 0, d_objects.at(0).interleaved_vertices.size());
    //unbind program
    glUseProgram(0); // NULL?

}