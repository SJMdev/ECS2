#include "window.ih"

bool Window::loadOBJFromSourceFile(std::string &filename, Model &model)
{
    bool success = true;
    ifstream file;

    file.open("models/" + filename);

    if (file.bad())
    {
        success = false;
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

        if (first_token == hex)
            SDL_Log("found hex!");

        if (first_token == vn)
        {
            SDL_Log("found vn!");
            Vec3f vertex;
            string garbage;
            stringstream(line) >> garbage >> vertex.x >> vertex.y >> vertex.z;
            SDL_Log("found vns: %f %f %f", vertex.x, vertex.y, vertex.z);
            model.normals.push_back(vertex);
            continue;
        }

        
        if (first_token == vt)
        {
            SDL_Log("found vt!");
            Vec2f uv;
            string garbage;
            stringstream(line) >> garbage >> uv.u >> uv.v;
            model.uvs.push_back(uv);
            continue;
        }

        
        if (first_token == f)
        {
            int firstVertex, secondVertex, thirdVertex = 0;
            size_t found = line.find("/");
            string garbage; // we need to skip the character, otherwise parsing doesn't work properly.
            if (found != string::npos)
            {

                int firstNormal, secondNormal, thirdNormal;
                int firstuv,     seconduv,     thirduv; 

                //necessary for parsing to happen properly
                std::replace( line.begin(), line.end(), '/', ' '); // replace all 'x' to 'y' 

               
                stringstream(line) >> garbage >> firstVertex >> firstNormal >> firstuv 
                                >> secondVertex >> secondNormal >>seconduv
                                >> thirdVertex >> thirdNormal >> thirduv;
                firstVertex -=1;
                firstNormal -=1;
                firstuv -=1;
                secondVertex -=1;
                secondNormal -=1;
                seconduv -=1;
                thirdVertex -=1;
                thirdNormal -=1;
                thirduv -=1;


                SDL_Log("found %s, %d, %d, %d", garbage.c_str(), firstVertex, secondVertex, thirdVertex);
                model.indices.push_back(firstVertex);
                model.indices.push_back(secondVertex);
                model.indices.push_back(thirdVertex);
            }
            else
            {
                stringstream(line) >> garbage >> firstVertex >> secondVertex >> thirdVertex;
                firstVertex -=1;
                secondVertex -=1;
                thirdVertex -=1;
                model.indices.push_back(firstVertex);
                model.indices.push_back(secondVertex);
                model.indices.push_back(thirdVertex);
                SDL_Log("found %s, %d, %d, %d", garbage.c_str(), firstVertex, secondVertex, thirdVertex);
            }
        }   

        if (first_token == v)
        {
            SDL_Log("found v!");
            Vec3f vertex;
            string garbage;
            stringstream(line) >> garbage >> vertex.x >> vertex.y >> vertex.z;
            model.vertices.push_back(vertex);
            continue;
        }

    }




    return success;
}