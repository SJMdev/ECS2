// #include "window.ih"

// bool Window::loadOBJFromFile(std::string &filename, Object &object)
// {
//     bool success = true;
//     ifstream file;

//     file.open("objects/" + filename);

//     if (file.bad())
//     {
//         success = false;
//         SDL_Log("failed to load OBJ file %s. ", filename.c_str());
//     }

//     string hex = "#";
//     string vn = "vn";
//     string vt = "vt";
//     string f = "f";
//     string v = "v";

//     //@cleanup : preallocate garbage string?
//     std::string line;
//     while (getline(file,line))
//     {
//         string first_token = line.substr(0, line.find(' '));

//         // case HEX
//         if (first_token == hex) {} // comments can be ignored.


//         // vertex normals.
//         if (first_token == vn)
//         {
//             // SDL_Log("found vn!");
//             Vec3f vertex;
//             string garbage;
//             stringstream(line) >> garbage >> vertex.x >> vertex.y >> vertex.z;
//             // SDL_Log("found vns: %f %f %f", vertex.x, vertex.y, vertex.z);
//             object.rawData.normals.push_back(vertex);
//             continue;
//         }

//         // uv texture maps
//         if (first_token == vt)
//         {
//             // SDL_Log("found vt!");
//             Vec2f uv;
//             string garbage;
//             stringstream(line) >> garbage >> uv.u >> uv.v;
//             object.rawData.uvs.push_back(uv);
//             continue;
//         }

//         //@Todo: fix reading in without normals with UV textures
//         if (first_token == f)
//         {
//             int firstVertex, secondVertex, thirdVertex = 0;
            
//             size_t foundSingleSlash = line.find("/");
//             size_t foundDoubleSlash = line.find("//");
//             string garbage; // we need to skip the character, otherwise parsing doesn't work properly.

//             if (foundDoubleSlash != string::npos)
//             {
//                 //we found a double slash. We thus do not have uv maps.
//                 int firstNormal, secondNormal, thirdNormal;
//                 std::replace( line.begin(), line.end(), '/', ' '); // replace all 'x' with 'y'
//                 stringstream(line) >> garbage >> firstVertex >> firstNormal
//                                    >> secondVertex >> secondNormal
//                                    >> thirdVertex >> thirdNormal;
//                 firstVertex -=1;
//                 firstNormal -=1;
//                 secondVertex -=1;
//                 secondNormal -=1;
//                 thirdVertex -=1;
//                 thirdNormal -=1;

//                 // SDL_Log("found %s, %d, %d, %d", garbage.c_str(), firstVertex, secondVertex, thirdVertex);

//                 object.rawData.vertex_indices.push_back(firstVertex);
//                 object.rawData.vertex_indices.push_back(secondVertex);
//                 object.rawData.vertex_indices.push_back(thirdVertex);  

//                 object.rawData.normal_indices.push_back(firstNormal);
//                 object.rawData.normal_indices.push_back(secondNormal);
//                 object.rawData.normal_indices.push_back(thirdNormal);
//             }
//             else if (foundSingleSlash != string::npos)
//             {

//                 int firstNormal, secondNormal, thirdNormal;
//                 int firstuv,     seconduv,     thirduv; 

//                 //necessary for parsing to happen properly
//                 std::replace( line.begin(), line.end(), '/', ' '); // replace all 'x' with 'y' 

//                 stringstream(line) >> garbage >> firstVertex >> firstuv  >> firstNormal
//                                 >> secondVertex >> seconduv >> secondNormal 
//                                 >> thirdVertex >> thirduv >> thirdNormal;
//                 firstVertex -=1;
//                 firstNormal -=1;
//                 firstuv -=1;
//                 secondVertex -=1;
//                 secondNormal -=1;
//                 seconduv -=1;
//                 thirdVertex -=1;
//                 thirdNormal -=1;
//                 thirduv -=1;

//                 object.rawData.vertex_indices.push_back(firstVertex);
//                 object.rawData.vertex_indices.push_back(secondVertex);
//                 object.rawData.vertex_indices.push_back(thirdVertex);  
//                 //how does this look?
//                 // SDL_Log("found vector %s, %d, %d, %d", garbage.c_str(), firstVertex, secondVertex, thirdVertex);
//                 // SDL_Log("found normals %d, %d, %d", firstNormal, secondNormal, thirdNormal);
//                 object.rawData.uv_indices.push_back(firstuv);
//                 object.rawData.uv_indices.push_back(seconduv);
//                 object.rawData.uv_indices.push_back(thirduv);

//                 object.rawData.normal_indices.push_back(firstNormal);
//                 object.rawData.normal_indices.push_back(secondNormal);
//                 object.rawData.normal_indices.push_back(thirdNormal);
//             }
//             else
//             {
//                 stringstream(line) >> garbage >> firstVertex >> secondVertex >> thirdVertex;
//                 firstVertex -=1;
//                 secondVertex -=1;
//                 thirdVertex -=1;
//                 object.rawData.vertex_indices.push_back(firstVertex);
//                 object.rawData.vertex_indices.push_back(secondVertex);
//                 object.rawData.vertex_indices.push_back(thirdVertex);  
//                 // SDL_Log("found %s, %d, %d, %d", garbage.c_str(), firstVertex, secondVertex, thirdVertex);
//             }
//         }   

//         // vertices.
//         if (first_token == v)
//         {
//             // SDL_Log("found v!");
//             Vec3f vertex;
//             string garbage;
//             stringstream(line) >> garbage >> vertex.x >> vertex.y >> vertex.z;
//             object.rawData.vertices.push_back(vertex);
//             continue;
//         }

//     }

//     return success;
// }