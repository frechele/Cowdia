#ifndef COWDIA_MESH_LOADER_HPP
#define COWDIA_MESH_LOADER_HPP

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
    explicit MeshLoader(std::string& path);
};
}  // namespace Cowdia::Mesh

#endif  // COWDIA_MESH_LOADER_HPP
