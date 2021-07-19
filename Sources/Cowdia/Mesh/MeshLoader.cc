<<<<<<< HEAD:Sources/Cowdia/Mesh/MeshLoader.cc
#include<string>
#include<iostream>
#include<vector>
#include<fstream>
#include<stdlib.h>
#include<Cowdia/Mesh/MeshLoader.hpp>
=======
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
>>>>>>> Mesh:Sources/Cowdia/Mesh/Mesh.cc

using namespace std;

namespace Cowdia::Mesh
{
<<<<<<< HEAD:Sources/Cowdia/Mesh/MeshLoader.cc
    MeshLoader::MeshLoader()
=======
 public:
    Mesh()
>>>>>>> Mesh:Sources/Cowdia/Mesh/Mesh.cc
    {
        //Do nothing
    }
<<<<<<< HEAD:Sources/Cowdia/Mesh/MeshLoader.cc
    MeshLoder::MeshLoader(std::string &path)
=======

    explicit Mesh(std::string path)
>>>>>>> Mesh:Sources/Cowdia/Mesh/Mesh.cc
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
<<<<<<< HEAD:Sources/Cowdia/Mesh/MeshLoader.cc
                vec2 tmpUv;
                readFile>>tmpUv.x>>tmpUv.y;
                tempUvs.push_back(tmpUv);
=======
                vec2 tmp_uv;
                readFile >> tmp_uv.x >> tmp_uv.y;
                temp_uvs.push_back(tmp_uv);
>>>>>>> Mesh:Sources/Cowdia/Mesh/Mesh.cc
            }
            else if (lineHeader.compare("vn") == 0)
            {
<<<<<<< HEAD:Sources/Cowdia/Mesh/MeshLoader.cc
                vec3 tmpNormal;
                readFile>>tmpNormal.x>>tmpNormal.y>>tmpNormal.z;
                tempNormals.push_back(tmpNormal);
=======
                vec3 tmp_normal;
                readFile >> tmp_normal.x >> tmp_normal.y >> tmp_normal.z;
                temp_normals.push_back(tmp_normal);
>>>>>>> Mesh:Sources/Cowdia/Mesh/Mesh.cc
            }
            else if (lineHeader.compare("f") == 0)
            {
                std::string vertex[3];
                readFile >> vertex[0] >> vertex[1] >> vertex[2];

                for (int i = 0; i < 3; i++)
                {
<<<<<<< HEAD:Sources/Cowdia/Mesh/MeshLoader.cc
                    unsigned int current=vertex[i].find('/');
                    if(current == string::npos)
=======
                    int current = vertex[i].find('/');
                    if (current == string::npos)
>>>>>>> Mesh:Sources/Cowdia/Mesh/Mesh.cc
                    {
                        vertexIndices.push_back(std::stoi(vertex[i]));
                        uvIndices.push_back(0);
                        normalIndices.push_back(0);
                    }
                    else
                    {
<<<<<<< HEAD:Sources/Cowdia/Mesh/MeshLoader.cc
                        unsigned int previous = 0;
                        vertexIndices.push_back(std::stoi(vertex[i].substr(previous,current-previous)));
                        previous = current+1;
=======
                        int previous = 0;
                        vertexIndices.push_back(std::stoi(
                            vertex[i].substr(previous, current - previous)));
                        previous = current + 1;
>>>>>>> Mesh:Sources/Cowdia/Mesh/Mesh.cc
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
<<<<<<< HEAD:Sources/Cowdia/Mesh/MeshLoader.cc
            vertices.push_back(tempVertices[vertexIndices[i]-1]);
=======
            vertices.push_back(temp_vertices[vertexIndices[i] - 1]);
>>>>>>> Mesh:Sources/Cowdia/Mesh/Mesh.cc
        }

        for (int i = 0; i < uvIndices.size(); i++)
        {
<<<<<<< HEAD:Sources/Cowdia/Mesh/MeshLoader.cc
            uvs.push_back(tempUvs[uvIndices[i]-1]);
=======
            uvs.push_back(temp_uvs[uvIndices[i] - 1]);
>>>>>>> Mesh:Sources/Cowdia/Mesh/Mesh.cc
        }

        for (int i = 0; i < normalIndices.size(); i++)
        {
<<<<<<< HEAD:Sources/Cowdia/Mesh/MeshLoader.cc
            normals.push_back(tempNormals[normalIndices[i]-1]);
        }
    }
=======
            normals.push_back(temp_normals[normalIndices[i] - 1]);
        }
    }

    ~Mesh()
    {
        vertices.clear();
        std::vector<vec3>().swap(vertices);
        uvs.clear();
        std::vector<vec2>().swap(uvs);
        normals.clear();
        std::vector<vec3>().swap(normals);
    }

 private:
    std::vector<vec3> vertices;
    std::vector<vec2> uvs;
    std::vector<vec3> normals;
};

int main()
{
    return 0;
>>>>>>> Mesh:Sources/Cowdia/Mesh/Mesh.cc
}

