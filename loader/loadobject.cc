#include "loader.ih"

/*
    loads .OBJ files. see beyond for try_catch snippet.
*/


bool Loader::loadObject(string &filename, Object &object)
{
    bool success = true;

    string prefixed_filename = "object/" + filename;
    ifstream file;
	file.open(prefixed_filename);

    if (!file)
    {
        success = false;
        SDL_Log("failed to open OBJ file %s. ", prefixed_filename.c_str());
    }
    else
    	SDL_Log("Managed to open OBJ file %s", prefixed_filename.c_str());

    // pre-match
    string hex = "#";
    string vn = "vn";
    string vt = "vt";
    string f = "f";
    string v = "v";
    string usemtl = "usemtl";
    string g = "g"; // group
    string o = "o"; // object

    //@cleanup : preallocate garbage string?
    string group;
    string line;
    while(getline(file,line))
    {
        string first_token = line.substr(0, line.find(' '));

        if (first_token == usemtl)
        {
            string mtl_file;
            string garbage;
            stringstream(line) >> garbage >> mtl_file;

            loadMTL("object/" + mtl_file);
        }

        // case #:
        if (first_token == hex) {continue;} // comments can be ignored.

        // case vn:
        if (first_token == vn)
        {
            // SDL_Log("found vn!");
            Vec3f vertex;
            string garbage;
            stringstream(line) >> garbage >> vertex.x >> vertex.y >> vertex.z;
            // SDL_Log("found vns: %f %f %f", vertex.x, vertex.y, vertex.z);
            object.rawData.normals.push_back(vertex);
            continue;
        }

        //  case vt: uv texture maps
        if (first_token == vt)
        {
            // SDL_Log("found vt!");
            Vec2f uv;
            string garbage;
            stringstream(line) >> garbage >> uv.u >> uv.v;
            object.rawData.uvs.push_back(uv);
            continue;
        }

        // case f: index description
        if (first_token == f)
        {
            int firstVertex, secondVertex, thirdVertex = 0;

            size_t slashCount = std::count(line.begin(), line.end(), '/');
            SDL_Log("slashCount: %d", slashCount);
            size_t foundSingleSlash = line.find("/");
            size_t foundDoubleSlash = line.find("//");
            string garbage; // we need to skip the character, otherwise parsing doesn't work properly.

            if (foundDoubleSlash != string::npos)
            {
                //we found a double slash. We thus do not have uv maps.
                int firstNormal, secondNormal, thirdNormal;
                std::replace( line.begin(), line.end(), '/', ' '); // replace all 'x' with 'y'
                stringstream(line) >> garbage >> firstVertex >> firstNormal
                                   >> secondVertex >> secondNormal
                                   >> thirdVertex >> thirdNormal;

                //subtract one because of indices
                firstVertex -=1;
                firstNormal -=1;
                secondVertex -=1;
                secondNormal -=1;
                thirdVertex -=1;
                thirdNormal -=1;

                // SDL_Log("found %s, %d, %d, %d", garbage.c_str(), firstVertex, secondVertex, thirdVertex);

                object.rawData.vertex_indices.push_back(firstVertex);
                object.rawData.vertex_indices.push_back(secondVertex);
                object.rawData.vertex_indices.push_back(thirdVertex);  

                object.rawData.normal_indices.push_back(firstNormal);
                object.rawData.normal_indices.push_back(secondNormal);
                object.rawData.normal_indices.push_back(thirdNormal);
            }
            else if (slashCount == 6)
            {

                int firstNormal, secondNormal, thirdNormal;
                int firstuv,     seconduv,     thirduv; 

                //necessary for parsing to happen properly
                std::replace( line.begin(), line.end(), '/', ' '); // replace all 'x' with 'y' 

                stringstream(line) >> garbage >> firstVertex >> firstuv  >> firstNormal
                                >> secondVertex >> seconduv >> secondNormal 
                                >> thirdVertex >> thirduv >> thirdNormal;
                
                //subtract one because of indices
                firstVertex -=1;
                firstNormal -=1;
                firstuv -=1;
                secondVertex -=1;
                secondNormal -=1;
                seconduv -=1;
                thirdVertex -=1;
                thirdNormal -=1;
                thirduv -=1;

                object.rawData.vertex_indices.push_back(firstVertex);
                object.rawData.vertex_indices.push_back(secondVertex);
                object.rawData.vertex_indices.push_back(thirdVertex);  
                object.rawData.uv_indices.push_back(firstuv);
                object.rawData.uv_indices.push_back(seconduv);
                object.rawData.uv_indices.push_back(thirduv);

                object.rawData.normal_indices.push_back(firstNormal);
                object.rawData.normal_indices.push_back(secondNormal);
                object.rawData.normal_indices.push_back(thirdNormal);
            }
            else if (slashCount == 3)
            {
                SDL_Log("single slash slinging slasher");
            }
            else if (slashCount == 0)
            {
                // only vertices
                stringstream(line) >> garbage >> firstVertex >> secondVertex >> thirdVertex;
                //subtract one because of indices
                firstVertex -=1;
                secondVertex -=1;
                thirdVertex -=1;
                object.rawData.vertex_indices.push_back(firstVertex);
                object.rawData.vertex_indices.push_back(secondVertex);
                object.rawData.vertex_indices.push_back(thirdVertex);  
                // SDL_Log("found %s, %d, %d, %d", garbage.c_str(), firstVertex, secondVertex, thirdVertex);
            }
        }   

        // vertices.
        if (first_token == v)
        {
            // SDL_Log("found v!");
            Vec3f vertex;
            string garbage;
            stringstream(line) >> garbage >> vertex.x >> vertex.y >> vertex.z;
            object.rawData.vertices.push_back(vertex);
            continue;
        }


        if (first_token == g)
        {
            std::string garbage;
            stringstream(line) >> garbage  >> group_name;
            SDL_Log("new group: %s", group_name);
        }
    }
    file.close();
    generateVertices(object);

    return success;
}


    // file.open(prefixed_filename);
    // ifstream file(prefixed_filename);

    // file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    //    std::stringstream sos;
    // try {
    //     file.open(prefixed_filename);
    // } catch (std::system_error& e) {
    //     sos << e.code().message() << std::endl;
    //     string test = sos.str();
    //     SDL_Log("caught %s", test.c_str());
    // }
    