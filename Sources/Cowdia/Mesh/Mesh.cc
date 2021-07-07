#include<string>
#include<iostream>
#include<vector>
#include<fstream>
#include<stdlib.h>

using namespace std;
typedef struct
{
    float x;
    float y;
    float z;
} vec3;

typedef struct
{
    float x;
    float y;
} vec2;

class Mesh
{
private:
    std::vector<vec3> vertices;
    std::vector<vec2> uvs;
    std::vector<vec3> normals;



public:
    Mesh(char* path)
    {
        std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
        std::vector<vec3> temp_vertices;
        std::vector<vec2> temp_uvs;
        std::vector<vec3> temp_normals;
        std::ifstream readFile;
        readFile.open(path);
        if (readFile.fail())
        {
            printf("failure to open the file !\n");
            return ;
        }

        while (!readFile.eof())
        {
            std::string lineHeader;
            readFile >> lineHeader;
            if (lineHeader.compare("v")==0)
            {
                vec3 tmp_ver;
                readFile >> tmp_ver.x >> tmp_ver.y >> tmp_ver.z;
                temp_vertices.push_back(tmp_ver);
            }
            else if(lineHeader.compare("vt")==0)
            {
                vec2 tmp_uv;
                readFile>>tmp_uv.x>>tmp_uv.y;
                temp_uvs.push_back(tmp_uv);
            }
            else if(lineHeader.compare("vn")==0)
            {
                vec3 tmp_normal;
                readFile>>tmp_normal.x>>tmp_normal.y>>tmp_normal.z;
                temp_normals.push_back(tmp_normal);
            }
            else if(lineHeader.compare("f")==0)
            {
                std::string vertex[3];
                readFile>>vertex[0]>>vertex[1]>>vertex[2];
                for(int i = 0; i<3; i++)
                {
                    int previous = 0;
                    int current=vertex[i].find('/');
                    if(current == string::npos)
                    {
                        vertexIndices.push_back(std::stoi(vertex[i]));
                        uvIndices.push_back(0);
                        normalIndices.push_back(0);
                    }
                    else
                    {
                        vertexIndices.push_back(std::stoi(vertex[i].substr(previous,current-previous)));
                        previous = current+1;
                        current = vertex[i].find('/');
                        uvIndices.push_back(std::stoi(vertex[i].substr(previous,current-previous)));
                        previous = current+1;
                        current = vertex[i].find('/');
                        normalIndices.push_back(std::stoi(vertex[i].substr(previous,current-previous)));
                    }
                }

            }
        }
        for(int i = 0; i<vertexIndices.size();i++)
        {
            vertices.push_back(temp_vertices[vertexIndices[i]-1]);
        }
        for(int i = 0; i<uvIndices.size();i++)
        {
            uvs.push_back(temp_uvs[uvIndices[i]-1]);
        }
        for(int i = 0; i<normalIndices.size();i++)
        {
            normals.push_back(temp_normals[normalIndices[i]-1]);
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

};

int main()
{
    return 0;
}
