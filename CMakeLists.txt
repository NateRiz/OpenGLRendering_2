cmake_minimum_required(VERSION 3.10)
project(Voxel3_CLION)

set(CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(Voxel3_CLION Engine/Sources/main.cpp Engine/Sources/actor.cpp Engine/Headers/actor.h Engine/Sources/mesh.cpp Engine/Headers/mesh.h Engine/Sources/object3d.cpp Engine/Headers/object3d.h Engine/Sources/transform.cpp Engine/Headers/transform.h Engine/Sources/window.cpp Engine/Headers/window.h Engine/Sources/world.cpp Engine/Headers/world.h Engine/Sources/glad.c Engine/Sources/Camera.cpp Engine/Headers/Camera.h Engine/Sources/Renderer.cpp Engine/Headers/Renderer.h Engine/Sources/Shader.cpp Engine/Headers/Shader.h Geometry/Sources/FieldManager.cpp Geometry/Headers/FieldManager.h Engine/Sources/noiseutils.cpp Engine/Headers/noiseutils.h Engine/Sources/Sun.cpp Engine/Headers/Sun.h)

include_directories(include)

target_link_libraries(Voxel3_CLION -lglfw3 -lGL -lm -ldl -lXinerama -lXrandr -lXi -lXcursor -lX11 -lXxf86vm -lpthread -lnoise)