#version 330

uniform vec3 color;

layout(location = 0) out vec4 out_color;

in float wave_height;

void main()
{
	out_color = vec4(abs(color) + (1 - abs(color)) * wave_height, 1);
}