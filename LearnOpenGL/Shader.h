#pragma once
#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

struct StrToCharArray {
	const char* p;
	StrToCharArray(const std::string& s) : p(s.c_str()) {}
	operator const char** () { return &p; }
};

class Shader
{
public:
	unsigned int ID;

	Shader(const char* vertexPath, const char* fragmentPath)
	{
		// Vertex Source
		std::ifstream vertexFile(vertexPath);
		if (!vertexFile.is_open())
		{
			std::cerr << "Invalid Path to Vertex Shader! Path: " << vertexPath << std::endl;
			__debugbreak();
			return;
		}
		std::stringstream vertexSource;
		vertexSource << vertexFile.rdbuf();
		vertexFile.close();

		// Fragment Source
		std::ifstream fragmentFile(fragmentPath);
		if (!fragmentFile.is_open())
		{
			std::cerr << "Invalid Path to Fragment Shader! Path: " << fragmentPath << std::endl;
			__debugbreak();
			return;
		}
		std::stringstream fragmentSource;
		fragmentSource << fragmentFile.rdbuf();
		fragmentFile.close();

		// Creating Shader
		unsigned int vert = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vert, 1, StrToCharArray(vertexSource.str()), 0);
		glCompileShader(vert);
		unsigned int frag = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(frag, 1, StrToCharArray(fragmentSource.str()), 0);
		glCompileShader(frag);

		// Check Compile status
		{
			int  success;
			char infoLog[512];
			glGetShaderiv(vert, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(vert, 512, NULL, infoLog);
				std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
			}
			glGetShaderiv(frag, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(frag, 512, NULL, infoLog);
				std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
			}
		}

		ID = glCreateProgram();
		glAttachShader(ID, vert);
		glAttachShader(ID, frag);
		glLinkProgram(ID);

		// Delete Shaders
		glDeleteShader(vert);
		glDeleteShader(frag);
	}
	~Shader()
	{
		glDeleteShader(ID);
	}

	void use()
	{
		glUseProgram(ID);
	}

	// utility uniform functions
	void setBool(const std::string& name, bool value) const
	{
		unsigned int uniformLocation = glGetUniformLocation(ID, name.c_str());
		if (uniformLocation == -1) return;
		glUniform1i(uniformLocation, value);
	}
	void setInt(const std::string& name, int value) const
	{
		unsigned int uniformLocation = glGetUniformLocation(ID, name.c_str());
		if (uniformLocation == -1) return;
		glUniform1i(uniformLocation, value);
	}
	void setFloat(const std::string& name, float value) const
	{
		unsigned int uniformLocation = glGetUniformLocation(ID, name.c_str());
		if (uniformLocation == -1) return;
		glUniform1f(uniformLocation, value);
	}
	void setMat4(const std::string& name, glm::mat4 value) const
	{
		unsigned int uniformLocation = glGetUniformLocation(ID, name.c_str());
		if (uniformLocation == -1) return;
		glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(value));
	}
	void setVec3(const std::string& name, glm::vec3 value)
	{
		unsigned int uniformLocation = glGetUniformLocation(ID, name.c_str());
		if (uniformLocation == -1) return;
		glUniform3f(uniformLocation, value.x, value.y, value.z);
	}
	void setVec3(const std::string& name, float v0, float v1, float v2)
	{
		setVec3(name, glm::vec3(v0, v1, v2));
	}
};
