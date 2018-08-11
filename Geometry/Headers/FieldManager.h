#ifndef VOXEL3_CLION_FIELDMANAGER_H
#define VOXEL3_CLION_FIELDMANAGER_H

#include "../../Engine/Headers/actor.h"
#include "../../Engine/Headers/object3d.h"
#include "../../Engine/Headers/noiseutils.h"
#include "noise/noise.h"
#include <utility>
#include <unordered_map>
#include <boost/functional/hash.hpp>
#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/hash.hpp>
#include <thread>
#include <atomic>

struct Cube{
    static constexpr int BLOCK_SIZE = 1;
    std::bitset<6> faces = 0; /**< (X, -X, Y, -Y, Z, -Z)*/
};

class FieldManager : public Actor{
public:
    FieldManager(){}
    ~FieldManager();
    FieldManager(World *world);
    void CreateChunk(int x, int y);
    virtual void Tick(float delta) override;

private:
    utils::NoiseMap CreateHeightMap(int x, int y);
    void CreateCube(int xCoord, int yCoord, int zCoord, std::vector<float>&);
    void DeleteOutOfBoundsChunks(int x, int z);

    static constexpr int CHUNK_DISTANCE = 6;
    static constexpr int CHUNK_SIZE = 32;

    std::thread mChunkLoader; /**< Chunks should be created outside of the main thread*/
    std::atomic_bool mChunkLoaderIsRunning {false};

    glm::vec3 mLastCameraLocation; /**< Location of active camera if it changed this frame*/
    glm::vec3 mLastCameraForward; /**< Forward of active camera if it changed this frame*/
    Mesh* mField; /**< Mesh object of all chunks*/
    std::unordered_map<std::pair<int,int>, std::vector<float>,boost::hash<std::pair<int,int>>> mCurrentChunks; /**< Key is world chunk coordinate and value is chunk vertices*/
    std::unordered_map<glm::vec3, Cube > mCubes;/**< Key is world cube coordinate and value is corresponding cube*/
    void UpdateChunks();
};

#endif //VOXEL3_CLION_FIELDMANAGER_H
