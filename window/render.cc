#include "window.ih"

void Window::render()
{
     //bind program!
    //glUseProgram(gProgramID);
    // clear color buffer
    glClearColor(0,0,0,1); // r,g,b,a
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


    // draw_game_3d()

   // bind shader program (set_shader?)
    glUseProgram(d_gProgramID);


    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, gIBO);
    glBindVertexArray(gVAO);
    glBindTexture(gTBO);


    // this is very naive.
    glDrawArrays(GL_TRIANGLES, 0, d_models.at(0).interleaved_vertices.size());
    //unbind program
    glUseProgram(0); // NULL?

}