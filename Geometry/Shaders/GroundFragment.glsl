#version 460

uniform vec3 sunPos;
uniform sampler2D tex;

in vec4 vertexColor; // the input variable from the vertex shader (same name and same type)
in vec3 Normal;
in vec3 FragPos;
in vec2 TexCoord;

out vec4 FragColor;

void main()
{
    vec3 result;
    vec3 lightColor = vec3(1.f, 1.f, 1.f);
    vec4 finalColor;
    float ambientStrength = 0.1f;
    vec3 ambient = lightColor * ambientStrength;

    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(sunPos - FragPos);
    float diffuseStrength = max(dot(norm, lightDir), 0.f);
    vec3 diffuse = diffuseStrength * lightColor * vec3(texture(tex, TexCoord));

    result = (ambient + diffuse);
    FragColor = vec4(result, 1.f);

}