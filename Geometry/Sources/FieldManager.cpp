#include "../Headers/FieldManager.h"
#include "../../Engine/Headers/mesh.h"
#include "../../Engine/Headers/transform.h"
#include "../../Engine/Headers/world.h"
#include "../../Engine/Headers/Camera.h"



void push_vec3(std::vector<float>&, glm::vec3&);
bool vec3_equals(glm::vec3, glm::vec3);
FieldManager::FieldManager(World *world) :
        Actor(world),
        mField(new Mesh(world)),
        mAllVertices(new std::vector<float>)
{
}

FieldManager::~FieldManager()
{
    delete mAllVertices;
}

void FieldManager::Tick(float delta)
{
//    if(!mChunkLoaderIsRunning)
//    {
//        mChunkLoaderIsRunning = true;
//        //mChunkLoader = std::thread(&FieldManager::UpdateChunks, this);
//        UpdateChunks();
//    }
    UpdateChunks();
}

void FieldManager::UpdateChunks() {
    glm::vec3 camLocation = GetWorld()->GetActiveCamera()->GetTransform()->GetLocation();
    glm::vec3 camForward = GetWorld()->GetActiveCamera()->GetTransform()->GetForward();
    if (vec3_equals(camLocation, mLastCameraLocation) && vec3_equals(camForward, mLastCameraForward))
    {
        mChunkLoaderIsRunning = false;
        return;
    }
    mLastCameraForward = camForward;
    mLastCameraLocation = camLocation;
    int xOffset = (int)(camLocation.x/32.0);
    int zOffset = (int)(camLocation.z/32.0);
    DeleteOutOfBoundsChunks(xOffset, zOffset);

    for (int i = 0 - CHUNK_DISTANCE/2; i < CHUNK_DISTANCE/2 + 1; i++)
    {
        for (int j = 0 - CHUNK_DISTANCE/2; j < CHUNK_DISTANCE/2 + 1; j++)
        {
            if (mCurrentChunks.find(std::pair<int,int>(xOffset + j, zOffset + i)) == mCurrentChunks.end())
            {
                CreateChunk(xOffset + j, zOffset + i);
            }
        }
    }

    mAllVertices->clear();
    for (auto k: mCurrentChunks)
    {
        mAllVertices->insert(mAllVertices->end(), k.second.begin(), k.second.end());
    }
    mField->SetVertices(mAllVertices);
    mChunkLoaderIsRunning = false;

}

void FieldManager::CreateChunk(int xOffset, int zOffset)
{
    utils::NoiseMap heightMap = CreateHeightMap(xOffset, zOffset);
    std::vector<float> vertices;

    for (int z = 0; z < CHUNK_SIZE; z++)
    {
        for (int x = 0; x < CHUNK_SIZE; x++)
        {
            int xCoord = xOffset * CHUNK_SIZE + x;
            int zCoord = zOffset * CHUNK_SIZE + z;
            int yCoord = heightMap.GetValue(x, z) * CHUNK_SIZE;
            CreateCube(xCoord, yCoord, zCoord, vertices);
        }
    }
    mCurrentChunks[std::pair<int,int>(xOffset,zOffset)] = vertices;

}



