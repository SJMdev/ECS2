#ifndef INCLUDED_LOADER_
#define INCLUDED_LOADER_
#include <string>
#include "../object/object.h"

#include <unordered_map>

struct Material {};

class Loader
{

	public:
		static unordered_map<std::string modelName, Material> loadMTL(std::string &filename);
		static bool loadObject(std::string &filename, Object &object);
		static bool loadTexture(std::string &filename, Texture &texture);
		static bool loadPNG(std::vector<unsigned char>& buffer, const std::string& filename); //designed for loading files from hard disk in an std::vector
 

	private:
		Loader() {}; // should not be able to contruct a loader.
		static bool Loader::generateVertices(Object &object);

		static int decodePNG(std::vector<unsigned char>& out_image, unsigned long& image_width, unsigned long& image_height, const unsigned char* in_png, size_t in_size, bool convert_to_rgba32);
};


#endif