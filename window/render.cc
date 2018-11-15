#include "window.ih"

void Window::render()
{
    // clear color buffer
    glClear(GL_COLOR_BUFFER_BIT);

    // render quad?
    if (gRenderQuad)
    {
        //bind program!
        glUseProgram(gProgramID);

        //enable vertex position
        glEnableVertexAttribArray(gVertexPos2DLocation);

        //set vertex data
        glBindBuffer( GL_ARRAY_BUFFER, gVBO);
        glVertexAttribPointer( gVertexPos2DLocation, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), NULL);

        //set index data and render
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, gIBO);
        glDrawElements(GL_TRIANGLE_FAN, 4, GL_UNSIGNED_INT, NULL);

        // disable vertex position

        glDisableVertexAttribArray(gVertexPos2DLocation);

        //unbind program
        glUseProgram(0); // NULL?

    }
}