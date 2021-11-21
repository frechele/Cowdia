#include <Cowdia/Mesh/MeshLoader.hpp>

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace Cowdia::Mesh
{
MeshLoader::MeshLoader()
{
    // Do nothing
}
MeshLoader::MeshLoader(std::string& path)
{
    std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
    std::vector<vec3> tempVertices;
    std::vector<vec2> tempUvs;
    std::vector<vec3> tempNormals;
    std::ifstream readFile;
    readFile.open(path);
    if (readFile.fail())
    {
        printf("failure to open the file !\n");
        return;
    }
    while (!readFile.eof())
    {
        std::string lineHeader;
        readFile >> lineHeader;
        if (lineHeader.compare("v") == 0)
        {
            vec3 tmpVer;
            readFile >> tmpVer.x >> tmpVer.y >> tmpVer.z;
            tempVertices.push_back(tmpVer);
        }
        else if (lineHeader.compare("vt") == 0)
        {
            vec2 tmpUv;
            readFile >> tmpUv.x >> tmpUv.y;
            tempUvs.push_back(tmpUv);
        }
        else if (lineHeader.compare("vn") == 0)
        {
            vec3 tmpNormal;
            readFile >> tmpNormal.x >> tmpNormal.y >> tmpNormal.z;
            tempNormals.push_back(tmpNormal);
        }
        else if (lineHeader.compare("f") == 0)
        {
            std::string vertex[3];
            readFile >> vertex[0] >> vertex[1] >> vertex[2];

            for (int i = 0; i < 3; i++)
            {
                unsigned int current = vertex[i].find('/');
                if (current == string::npos)
                {
                    vertexIndices.push_back(std::stoi(vertex[i]));
                    uvIndices.push_back(0);
                    normalIndices.push_back(0);
                }
                else
                {
                    unsigned int previous = 0;
                    vertexIndices.push_back(std::stoi(
                        vertex[i].substr(previous, current - previous)));
                    previous = current + 1;
                    current = vertex[i].find('/');
                    uvIndices.push_back(std::stoi(
                        vertex[i].substr(previous, current - previous)));
                    previous = current + 1;
                    current = vertex[i].find('/');
                    normalIndices.push_back(std::stoi(
                        vertex[i].substr(previous, current - previous)));
                }
            }
        }
    }

    for (int i = 0; i < vertexIndices.size(); i++)
    {
        vertices.push_back(tempVertices[vertexIndices[i] - 1]);
    }

    for (int i = 0; i < uvIndices.size(); i++)
    {
        uvs.push_back(tempUvs[uvIndices[i] - 1]);
    }

    for (int i = 0; i < normalIndices.size(); i++)
    {
        normals.push_back(tempNormals[normalIndices[i] - 1]);
    }
}
}  // namespace Cowdia::Mesh
