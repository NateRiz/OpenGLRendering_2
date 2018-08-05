#version 460

uniform vec3 sunPos;

in vec4 vertexColor; // the input variable from the vertex shader (same name and same type)
in vec3 Normal;
in vec3 FragPos;

out vec4 FragColor;

void main()
{
    vec3 result;
    vec3 lightColor = vec3(1.f, 1.f, 1.f);
    vec3 baseColor = vec3(0.74f, 1.0f, 0.f);
    vec4 finalColor;
    float ambientStrength = 0.1f;
    vec3 ambient = lightColor * ambientStrength;

    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(sunPos - FragPos);
    float diffuseStrength = max(dot(norm, lightDir), 0.f);
    vec3 diffuse = diffuseStrength * lightColor;

    result = (ambient + diffuse) * baseColor;
    FragColor = vec4(result, 1.f);

}