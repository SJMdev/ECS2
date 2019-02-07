#include "window.ih"

// Load .OBJ from filename
// generate vertices from raw_vertices
// set scale, translation & rotation
// send objects to buffer.

void Window::initializeObjects(vector<string> &objectNames)
{
    for (auto &objectName : objectNames)
    {
        Object object;
        loadObject(objectName,object); 
        // we generate the vertices here too.
        generateVertices(object);
        object.scaleMatrix.toIdentity();
        object.translationMatrix.toIdentity();
        object.rotationMatrix.toIdentity();
        SDL_Log( "matrix: %s", object.scaleMatrix.toString().c_str());
        SDL_Log( "matrix: %s", object.translationMatrix.toString().c_str());

        object.modelMatrix = object.translationMatrix * object.rotationMatrix * object.scaleMatrix;
        d_objects.push_back(object);
    }
    SDL_Log("found %d objects.", d_objects.size());


    sendObjectToBuffer(d_objects.at(0));

}