#version 440
layout(location = 0) in vec3 vPos;
layout(location = 1) in vec3 in_Color;

uniform mat4 modelTransform;
out vec4 out_Color;

void main()
{
	gl_Position = modelTransform * vec4(vPos, 1.0);

	out_Color = vec4(in_Color, 1.0);
}