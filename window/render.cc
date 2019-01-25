#include "window.ih"

void Window::render()
{
     //bind program!
    //glUseProgram(gProgramID);
    // clear color buffer
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   // bind shader pprogram
   glUseProgram( gProgramID);

    //glClearColor(255,255,255,0); // set background color to white.
    

    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, gIBO);
    glBindVertexArray(gVAO);
    
    glDrawElements(GL_TRIANGLES,d_activeModel.vertices.size(), GL_FLOAT, (void*)0);



    glDrawArrays(GL_TRIANGLES, 0, d_activeModel.vertices.size());
    //unbind program
    glUseProgram(0); // NULL?

}