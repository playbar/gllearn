#version 330 core
layout (location = 0) in vec4 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;

out vec2 TexCoords;
out vec3 rimVDN;
out float rc;
out vec4 v_pos;
out vec3 v_norm;


uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main()
{
    v_pos = aPos;
    v_norm = aNormal;
    mat4 modelview= view * model;
    vec3 n = normalize(mat3(modelview) * aNormal);  // convert normal to view space
    vec3 p = vec3(modelview * aPos);  // position in view space
    vec3 v = normalize(-p);             // vector towards eye
    rc = 1.0 - max(dot(v, n), 0.0);
    rimVDN = vec3(rc, rc, rc);
    TexCoords = aTexCoords;
    gl_Position = projection * view * model * aPos;
}