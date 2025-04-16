#version 430 core

struct Material
{
    sampler2D texture_diffuse1;
    sampler2D texture_specular1;
};
uniform Material material;

struct Light
{
    vec3  position;
    vec3  direction;
    float cutOff;
};
uniform Light light;

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoord;

out vec4 FragColor;

void main()
{
    vec3 lightDir = normalize(light.position - FragPos);
    float theta = dot(lightDir, normalize(-light.direction));

    vec3 ambient = vec3(0.2f, 0.2f, 0.2f);

    vec3 diffuse = vec3(0.6f, 0.6f, 0.6f);
    
    vec3 result;
    
    if (theta > light.cutOff)
    {
        result = (ambient + diffuse) * vec3(texture(material.texture_diffuse1, TexCoord));
    }
    else
    {
        result = ambient * vec3(texture(material.texture_diffuse1, TexCoord));
    }
    
    FragColor = vec4(result, 1.0);
    
}