#version 440
layout(location = 0) in vec3 Pos;
layout(location = 1) in vec3 Color;

uniform vec2 movePos;

out vec4 out_Color;

void main()
{
	vec3 newPos = vec3(Pos.xy + movePos, Pos.z);
	gl_Position = vec4(newPos, 1.0);
	out_Color = vec4(Color, 1.0);
}