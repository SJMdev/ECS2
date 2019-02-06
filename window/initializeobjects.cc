#include "window.ih"

void Window::initializeObjects(vector<string> &objectNames)
{
    // create as many objects as we have objectNames (preallocate?).
    // I won't do that here.

    for (auto &objectName : objectNames)
    {
        Object object;
        loadObject(objectName,object); 
        // we generate the vertices here too.
        generateVertices(object);
        object.scaleMatrix.toIdentity();
        object.translationMatrix.toIdentity();
        object.rotationMatrix.toIdentity();

        object.modelMatrix = object.translationMatrix * object.rotationMatrix * object.scaleMatrix;
        d_objects.push_back(object);
    }
    SDL_Log("found %d objects.", d_objects.size());

    // move this to some other place.

    sendObjectToBuffer(d_objects.at(0));

    //calculate transformation:
    //object.modelMatrix = object.translationMatrix * object.rotationMatrix * object.scaleMatrix;
}