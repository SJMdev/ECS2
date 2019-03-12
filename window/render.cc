#include "window.ih"

//////////////////////////////////
// clear the color & depth buffer
// state which program to use 
// calculate the view transformation
// set up the light position vector (currently at 0,0, -0.5, 1)
/////////////////////////////////////////////////////////////////


void Window::render()
{
    // clear the screen!
    // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // glClearColor(0,0,0,1); 
    // // bind shader program (set_shader?)
    // glUseProgram(d_gProgramID);
    
    // calculateViewTransformation();
    // // shader mode stuff:



    // //if shadermode is something:
    // // d_lightPositionVector = {0, 0, 0.5, 1};
    // glUniform4fv(d_lightPositionLocation, 1, d_lightPositionVector.data());
    // glUniform3fv(d_lightColorLocation,    1, d_Light.color.data()); // fixed this!
    // glUniform4fv(d_materialLocation,      1, d_material.data());
    
    // // glActiveTexture(GL_TEXTURE0);
    // // bind the view matrix to the uniform. 
    // glUniformMatrix4fv(d_viewMatrixLocation,      1, false, d_viewMatrix.data());
    // //use the projection matrix, set in the beginning:
    // glUniformMatrix4fv(d_projectionMatrixLocation,      1, false, d_projectionMatrix.data());


    // for(auto &object : d_objects)
    //     drawObject(object)


    //for all objects, draw:
  //  for (auto &object : d_objects)
    //{
//         glActiveTexture(GL_TEXTURE0);
//         //calculate object model matrix
// //        object.modelMatrix = object.translationMatrix * object.rotationMatrix * object.scaleMatrix;
//         object.modelMatrix = object.scaleMatrix * object.rotationMatrix * object.translationMatrix;
//         object.normalTransformMatrix = object.modelMatrix.normalMatrix();

//         glUniformMatrix4fv(d_modelMatrixLocation, 1, false, object.modelMatrix.data());
//         glUniformMatrix3fv(d_normalTransformMatrixLocation, 1, false, object.normalTransformMatrix.data());

//         glBindVertexArray(gVAO);
//         glBindTexture(GL_TEXTURE_2D, object.TBO);


//         glUniform1i(d_textureLocation, 0);
//         glDrawArrays(GL_TRIANGLES, 0, d_objects.at(0).interleaved_vertices.size());
    //}

    
    //unbind program
    glUseProgram(0); // NULL?

}