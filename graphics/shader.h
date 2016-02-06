#ifndef GAME_ENGINE_SHADER_H
#define GAME_ENGINE_SHADER_H

#include "transform.h"

#include <GL/glew.h>
#include <string>

namespace Engine
{
	class Camera;

	class Shader
	{
	public:
		Shader(const std::string& fileName);

		void Bind();
		void Update(const Transform& transform, const Camera& camera);

		virtual ~Shader();

		inline GLuint GetProgramID() const { return m_program; }
		inline const GLuint* GetuniformsID() const { return m_uniforms; }

	private:
		static const unsigned int NUM_SHADERS = 2;
		static const unsigned int NUM_UNIFORMS = 1;
		void operator=(const Shader& shader) {}
		Shader(const Shader& shader) {}

		std::string LoadShader(const std::string& fileName);
		void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);
		GLuint CreateShader(const std::string& text, unsigned int type);

		GLuint m_program;
		GLuint m_shaders[NUM_SHADERS];
		GLuint m_uniforms[NUM_UNIFORMS];
	};
}

#endif //GAME_ENGINE_SHADER_H