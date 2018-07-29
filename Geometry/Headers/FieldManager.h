#ifndef VOXEL3_CLION_FIELDMANAGER_H
#define VOXEL3_CLION_FIELDMANAGER_H

#include "../../Engine/Headers/actor.h"
#include "../../Engine/Headers/object3d.h"
#include <utility>

class FieldManager : public Actor{
public:
    FieldManager(){}
    FieldManager(World *world);
    void CreateChunk(int x, int y);


private:
    void CreateHeightMap(int x, int y);

    static constexpr unsigned int CHUNK_SIZE = 32;
    Object3D* mField;
    Mesh* mFieldMesh;
    std::pair<int, int>mCurrentChunk;
    std::vector<int> mVertices;
};


#endif //VOXEL3_CLION_FIELDMANAGER_H
