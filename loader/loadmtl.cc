#include "loader.ih"

/*
    reads a Wavefront .mtl file, according to original description.
    File should should be contained within object.
    Returns: unordered map containing modelname & Material.
*/

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
    string newmtl = "newmtl";
    string Ns = "Ns";
    string Ni = "Ni";
    string d = "d";
    string Tr = "Tr";
    string Tf = "Tf";
    string illum = "illum";
    string Ka = "Ka"; // group
    string Kd = "Kd"; 
    string Ks = "Ks";
    string Ke = "Ke";
    string map_Ka = "map_Ka";
    string map_Kd = "map_Kd";

    string line;

    // need a new mtl!
    Material material();
    while (getline(file,line))
    {
    	string first_token = line.substr(0, line.find(' '));
    	// first check whether a new mtl is being created.
    		// create a new material. 
    		// after we are done processing, add it.

        if (first_token == newmtl)
        {
            
        }

    	if (first_token == Ns)
    	{
    		std::string garbage;
    		float ns_value;
    		stringstream(line) >> garbage >> ns_value;

    		continue;
    	}

        if (first_token == Tr)
        {
            string garbage;
            float transparency;
            stringstream(line) >> garbage >> transparency;
            material.opacity = 1 - transparency;
        }


    	if (first_token == Ni)
    	{

    		continue;
    	}

    	if (first_token == Ka)
    	{
            // ka spectral?
    		std::string garbage;
    		stringstream(line) >> garbage >> material.d_ambient_color.r >> material.d_ambient_color.g >> material.d_ambient_color.b;
    		ambient_color.a = 1.0f;
    		continue;
    	}

    	if (first_token == Kd)
    	{
            // also KD spectral 
            // and KD xyz.
    		std::string garbage;
    		stringstream(line) >> garbage >> material.d_diffuse_color.r >> material.d_diffuse_color.g >> material.d_diffuse_color.b;
    		material.d_diffuse_color.a = 1.0f;
    	}

        if (first_token == Ks)
        {
            std::string garbage;
            stringstream(line) >> garbage >> material.d_specular_color.r >> material.d_specular_color.g >> material.d_specular_color.b;
            material.d_specular_color.a = 1.0f;
        }

        if (first_token == Ns)
        {
            // specular exponent.
            string garbage;
            stringstream(line) >> garbage >> material.d_specular_exponent;
        }
        




    }


	return success;
}