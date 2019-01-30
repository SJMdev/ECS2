#include "window.ih"

void Window::render()
{
     //bind program!
    //glUseProgram(gProgramID);
    // clear color buffer
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   // bind shader pprogram
   glUseProgram(d_gProgramID);

    //glClearColor(255,255,255,0); // set background color to white.

    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, gIBO);
    glBindVertexArray(gVAO);
    
    // glDrawElements(GL_TRIANGLES,d_activeModel.vertex_indices.size() * 3, GL_FLOAT, (void*)0);


    // was vertices.size();
    glDrawArrays(GL_TRIANGLES, 0, d_activeModel.vertex_indices.size());
    //unbind program
    glUseProgram(0); // NULL?

}