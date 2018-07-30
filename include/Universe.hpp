#ifndef UNIVERSE_H
#define UNIVERSE_H
#include <iostream>
#include <array>
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <Shader.hpp>
#include <Camera.hpp>
#include <Block.hpp>
#include <Chunk.hpp>

#define WIDTH_DEFAULT 1280
#define HEIGHT_DEFAULT 720

#define DISABLE_CULLING 0
#define WIREFRAME 0
#define NEW_RENDERING 1

using namespace std;

class Universe
{
public:
	Universe(int *setupStatus);
	~Universe();
	void MakeMap();
	void EventLoop();
	void Cleanup();
	void ResizeCallback(GLFWwindow* window, int width, int height);
	void MouseCallback(GLFWwindow* window, double xPos, double yPos);
	GLFWwindow* window;
	Shader* shader;
	Camera* camera;
private:
	void MoveCharacter();
	void FindBlock();
	float oldTime;
	float oldXpos;
	float oldYpos;
	float oldFrameTime = 0.0f;
	int frameCounter = 0;
	bool firstFrame = true;
	unsigned int VAO;
	vector<Chunk> map;
	vector<Block> BlockDictionary;
	float cube[180] = {
		0.0f, 0.0f, 0.0f,  1.0f, 0.0f,
		1.0f, 0.0f, 0.0f,  0.0f, 0.0f,
		1.0f,  1.0f, 0.0f,  0.0f, 1.0f,
		1.0f,  1.0f, 0.0f,  0.0f, 1.0f,
		0.0f,  1.0f, 0.0f,  1.0f, 1.0f,
		0.0f, 0.0f, 0.0f,  1.0f, 0.0f,

		1.0f, 0.0f,  1.0f,  1.0f, 0.0f,
		0.0f, 0.0f,  1.0f,  0.0f, 0.0f,
		1.0f,  1.0f,  1.0f,  1.0f, 1.0f,
		0.0f,  1.0f,  1.0f,  0.0f, 1.0f,
		1.0f,  1.0f,  1.0f,  1.0f, 1.0f,
		0.0f, 0.0f,  1.0f,  0.0f, 0.0f,

		0.0f, 0.0f, 0.0f,  0.0f, 0.0f,
		0.0f,  1.0f, 0.0f,  0.0f, 1.0f,
		0.0f,  1.0f,  1.0f,  1.0f, 1.0f,
		0.0f, 0.0f,  1.0f,  1.0f, 0.0f,
		0.0f, 0.0f, 0.0f,  0.0f, 0.0f,
		0.0f,  1.0f,  1.0f,  1.0f, 1.0f,

		1.0f, 0.0f, 0.0f,  1.0f, 0.0f,
		1.0f,  1.0f,  1.0f,  0.0f, 1.0f,
		1.0f,  1.0f, 0.0f,  1.0f, 1.0f,
		1.0f,  1.0f,  1.0f,  0.0f, 1.0f,
		1.0f, 0.0f, 0.0f,  1.0f, 0.0f,
		1.0f, 0.0f,  1.0f,  0.0f, 0.0f,

		0.0f, 0.0f, 0.0f,  1.0f, 1.0f,
		1.0f, 0.0f,  1.0f,  0.0f, 0.0f,
		1.0f, 0.0f, 0.0f,  0.0f, 1.0f,
		1.0f, 0.0f,  1.0f,  0.0f, 0.0f,
		0.0f, 0.0f, 0.0f,  1.0f, 1.0f,
		0.0f, 0.0f,  1.0f,  1.0f, 0.0f,

		1.0f,  1.0f,  1.0f,  1.0f, 0.0f,
		0.0f,  1.0f, 0.0f,  0.0f, 1.0f,
		1.0f,  1.0f, 0.0f,  1.0f, 1.0f,
		0.0f,  1.0f, 0.0f,  0.0f, 1.0f,
		1.0f,  1.0f,  1.0f,  1.0f, 0.0f,
		0.0f,  1.0f,  1.0f,  0.0f, 0.0f
    	};
};

#endif