void FieldManager::CreateCube(float xCoord, float yCoord, float zCoord, std::vector<float>& vertices)
{
    glm::vec3 v0 = glm::vec3(xCoord + BLOCK_SIZE, yCoord + BLOCK_SIZE, zCoord + BLOCK_SIZE); // 1, 1, 1
    glm::vec3 v1 = glm::vec3(xCoord + BLOCK_SIZE, yCoord + BLOCK_SIZE, zCoord - BLOCK_SIZE); // 1, 1, 0
    glm::vec3 v2 = glm::vec3(xCoord + BLOCK_SIZE, yCoord - BLOCK_SIZE, zCoord + BLOCK_SIZE); // 1, 0, 1
    glm::vec3 v3 = glm::vec3(xCoord + BLOCK_SIZE, yCoord - BLOCK_SIZE, zCoord - BLOCK_SIZE); // 1, 0, 0
    glm::vec3 v4 = glm::vec3(xCoord - BLOCK_SIZE, yCoord + BLOCK_SIZE, zCoord + BLOCK_SIZE); // 0, 1, 1
    glm::vec3 v5 = glm::vec3(xCoord - BLOCK_SIZE, yCoord + BLOCK_SIZE, zCoord - BLOCK_SIZE); // 0, 1, 0
    glm::vec3 v6 = glm::vec3(xCoord - BLOCK_SIZE, yCoord - BLOCK_SIZE, zCoord + BLOCK_SIZE); // 0, 0, 1
    glm::vec3 v7 = glm::vec3(xCoord - BLOCK_SIZE, yCoord - BLOCK_SIZE, zCoord - BLOCK_SIZE); // 0, 0, 0



    // -Z
    push_vec3(vertices, v7);
    push_vec3(vertices, v3);
    push_vec3(vertices, v5);

    push_vec3(vertices, v3);
    push_vec3(vertices, v1);
    push_vec3(vertices, v5);

    // +X
    push_vec3(vertices, v3);
    push_vec3(vertices, v1);
    push_vec3(vertices, v0);

    push_vec3(vertices, v0);
    push_vec3(vertices, v2);
    push_vec3(vertices, v3);

    // +Z
    push_vec3(vertices, v2);
    push_vec3(vertices, v0);
    push_vec3(vertices, v4);

    push_vec3(vertices, v4);
    push_vec3(vertices, v6);
    push_vec3(vertices, v2);

    // -X
    push_vec3(vertices, v7);
    push_vec3(vertices, v5);
    push_vec3(vertices, v4);

    push_vec3(vertices, v4);
    push_vec3(vertices, v6);
    push_vec3(vertices, v7);

    // +Y
    push_vec3(vertices, v5);
    push_vec3(vertices, v1);

    push_vec3(vertices, v0);

    push_vec3(vertices, v0);
    push_vec3(vertices, v4);
    push_vec3(vertices, v5);

/*
    // -Y
    push_vec3(vertices, v7);
    push_vec3(vertices, v3);
    push_vec3(vertices, v2);

    push_vec3(vertices, v2);
    push_vec3(vertices, v6);
    push_vec3(vertices, v7);
*/
}

utils::NoiseMap FieldManager::CreateHeightMap(int xOffset, int zOffset)
{
    noise::module::Perlin myModule;
    utils::NoiseMap heightMap;
    utils::NoiseMapBuilderPlane heightMapBuilder;

    heightMapBuilder.SetSourceModule(myModule);
    heightMapBuilder.SetDestNoiseMap(heightMap);
    heightMapBuilder.SetDestSize(CHUNK_SIZE, CHUNK_SIZE);
    heightMapBuilder.SetBounds(xOffset * .25, xOffset * .25 + .25, zOffset * .25, zOffset * .25 + .25);
    heightMapBuilder.Build();

    return heightMap;

    /*
    //WRITE TO FILE
    utils::RendererImage renderer;
    utils::Image image;
    renderer.SetSourceNoiseMap(heightMap);
    renderer.SetDestImage(image);
    renderer.Render();

    utils::WriterBMP writer;
    writer.SetSourceImage(image);
    writer.SetDestFilename("m_<" + std::to_string(x)+ "," + std::to_string(y)+">.png");
    writer.WriteDestFile();
    */
}

void FieldManager::DeleteOutOfBoundsChunks(int x, int z)
{
    std::unordered_map<std::pair<int, int>,bool,boost::hash<std::pair<int,int>>> oldChunks;
    for(auto k : mCurrentChunks)
    {
        oldChunks[k.first] = true;
    }

    for (int i = 0 - CHUNK_DISTANCE/2; i < CHUNK_DISTANCE/2 + 1; i++)
    {
        for (int j = 0 - CHUNK_DISTANCE/2; j < CHUNK_DISTANCE/2 + 1; j++)
        {
            if (oldChunks.find(std::pair<int, int>(x+j,z+i))!=oldChunks.end())
            {
                oldChunks[std::pair<int, int>(x+j,z+i)] = false;
            }
        }
    }

    for(auto k : oldChunks)
    {
        if (k.second)
        {
            printf("removing chunk (%d, %d)\n",k.first.first, k.first.second);
            mCurrentChunks.erase(k.first);
        }
    }
}

void push_vec3(std::vector<float>& mV, glm::vec3& v)
{
    mV.push_back(v.x);
    mV.push_back(v.y);
    mV.push_back(v.z);
}
bool vec3_equals(glm::vec3 a, glm::vec3 b)
{
    const float EPSILON = .0001;
    return (abs(a.x - b.x) < EPSILON || abs(a.y - b.y) < EPSILON || abs(a.z - b.z) < EPSILON);
}
