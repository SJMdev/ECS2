#ifndef INCLUDED_SCENE_
#define INCLUDED_SCENE_
#include "../camera/light.h"
#include "../shared/objectfilepaths.h"
#include "../shared/model.h"
#include "../shared/texture.h"
#include "../object/object.h"
#include <vector>

// #include "../object/object.h"

class Scene
{
	Light d_light;
	std::vector<Object> d_objects;

	public:
		Scene();
		initializeLight(Light &light);
		void initializeObjects(std::vector<ObjectFilePaths>  &objectFilePaths);




};


#endif