#version 330 core

in vec2 TexCoord;
in vec3 FragPos;
in vec3 Normal;

layout (location = 0) out vec4 Color;

uniform vec4 QuadColor;
uniform vec3 CameraPos;
uniform sampler2D sampler;

void main()
{
	vec3 LightColor = vec3(1.0, 1.0, 1.0);

	// Calculate Ambient
	float AmbientStrength = 0.1;
	vec3 Ambient = AmbientStrength * LightColor;

	// Calculate Diffuse
	vec3 LightPos = vec3(3.0, 4.0, -8.0);
	vec3 Norm = normalize(Normal);
	vec3 LightDirection = normalize(LightPos - FragPos);
	float Diff = max(dot(Norm, LightDirection), 0.0);
	vec3 Diffuse = Diff * LightColor;

	// Calculate Specular
	float SpecularStrength = 1;
	vec3 ViewDirection = normalize(CameraPos - FragPos);
	vec3 ReflectDirection = reflect(-LightDirection, Norm);
	float Spec = pow(max(dot(ViewDirection, ReflectDirection), 0.0), 32);
	vec3 Specular = vec3(SpecularStrength * Spec * LightColor);

	vec4 ProcColor = vec4(Ambient + Diffuse + Specular, 1.0) * texture2D(sampler, TexCoord);

	Color = ProcColor;
}
