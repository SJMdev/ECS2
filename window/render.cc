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
    

    glDrawArrays(GL_TRIANGLES, 0, 3);
    //unbind program
    glUseProgram(0); // NULL?

}