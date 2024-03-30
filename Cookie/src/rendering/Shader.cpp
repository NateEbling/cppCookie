#include "core.h"
#include "rendering/Shader.h"

namespace Cookie
{
	static GLenum ShaderTypeFromString(const std::string& type);
	static std::string ReadFile(const char* filepath);

	Shader::Shader(char* shaderFilepath)
	{
		filepath = shaderFilepath;
		
		int strLength = (int)std::strlen(shaderFilepath);
		filepath = (char*)(sizeof(char) * (strLength + 1));
		std::strcpy(filepath, shaderFilepath);
		filepath[strLength] = '\0';
		std::string fileSource = ReadFile(filepath);

		const char* typeToken = "#type";
		size_t typeTokenLength = strlen(typeToken);
		size_t pos = fileSource.find(typeToken, 0);
		while (pos != std::string::npos)
		{
			size_t eol = fileSource.find_first_of("\r\n", pos);
			size_t begin = pos + typeTokenLength + 1;
			std::string type = fileSource.substr(begin, eol - begin);

			size_t nextLinePos = fileSource.find_first_not_of("\r\n", eol);
			pos = fileSource.find(typeToken, nextLinePos);
			shaderSources[ShaderTypeFromString(type)] = fileSource.substr(nextLinePos, pos - (nextLinePos == std::string::npos ? fileSource.size() - 1 : nextLinePos));
		}
	}

	void Shader::compile()
	{
		GLuint program = glCreateProgram();
		std::array<GLenum, 2> glShaderIDs;
		int glShaderIDIndex = 0;

		for (auto& kv : shaderSources)
		{
			GLenum shaderType = kv.first;
			const std::string& source = kv.second;

			// Create empty vertex shader handle
			GLuint shader = glCreateShader(shaderType);

			const GLchar* sourceCStr = source.c_str();
			glShaderSource(shader, 1, &sourceCStr, 0);

			// Compile vertex shader
			glCompileShader(shader);

			GLint isCompiled = 0;
			glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
			if (isCompiled == GL_FALSE)
			{
				GLint maxLength = 0;
				glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

				std::vector<GLchar> infoLog(maxLength);
				glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);

				glDeleteShader(shader);

				std::cerr << "Shader compilation failed" << std::endl;

				shaderProgramID = UINT32_MAX;
				return;
			}

			glAttachShader(program, shader);
			glShaderIDs[glShaderIDIndex++] = shader;
		}

		// Link our program
		glLinkProgram(program);

		GLint isLinked = 0;
		glGetProgramiv(program, GL_LINK_STATUS, (int*)&isLinked);
		if (isLinked == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength);
			glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

			// We don't need the program anymore.
			glDeleteProgram(program);
			// Don't leak shaders either.
			for (auto id : glShaderIDs)
				glDeleteShader(id);

			std::cerr << "Shader linking failed" << std::endl;

			shaderProgramID = UINT32_MAX;
			return;
		}

		// Detach shaders after a successful link
		for (auto id : glShaderIDs)
			glDetachShader(program, id);

		shaderProgramID = program;
	}

	void Shader::use()
	{
		if (!beingUsed)
		{
			glUseProgram(shaderProgramID);
			beingUsed = true;
		}
	}

	void Shader::detach()
	{
		glUseProgram(0);
		beingUsed = false;
	}

	// Private functions
	static std::string ReadFile(const char* filepath)
	{
		std::string result;
		std::ifstream in(filepath, std::ios::in | std::ios::binary);
		if (in)
		{
			in.seekg(0, std::ios::end);
			result.resize(in.tellg());
			in.seekg(0, std::ios::beg);
			in.read(&result[0], result.size());
			in.close();
		}
		else
		{
			std::cerr << "Could not open file " << filepath << "." << std::endl;
		}

		return result;
	}

	static GLenum ShaderTypeFromString(const std::string& type)
	{
		if (type == "vertex")
			return GL_VERTEX_SHADER;
		else if (type == "fragment")
			return GL_FRAGMENT_SHADER;

		std::cerr << "Unknown shader type" << std::endl;
		return 0;
	}
}