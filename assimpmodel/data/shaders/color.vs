#version 110

attribute vec4 position;
attribute vec4 color;
uniform mat4 MVP;
//uniform vec4 color_u;
varying vec4 color_f;
void main()
{
    color_f = color;
    gl_Position = MVP * position;
}