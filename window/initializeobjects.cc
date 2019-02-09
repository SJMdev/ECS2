#include "window.ih"

// Load .OBJ from filename
// generate vertices from raw_vertices
// set scale, translation & rotation
// send objects to buffer.

void Window::initializeObjects(vector<ObjectFilePaths>  &objectFilePaths)
{
    for (auto &filepaths : objectFilePaths)
    {
        Object object;
		
        loadObject(filepaths.modelPath,object); 
	    fillTexture(object.texture, filepaths.texturePath);
        // we generate the vertices here too.
        generateVertices(object);
		
		
        object.scaleMatrix.toIdentity();
        object.translationMatrix.toIdentity();
        object.rotationMatrix.toIdentity();

	    object.translationMatrix[3][2] = -3; 
        object.scaleMatrix.scaleSelf(0.05f);
        object.modelMatrix = object.rotationMatrix * object.scaleMatrix;
		object.modelMatrix = object.translationMatrix * object.modelMatrix; 
	  			

		
        d_objects.push_back(object);
    }
    SDL_Log("found %d objects.", d_objects.size());


    sendObjectToBuffer(d_objects.at(0));

}