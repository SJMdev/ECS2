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
		
		//object.translationMatrix.translate(0.0f,0.0f,0.0f); // x, y, ,z.
		
		object.translationMatrix[3][2] = -0.2f ;
		
        //SDL_Log( "matrix: %s", object.scaleMatrix.toString().c_str());
        //SDL_Log( "matrix: %s", object.translationMatrix.toString().c_str());

        object.modelMatrix = object.rotationMatrix * object.scaleMatrix;
		object.modelMatrix = object.translationMatrix * object.modelMatrix; 
	  	
//		SDL_Log( "object.modelMatrix: %s", object.modelMatrix.toString().c_str());
		
		
		
		
        d_objects.push_back(object);
    }
    SDL_Log("found %d objects.", d_objects.size());


    sendObjectToBuffer(d_objects.at(0));

}