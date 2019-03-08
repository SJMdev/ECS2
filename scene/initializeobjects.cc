#include "scene.ih"

// Load .OBJ from filename
// generate vertices from raw_vertices
// set scale, translation & rotation
// send objects to buffer.

void Scene::initializeObjects(vector<ObjectFilePaths>  &objectFilePaths)
{
    for (auto &filepaths : objectFilePaths)
    {
        Object object;
		
        Loader::loadObject(filepaths.modelPath, object);             
        // SDL_Log("Successfully loaded object from source file.");
        // SDL_Log("amount of vertices in file: %d", object.rawData.vertices.size());
        // SDL_Log("amount of vertex indices in file: %d", object.rawData.vertex_indices.size());
        // SDL_Log("amount of normal indices in file: %d", object.rawData.normal_indices.size());

	    fillTexture(filepaths.texturePath, object.texture);

        // we generate the vertices in loadObject, so this is no longer necessary
        //generateVertices(object);

		object.modelMatrix.toIdentity();
        object.scaleMatrix.toIdentity();
        object.translationMatrix.toIdentity();
        object.rotationMatrix.toIdentity();

	    //object.translationMatrix.translateSelf(0,0,-3);
        object.scaleMatrix.scaleSelf(0.2f);
        object.translationMatrix.translateSelf(0, 0, -0.8f);
        object.modelMatrix = object.translationMatrix * object.rotationMatrix * object.scaleMatrix;
        SDL_Log("object modelmatrix : %s", object.modelMatrix.toString().c_str());
	  			

        d_objects.push_back(object);    
    }
    
    for (auto &object: d_objects)
    {
        sendObjectToBuffer(object);
        sendTextureToBuffer(object);
    }
   
    
    SDL_Log("loaded %d objects.", d_objects.size());   
}