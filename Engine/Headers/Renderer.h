#ifndef VOXEL3_CLION_RENDERER_H
#define VOXEL3_CLION_RENDERER_H
#include <vector>
class Mesh;

class Renderer {

public:
    Renderer(){};
    void DrawAll();
    void AddMesh(Mesh *mesh);



private:
    std::vector<Mesh*> mDrawable;

};


#endif //VOXEL3_CLION_RENDERER_H
