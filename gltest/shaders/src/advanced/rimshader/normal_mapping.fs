#version 330 core
out vec4 FragColor;

in vec2 TexCoords;
in vec3 rimVDN;
in float rc;
out vec4 v_pos;
out vec3 v_norm;

uniform sampler2D diffuseMap;
uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

uniform float rimPower = 0.65;



void main()
{

//    mat4 modelview= view * model;
//    vec3 nn = normalize(mat3(modelview) * v_norm);
//    vec3 pp = vec3(modelview * v_pos);
//    vec3 v = normalize(-p);
//    float vdn = 1.0 - max(dot(v, n), 0.0);
//    vdn = 0.5;
//    float rimsmooth = smoothstep( rimPower, 1.0, vdn);
//    FragColor = vec4(0.5, 0.5, 0.5, 1.0);
//    FragColor.a = 1.0;
//    FragColor.rgb = vec3(smoothstep(0.6, 1.0, vdn));

//    FragColor = vec4(smoothstep(rimPower, 1.0, rimVDN), 1.0);

//    float rimsmooth = smoothstep( rimPower, 1.0, rc);
//    FragColor = vec4(rimsmooth, rimsmooth, rimsmooth, 1.0);

    float rimsmooth = smoothstep( rimPower, 1.0, rc);
    FragColor = texture(diffuseMap, TexCoords);
    FragColor = FragColor * rimsmooth;


}