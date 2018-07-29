#include "../Headers/FieldManager.h"
#include "../../Engine/Headers/mesh.h"
#include "../../Engine/Headers/transform.h"
#include "../../Engine/Headers/noiseutils.h"
#include "noise/noise.h"
FieldManager::FieldManager(World *world) :
        Actor(world),
        mField(new Object3D(world, new Transform())),
        mFieldMesh(new Mesh(world)),
        mCurrentChunk(std::pair<int, int>(0, 0))
{
    CreateChunk(mCurrentChunk.first, mCurrentChunk.second);
}

void FieldManager::CreateChunk(int x, int y)
{
    CreateHeightMap(x,y);

}

void FieldManager::CreateHeightMap(int x, int y)
{
    noise::module::Perlin myModule;
    utils::NoiseMap heightMap;
    utils::NoiseMapBuilderPlane heightMapBuilder;
    heightMapBuilder.SetSourceModule(myModule);
    heightMapBuilder.SetDestNoiseMap(heightMap);
    heightMapBuilder.SetDestSize(CHUNK_SIZE, CHUNK_SIZE);
    heightMapBuilder.SetBounds(x * .25, x * .25 + .25, y * .25, y * .25 + .25);

    heightMapBuilder.Build();

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