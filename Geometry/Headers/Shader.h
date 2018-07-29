#ifndef VOXEL3_CLION_SHADER_H
#define VOXEL3_CLION_SHADER_H
#include <glm/glm.hpp>
#include <string>
#include <glad/glad.h>

class Shader {
public:
    Shader(const char*, const char*);
    void Use();
    void setMat4(const std::string &name, const glm::mat4 &mat) const;

    unsigned int ID;

private:
    // utility function for checking shader compilation/linking errors.
    // ------------------------------------------------------------------------
    void checkCompileErrors(GLuint shader, std::string type);

};


#endif //VOXEL3_CLION_SHADER_H
