#version 330 core
out vec4 FragColor;

in vec2 TexCoords;
in float step;
in vec3 posout;
uniform vec3 eyepos;
uniform sampler2D texture1;

void main()
{
    vec2 pos1 = vec2(posout.x, posout.z);
    vec2 pos2 = vec2(eyepos.x, eyepos.z);
//    float stepee = length(pos1);
//    float stepee = distance(pos1, pos2);
    float stepee = posout.z;
    stepee = clamp(stepee, 0.0, 1.0);
    vec4 color = texture(texture1, TexCoords);
    FragColor = mix(color, vec4(0.0, 0.8, 0.0, 1.0), stepee );
//    if( step > 0.2)
//        FragColor = vec4(0.0, 0.8, 0.2, 1.0);
//    else
//        FragColor = texture(texture1, TexCoords);
}