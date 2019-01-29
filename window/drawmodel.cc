#include "window.ih"
#define BUFFER_OFFSET(i) ((void*)(i)) //hacky macro

void Window::drawModel(Model &model)
{
        glClearColor(0.2f, 0.5f, 0.7f, 0.0f); // r, g, b, a
        
        std::vector<Point3> verts;

        // naive solution, but i see something!
        for (int idx =0; idx != model.vertex_indices.size(); ++idx)
        {
                Point3 temp = { model.vertices.at(model.vertex_indices.at(idx)).x * 0.8,
                                model.vertices.at(model.vertex_indices.at(idx)).y * 0.8,
                                model.vertices.at(model.vertex_indices.at(idx)).z * 0.8, 
                                model.normals.at(model.normal_indices.at(idx)).x,
                                model.normals.at(model.normal_indices.at(idx)).y,
                                model.normals.at(model.normal_indices.at(idx)).z                               
                };
                verts.push_back(temp);
        }

        SDL_Log("verts.size: %i", verts.size());
        

        GLsizei objectCount = 1;
         
        //create VBO
        glGenBuffers(objectCount, &gVBO);     // glsizei n, GLuint *buffers
        glGenVertexArrays(objectCount, &gVAO); // glsizei n, GLuinbt *arrays
        glBindVertexArray(gVAO);
        glBindBuffer(GL_ARRAY_BUFFER, gVBO);


        // glGenBuffers(objectCount, &gIBO);
        // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, gIBO);
        // glBufferData(GL_ELEMENT_ARRAY_BUFFER, static_cast<int>(model.indices.size() * sizeof(float)), model.indices.data(), GL_STATIC_DRAW);
 

        // END
        glBufferData(GL_ARRAY_BUFFER, static_cast<int>(verts.size() * sizeof(Point3)), verts.data(), GL_STATIC_DRAW);
        

        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Point3), 0); // x , y,z
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Point3), BUFFER_OFFSET(3 * sizeof(float))); //r,g,b!



}