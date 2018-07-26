cmake_minimum_required(VERSION 3.10)
project(Voxel3_CLION)

set(CMAKE_CXX_STANDARD 11)

add_executable(Voxel3_CLION Engine/Sources/main.cpp Engine/Sources/actor.cpp Engine/Headers/actor.h Engine/Sources/mesh.cpp Engine/Headers/mesh.h Engine/Sources/object3d.cpp Engine/Headers/object3d.h Engine/Sources/transform.cpp Engine/Headers/transform.h Engine/Sources/window.cpp Engine/Headers/window.h Engine/Sources/world.cpp Engine/Headers/world.h Engine/Sources/glad.c Geometry/Sources/Field.cpp Geometry/Headers/Field.h Engine/Sources/Camera.cpp Engine/Headers/Camera.h Engine/Sources/Renderer.cpp Engine/Headers/Renderer.h)

include_directories(include)

target_link_libraries(Voxel3_CLION -lglfw3 -lGL -lm -ldl -lXinerama -lXrandr -lXi -lXcursor -lX11 -lXxf86vm -lpthread -lnoise)