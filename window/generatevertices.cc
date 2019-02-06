#include "window.ih"

void Window::generateVertices(Object &object)
{    
//Generate all face vertices & push them back. maybe do this during parsing.
    for (size_t idx =0; idx != object.rawData.vertex_indices.size(); ++idx)
    {
        Vertex temp = { 
                        object.rawData.vertices.at(object.rawData.vertex_indices.at(idx)).x * 0.8f,  //vx
                        object.rawData.vertices.at(object.rawData.vertex_indices.at(idx)).y * 0.8f,  //vy
                        object.rawData.vertices.at(object.rawData.vertex_indices.at(idx)).z * 0.8f,  //vz
                        object.rawData.uvs.at(object.rawData.uv_indices.at(idx)).u,                  //u                                       //u
                        object.rawData.uvs.at(object.rawData.uv_indices.at(idx)).v,                  //v
                        object.rawData.normals.at(object.rawData.normal_indices.at(idx)).x,          //nx
                        object.rawData.normals.at(object.rawData.normal_indices.at(idx)).y,          //ny
                        object.rawData.normals.at(object.rawData.normal_indices.at(idx)).z,          //nz                     
                      };
        object.interleaved_vertices.push_back(temp);
    }

    SDL_Log("object.interleaved_vertices.size(): %d", object.interleaved_vertices.size());
        
}