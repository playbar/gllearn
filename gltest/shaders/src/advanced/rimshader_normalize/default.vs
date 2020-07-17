#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

out vec2 TexCoords;
out float rc;

out vec3 fragPosition;
out vec3 fragNormal;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main()
{
//    mat4 modelview= view * model;
//    vec3 n = normalize(mat3(modelview) * aNormal);  // convert normal to view space
//    vec3 p = vec3(modelview * vec4(aPos, 1.0));  // position in view space
//    vec3 v = normalize(-p);             // vector towards eye
//    rc = 1.0 - max(dot(v, n), 0.0);
    TexCoords = aTexCoords;
    gl_Position = projection * view * model * vec4(aPos, 1.0);
    fragPosition = (model * vec4(aPos, 1.0)).xyz;
    fragNormal = normalize((model *vec4(aNormal, 0.0)).xyz);
}