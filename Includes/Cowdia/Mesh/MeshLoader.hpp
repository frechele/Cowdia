#ifndef MESH_LOADER_HPP_INCLUDED
#define MESH_LOADER_HPP_INCLUDED
struct vec3
{
    float x;
    float y;
    float z;
};

struct vec2
{
    float x;
    float y;
};

namespace Cowdia::Mesh
{
class MeshLoader
{
private:
    std::vector<vec3> vertices;
    std::vector<vec2> uvs;
    std::vector<vec3> normals;

public:
    MeshLoader();
    explicit MeshLoader(std::string &path);
};
}


#endif // MESH_LOADER_HPP_INCLUDED
