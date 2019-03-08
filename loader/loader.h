#ifndef INCLUDED_LOADER_
#define INCLUDED_LOADER_
#include <string>
#include "../object/object.h"

class Loader
{

	public:
		static bool loadObject(std::string filename, Object &object);
		static bool loadTexture(std::string filename, Texture &texture);

	private:
		Loader() {}; // should not be able to contruct a loader.
		static bool void Loader::generateVertices(Object &object);
}