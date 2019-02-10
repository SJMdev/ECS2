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
    
    
    d_objects.at(1).translationMatrix[3][0] = 0.8;
    //d_objects.at(1).rotationMatrix.rotateSelf(90,0,0);
    
    for (auto &object: d_objects)
        sendObjectToBuffer(object);
   
    
    SDL_Log("found %d objects.", d_objects.size());   
}