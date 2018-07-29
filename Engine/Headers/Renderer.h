#ifndef VOXEL3_CLION_RENDERER_H
#define VOXEL3_CLION_RENDERER_H
#include <vector>
class Mesh;

class Renderer {

public:
    Renderer(){};
    /**
     * Calls every mesh's draw function in the world
     */
    void DrawAll();
    /**
     * Add passed in mesh to mDrawable
     * @param mesh The mesh to be added.
     */
    void AddMesh(Mesh *mesh);



private:
    std::vector<Mesh*> mDrawable;/**< All Meshes automatically added this this vector to be drawn.*/


};


#endif //VOXEL3_CLION_RENDERER_H
