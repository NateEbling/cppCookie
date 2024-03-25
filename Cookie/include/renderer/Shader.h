#pragma once
#include "core.h"

namespace Cookie
{
	class Shader
	{
	private:
		uint32 shaderProgramID;
		bool beingUsed;
		robin_hood::unordered_map<GLenum, std::string> shaderSources;
		char* filepath;
	public:
		Shader(char* filepath);
		void compile();
		void use();
		void detach();
		// Upload data to shader
		void uploadMat4(const char* varName, const glm::mat4& mat4) const;
		void uploadMat3(const char* varName, const glm::mat3& mat3) const;
		void uploadVec4(const char* varName, const glm::vec4& vec4) const;
		void uploadVec3(const char* varName, const glm::vec3& vec3) const;
		void uploadVec2(const char* varName, const glm::vec2& vec2) const;
		void uploadFloat(const char* varName, float val) const;
		void uploadInt(const char* varName, int val) const;
		void uploadTexture(const char* varName, int slot) const;
		void uploadIntArray(const char* varname, int length, const int* array) const;
	};
}
