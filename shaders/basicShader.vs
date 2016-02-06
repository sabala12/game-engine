#version 120

attribute vec3 position;
attribute vec3 color;
attribute mat4 fullTransformationMatrix;

varying vec4 f_color;

uniform mat4 transformation;
 
void main()
{
	gl_Position = transformation * vec4(position,1.0);
	
	f_color = vec4(color,0.5);
}