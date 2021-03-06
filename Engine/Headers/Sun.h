//
// Created by nathan on 8/4/18.
//

#ifndef VOXEL3_CLION_SUN_H
#define VOXEL3_CLION_SUN_H
#include "mesh.h"
#include <vector>
class World;

class Sun: public Mesh{
public:
    Sun(World*);
    virtual ~Sun();
    virtual void Tick(float delta) override;

private:
    std::vector<float> mVertices{
        //0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 1.f, 1.f, 0.f, //z
        //0.f, 0.f, 0.f, 0.f, 1.f, 0.f, 1.f, 1.f, 0.f,
        //1.f, 0.f, 0.f, 1.f, 1.f, 0.f, 1.f, 1.f, 1.f, //x
        //1.f, 0.f, 0.f, 1.f, 0.f, 1.f, 1.f, 1.f, 1.f,
        0.f, 0.f, 0.f, 0.f, -1.f, 0.f,
        1.f, 0.f, 0.f, 0.f, -1.f, 0.f,
        1.f, 0.f, 1.f, 0.f, -1.f, 0.f,
        0.f, 0.f, 0.f, 0.f, -1.f, 0.f,
        0.f, 0.f, 1.f, 0.f, -1.f, 0.f,
        1.f, 0.f, 1.f, 0.f, -1.f, 0.f
    };
};


#endif //VOXEL3_CLION_SUN_H
