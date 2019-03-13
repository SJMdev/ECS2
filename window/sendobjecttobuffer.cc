#include "window.ih"
#define BUFFER_OFFSET(i) ((void*)(i)) //hacky macro

void Window::sendObjectToBuffer(Object &object)
{
    // actually send the data to the buffer. We pass a reference to the raw data in interleaved vertices.
    glBufferData(GL_ARRAY_BUFFER, static_cast<int>(object.interleaved_vertices.size() * sizeof(Vertex)), object.interleaved_vertices.data(), GL_STATIC_DRAW);
     
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0); // x, y, z
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), BUFFER_OFFSET(3 * sizeof(float))); //  skip  3: u, v,
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), BUFFER_OFFSET(5 * sizeof(float)));   //skip 5: r, g, b.

}