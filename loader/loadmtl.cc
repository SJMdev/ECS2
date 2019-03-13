#include "loader.ih"


// return a map 

unordered_map<std::string modelName, Material> Loader::loadMTL(std::string &filename)
{
	bool success = true;
    string prefixed_filename = "object/" + filename;
    ifstream file;
	file.open(prefixed_filename);

    if (!file)
    {
        success = false;
        SDL_Log("failed to open MTL file %s. ", prefixed_filename.c_str());
    }
    else
    	SDL_Log("Managed to open MTL file %s", prefixed_filename.c_str());

     // pre-match
    //TODO: make this a map.
    string Ns = "Ns";
    string Ni = "Ni";
    string d = "d";
    string Tr = "Tr";
    string Tf = "v";
    string illum = "illum";
    string Ka = "Ka"; // group
    string Kd = "Kd"; 
    string Ks = "Ks";
    string Ke = "Ke";
    string map_Ka = "map_Ka";
    string map_Kd = "map_Kd";

    string line;

    // need a new mtl!
    while (getline(file,line))
    {
    	string first_token = line.substr(0, line.find(' '));

    	if (first_token == Ns)
    	{

    		std::string garbage;
    		float ns_value;
    		stringstream(line) >> garbage >> ns_value;



    		continue;
    	}

    	if (first_token == Ni)
    	{

    		continue;
    	}

    	if (first_token == Ka)
    	{
    		std::string garbage;
			Color ambient_color;
    		stringstream(line) >> garbage >> ambient_color.r >> ambient_color.g >> ambient_color.b;
    		
    		continue;
    	}





    }


	return success;
}