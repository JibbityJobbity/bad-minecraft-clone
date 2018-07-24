#ifndef SHADER_H
#define SHADER_H
#include <glad/glad.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
using namespace std;

class Shader
{
public:
	unsigned int ID;

	Shader(const char* vertexPath, const char* fragmentPath);
	void use();
	void setBool(const std::string &name, bool value);
	void setInt(const std::string &name, int value);
	void setFloat(const std::string &name, float value);
	void setMat4(const std::string &name, glm::mat4 value);
	void setVec2(const std::string &name, const glm::vec2 &value);
};

#endif