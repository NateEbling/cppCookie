#pragma once
#include "core.h"

namespace Cookie
{
	struct Shader
	{
		uint32 programID;
		uint32 startIndex;
		char* filepath;

		Shader();

		void compile(const char* shaderFilepath);
		void bind() const;
		void unbind() const;
		void destroy();

		void uploadMat3(const char* varName, const glm::mat3& mat3) const;
		void uploadMat4(const char* varName, const glm::mat4& mat4) const;
		void uploadVec4(const char* varName, const glm::vec4& vec4) const;
		void uploadVec3(const char* varName, const glm::vec3& vec3) const;
		void uploadVec2(const char* varName, const glm::vec2& vec2) const;
		void uploadInt(const char* varName, int val) const;
		void uploadFloat(const char* varName, float val) const;
		void uploadIntArray(const char* varName, int length, const int* array) const;
		void uploadTexture(const char* varName, int slot);
	};
}
