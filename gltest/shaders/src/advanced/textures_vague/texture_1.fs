#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

// texture sampler
uniform sampler2D texture1;
uniform float dis;  //模糊半径

void main()
{
    vec2 u_TextureCoordOffset[25];

    u_TextureCoordOffset=vec2[](
            vec2(-2. * dis,2. * dis),vec2(-1. * dis,2. * dis),vec2(0. * dis,2. * dis),vec2(1. * dis,2. * dis),vec2(2. * dis,2. * dis),
            vec2(-2. * dis,1. * dis),vec2(-1. * dis,1. * dis),vec2(0. * dis,1. * dis),vec2(1. * dis,1. * dis),vec2(2. * dis,1. * dis),
            vec2(-2. * dis,0. * dis),vec2(-1. * dis,0. * dis),vec2(0. * dis,0. * dis),vec2(1. * dis,0. * dis),vec2(2. * dis,0. * dis),
            vec2(-2. * dis,-1. * dis),vec2(-1. * dis,-1. * dis),vec2(0. * dis,-1. * dis),vec2(1. * dis,-1. * dis),vec2(2. * dis,-1. * dis),
            vec2(-2. * dis,-2. * dis),vec2(-1. * dis,-2. * dis),vec2(0. * dis,-2. * dis),vec2(1. * dis,-2. * dis),vec2(2. * dis,-2. * dis)
    );

    vec4 sample[25];
    for (int i = 0; i < 25; i++)
    {
        sample[i] = texture(texture1, TexCoord.st + u_TextureCoordOffset[i]/512.0);
    }

//    FragColor = texture(texture1, TexCoord);
    FragColor = (
           (1.0  * (sample[0] + sample[4]  + sample[20] + sample[24])) +
           (4.0  * (sample[1] + sample[3]  + sample[5]  + sample[9] + sample[15] + sample[19] + sample[21] + sample[23])) +
           (7.0  * (sample[2] + sample[10] + sample[14] + sample[22])) +
           (16.0 * (sample[6] + sample[8]  + sample[16] + sample[18])) +
           (26.0 * (sample[7] + sample[11] + sample[13] + sample[17])) +
           (41.0 * sample[12])
   ) / 273.0;
}