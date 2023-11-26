#version 440
layout(location = 0) in vec3 vPos;

uniform mat4 viewTransform;
uniform mat4 projectionTransform;
uniform mat4 modelTransform;
out vec4 out_Color;

void main()
{
	gl_Position = projectionTransform * viewTransform * modelTransform * vec4(vPos, 1.0);
	
	out_Color = vec4(0.0, 1.0, 1.0, 1.0);
}