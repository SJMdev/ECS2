#include "window.ih"

// void Window::calculateNormals(Model &model)
// {
//     for all points
//     for (int idx = 0; idx != model.vertices.size(); ++idx)
//     {
//         // find the set of triangles where I participate in
//         Vec3f normal = Vec3f{ 0, 0, 0};
//         for( auto &face : model.faces)
//         {
//             int index = idx + 1;
//             if (index == face.x || index == face.y || index == face.z)
//             {
//                 Vec3f U = model.vertices.at(face.y -1) - model.vertices.at(face.x -1);
//                 Vec3f V = model.vertices.at(face.z -1) - model.vertices.at(face.x -1 );
//                 normal.x += U.y * U.z - U.z * V.y;
//                 normal.y += U.z * V.x - U.x * V.z;
//                 normal.z += U.x * V.y - U.y * V.x;
//             }
//         }
//             float sum = normal.x + normal.y + normal.z;
//             normal.x /= sum;
//             normal.y /= sum;
//             normal.z /= sum;

//             model.normals.push_back(normal);
//     }



// }