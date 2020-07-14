#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoords;

out vec2 TexCoords;
out float step;
out vec3 posout;
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    TexCoords = aTexCoords;    
    vec4 pos = projection * view * model * vec4(aPos, 1.0f);
    gl_Position = normalize(pos);
    posout = vec3(gl_Position.x, gl_Position.y, gl_Position.z);
    float stepz = length(gl_Position);
    //step =  (2.0 - stepz) / 1.44;
    step = clamp(step, 0.0, 1.0);
}