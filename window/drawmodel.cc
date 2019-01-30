#include "window.ih"
#define BUFFER_OFFSET(i) ((void*)(i)) //hacky macro

void Window::drawModel(Model &model)
{
        std::vector<Point3> verts;

        //Generate all face vertices & push them back.
        for (int idx =0; idx != model.vertex_indices.size(); ++idx)
        {
                Point3 temp = { model.vertices.at(model.vertex_indices.at(idx)).x * 0.8f,
                                model.vertices.at(model.vertex_indices.at(idx)).y * 0.8f,
                                model.vertices.at(model.vertex_indices.at(idx)).z * 0.8f, 
                                model.normals.at(model.normal_indices.at(idx)).x,
                                model.normals.at(model.normal_indices.at(idx)).y,
                                model.normals.at(model.normal_indices.at(idx)).z                               
                };
                verts.push_back(temp);
        }
        
        //generate something else
        // for (int idx =0; idx != model.vertices.size(); ++idx)
        // {
        //         Point3 temp = { model.vertices.at(idx).x * 0.8f,
        //                         model.vertices.at(idx).y * 0.8f,
        //                         model.vertices.at(idx).z * 0.8f, 
        //                         1,
        //                         0,
        //                         0                              
        //         };
        //         verts.push_back(temp);
        // }

        // vector<float> indices;
        // //reconstruct one index buffer
        // for (int idx = 0; idx != model.vertex_indices.size(); ++idx)
        // {
        //         indices.push_back(model.vertex_indices.at(idx));
        //         indices.push_back(model.uv_indices.at(idx));
        //         indices.push_back(model.normal_indices.at(idx));
        // }


        GLsizei objectCount = 1;
         
        //create VBO
        glGenBuffers(objectCount, &gVBO);     // glsizei n, GLuint *buffers
        glGenVertexArrays(objectCount, &gVAO); // glsizei n, GLuinbt *arrays
        glBindVertexArray(gVAO);
        glBindBuffer(GL_ARRAY_BUFFER, gVBO);

        // //create IBO
        // glGenBuffers(objectCount, &gIBO);
        // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, gIBO);
        // // glBufferData(GL_ELEMENT_ARRAY_BUFFER, static_cast<int>(model.vertex_indices.size() * sizeof(float)), model.vertex_indices.data(), GL_STATIC_DRAW);
        // glBufferData(GL_ELEMENT_ARRAY_BUFFER, static_cast<int>(indices.size() * sizeof(float)), indices.data(), GL_STATIC_DRAW);
        

        // END
        glBufferData(GL_ARRAY_BUFFER, static_cast<int>(verts.size() * sizeof(Point3)), verts.data(), GL_STATIC_DRAW);
        
        
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Point3), 0); // x , y,z
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Point3), BUFFER_OFFSET(3 * sizeof(float))); //r,g,b!

}