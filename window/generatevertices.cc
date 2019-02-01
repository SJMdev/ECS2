#include "window.ih"

void Window::generateVertices(Model &model)
{    
//Generate all face vertices & push them back. maybe do this during parsing.
    for (size_t idx =0; idx != model.vertex_indices.size(); ++idx)
    {
        Vertex temp = { 
                        model.vertices.at(model.vertex_indices.at(idx)).x * 0.8f,  //vx
                        model.vertices.at(model.vertex_indices.at(idx)).y * 0.8f,  //vy
                        model.vertices.at(model.vertex_indices.at(idx)).z * 0.8f,  //vz
                        model.uvs.at(model.uv_indices.at(idx)).u,                  //u                                       //u
                        model.uvs.at(model.uv_indices.at(idx)).v,                  //v
                        model.normals.at(model.normal_indices.at(idx)).x,          //nx
                        model.normals.at(model.normal_indices.at(idx)).y,          //ny
                        model.normals.at(model.normal_indices.at(idx)).z,          //nz                     
                      };
        model.interleaved_vertices.push_back(temp);
    }

    SDL_Log("model.interleaved_vertices.size(): %d", model.interleaved_vertices.size());
        
}