#ifndef AQUAENGINE_CORE_PHYS_ENTITY_H
#define AQUAENGINE_CORE_PHYS_ENTITY_H

#include <graphics/Model.h>
#include <graphics/Texture.h>
#include <graphics/Shader.h>
#include <graphics/MeshTransform.h>
#include <graphics/ShadowMapping.h>

class PhysEntity {
private:
	Model mModel;
	Texture mTexture;
public:
	PhysEntity() {}
	PhysEntity(const std::string& ModelPath, const std::string& TexturePath, vec3 Position, vec3 RotAxis, vec3 Scale);

	void Load(const std::string& ModelPath, const std::string& TexturePath, vec3 Position, vec3 RotAxis, vec3 Scale);
	void Render(Shader& shader);

	bool operator==(PhysEntity &ent);

	MeshTransform Transform;
};

#endif
