#include "window.ih"

void Window::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // clear color buffer
    glClearColor(0,0,0,1); // r,g,b,a
    // bind shader program (set_shader?)
    glUseProgram(d_gProgramID);

    calculateTransformation();
    calculateViewTransformation();

    

    // shader mode stuff:
    //if shadermode is something:
    d_lightPositionVector = {0, 0, 0, 1};
    glUniform4fv(d_lightPositionLocation, 1, d_lightPositionVector.data());
    glUniform3fv(d_lightColorLocation,    1, d_lightColor.data());
    glUniform4fv(d_materialLocation,      1, d_material.data());
    

    glActiveTexture(GL_TEXTURE0);
    d_projectionTransformation.toIdentity();
    glUniformMatrix4fv(d_viewMatrixLocation,      1, false, d_viewMatrix.data());
    glUniformMatrix4fv(d_projectionLocation,      1, false, d_projectionTransformation.data());


    //for all objects, c:
    for (auto &object : d_objects)
    {
        object.modelMatrix = object.translationMatrix * object.rotationMatrix * object.scaleMatrix;
        object.normalTransformMatrix = object.modelMatrix.normalMatrix();
        glUniformMatrix4fv(d_modelLocation, 1, false, object.modelMatrix.data()); // I have no idea whether this will work or not.
        glUniformMatrix3fv(d_normalTransformLocation, 1, false, object.normalTransformMatrix.data());

        glBindVertexArray(gVAO);
        glBindTexture(GL_TEXTURE_2D, gTBO);

        glDrawArrays(GL_TRIANGLES, 0, d_objects.at(0).interleaved_vertices.size());
    }

  

    // this is very naive.
    
    //unbind program
    glUseProgram(0); // NULL?

}