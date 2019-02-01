#include "window.ih"

void Window::loadModel(string &filename, Model &model)
{
    loadOBJFromFile(filename, model);
    SDL_Log("Successfully loaded object from source file.");
    SDL_Log("amount of vertices in file: %d", model.vertices.size());
    SDL_Log("amount of vertex indices in file: %d", model.vertex_indices.size());
    SDL_Log("amount of normal indices in file: %d", model.normal_indices.size());

}