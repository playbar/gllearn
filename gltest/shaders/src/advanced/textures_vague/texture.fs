#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

// texture sampler
uniform sampler2D texture1;
uniform float dis;  //模糊半径

void main()
{
    FragColor = texture(texture1, TexCoord);

}