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

    char c;
    while (file)
    {

        
        file >> c;
        if (file.eof())
            break;
        // SDL_Log("found %c",c);
        switch(c)
        {
            case 'v': {
                        Vec3f vertex;
                        file >> vertex.x >> vertex.y >> vertex.z;
                        // SDL_Log("vertex: %f, %f,%f",vertex.x,vertex.y,vertex.z);
                        model.vertices.push_back(vertex);
                        break;
                    }
            case 'f': { Vec3f face;
                        file >> face.x >> face.y >> face.z;
                        // SDL_Log("face: %f, %f,%f", face.x, face.y, face.z);
                        model.faces.push_back(face);
                        break;
                    }
            default:
                // SDL_Log("default switch case. found %c",c);
                file.ignore(256, '\n');
                break;
        }
    }




    return success;
}