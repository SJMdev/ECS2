#include "window.ih"

void Window::render()
{
   // bind shader program (set_shader?)
    glUseProgram(d_gProgramID);
    // clear color buffer
    glClearColor(0,0,0,1); // r,g,b,a
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBindVertexArray(gVAO);
    
    glBindTexture(GL_TEXTURE_2D, gTBO);


    // this is very naive.
    glDrawArrays(GL_TRIANGLES, 0, d_models.at(0).interleaved_vertices.size());
    //unbind program
    glUseProgram(0); // NULL?

}