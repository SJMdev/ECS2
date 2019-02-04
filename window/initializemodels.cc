#include "window.ih"

void Window::initializeModels(vector<string> &modelNames)
{
    // create as many models as we have modelNames (preallocate?).
    // I won't do that here.



    SDL_Log("texture width: %d", texture.width);
    SDL_Log("texture height:%d", texture.height);

    for (auto &modelName : modelNames)
    {
        Model model;
        loadModel(modelName,model); 
        // we generate the vertices here too.
        generateVertices(model);
        d_models.push_back(model);
    }
    SDL_Log("found %d models.", d_models.size());

    sendModelToBuffer(d_models.at(0));
    
}