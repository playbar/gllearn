#version 110

varying vec2      textureCoords;
uniform sampler2D textureSampler;

void main()
{
    gl_FragColor.xyz = texture2D( textureSampler, textureCoords ).xyz;
}
