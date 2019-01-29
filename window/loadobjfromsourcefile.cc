#include "window.ih"

bool Window::loadOBJFromSourceFile(std::string &filename, Model &model)
{
    bool success = true;
    ifstream file;

    file.open("models/" + filename);

    if (file.bad())
    {
        success = false;
        SDL_Log("failed to load OBJ file %s. ", filename.c_str());
    }

    string hex = "#";
    string vn = "vn";
    string vt = "vt";
    string f = "f";
    string v = "v";

    //@cleanup : preallocate garbage string?
    std::string line;
    while (getline(file,line))
    {
        string first_token = line.substr(0, line.find(' '));

        // case HEX
        if (first_token == hex) {} // comments can be ignored.


        // vertex normals.
        if (first_token == vn)
        {
            // SDL_Log("found vn!");
            Vec3f vertex;
            string garbage;
            stringstream(line) >> garbage >> vertex.x >> vertex.y >> vertex.z;
            // SDL_Log("found vns: %f %f %f", vertex.x, vertex.y, vertex.z);
            model.normals.push_back(vertex);
            continue;
        }

        //
        if (first_token == vt)
        {
            SDL_Log("found vt!");
            Vec2f uv;
            string garbage;
            stringstream(line) >> garbage >> uv.u >> uv.v;
            model.uvs.push_back(uv);
            continue;
        }

        //@Todo: fix reading in without normals with UV textures
        if (first_token == f)
        {
            int firstVertex, secondVertex, thirdVertex = 0;
            
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
                firstVertex -=1;
                firstNormal -=1;
                secondVertex -=1;
                secondNormal -=1;
                thirdVertex -=1;
                thirdNormal -=1;

                SDL_Log("found %s, %d, %d, %d", garbage.c_str(), firstVertex, secondVertex, thirdVertex);

                model.vertex_indices.push_back(firstVertex);
                model.vertex_indices.push_back(secondVertex);
                model.vertex_indices.push_back(thirdVertex);  

                model.normal_indices.push_back(firstNormal);
                model.normal_indices.push_back(secondNormal);
                model.normal_indices.push_back(thirdNormal);
            }
            else if (foundSingleSlash != string::npos)
            {

                int firstNormal, secondNormal, thirdNormal;
                int firstuv,     seconduv,     thirduv; 

                //necessary for parsing to happen properly
                std::replace( line.begin(), line.end(), '/', ' '); // replace all 'x' with 'y' 

                stringstream(line) >> garbage >> firstVertex >> firstuv  >> firstNormal
                                >> secondVertex >> seconduv >> secondNormal 
                                >> thirdVertex >> thirduv >> thirdNormal;
                firstVertex -=1;
                firstNormal -=1;
                firstuv -=1;
                secondVertex -=1;
                secondNormal -=1;
                seconduv -=1;
                thirdVertex -=1;
                thirdNormal -=1;
                thirduv -=1;

                model.vertex_indices.push_back(firstVertex);
                model.vertex_indices.push_back(secondVertex);
                model.vertex_indices.push_back(thirdVertex);  
                //how does this look?
                SDL_Log("found vector %s, %d, %d, %d", garbage.c_str(), firstVertex, secondVertex, thirdVertex);
                SDL_Log("found normals %d, %d, %d", firstNormal, secondNormal, thirdNormal);

                model.normal_indices.push_back(firstNormal);
                model.normal_indices.push_back(secondNormal);
                model.normal_indices.push_back(thirdNormal);
            }
            else
            {
                stringstream(line) >> garbage >> firstVertex >> secondVertex >> thirdVertex;
                firstVertex -=1;
                secondVertex -=1;
                thirdVertex -=1;
                model.vertex_indices.push_back(firstVertex);
                model.vertex_indices.push_back(secondVertex);
                model.vertex_indices.push_back(thirdVertex);  
                SDL_Log("found %s, %d, %d, %d", garbage.c_str(), firstVertex, secondVertex, thirdVertex);
            }
        }   

        if (first_token == v)
        {
            // SDL_Log("found v!");
            Vec3f vertex;
            string garbage;
            stringstream(line) >> garbage >> vertex.x >> vertex.y >> vertex.z;
            model.vertices.push_back(vertex);
            continue;
        }

    }




    return success;
}