#include <Universe.hpp>

Universe* universe_pointer = nullptr;

void Resize_Callback(GLFWwindow* window, int width, int height)
{
	if (universe_pointer)
	{
		universe_pointer->ResizeCallback(window, width, height);
	}
}

void Mouse_Callback(GLFWwindow* window, double xPos, double yPos)
{
	if (universe_pointer)
	{
		universe_pointer->MouseCallback(window, xPos, yPos);
	}
}

int Universe::Setup()
{
	universe_pointer = this;
	// Init GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(WIDTH_DEFAULT, HEIGHT_DEFAULT, "Game", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to initialise GLFW";
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, Resize_Callback);
	glfwSetCursorPosCallback(window, Mouse_Callback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	

	// Init GLAD
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialise GLAD" << std::endl;
		glfwTerminate();
		return -2;
	}

	glViewport(0, 0, WIDTH_DEFAULT, HEIGHT_DEFAULT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CW);

	// Vertex Buffers
	unsigned int VBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(cube), cube, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	LoadBlocks(&BlockDictionary);
	MakeMap();

	camera = new Camera(WIDTH_DEFAULT, HEIGHT_DEFAULT);
    	shader = new Shader("shaders/vertex.vs", "shaders/fragment.fs");

	return 0;
}

void Universe::EventLoop()
{
        float aniFiltering = 0.0f;
	while (!glfwGetKey(window, GLFW_KEY_ESCAPE) && !glfwWindowShouldClose(window))
	{
		MoveCharacter();
		// Clear framebuffer
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Use shader
		shader->use();
		shader->setMat4("view", camera->View);
		shader->setMat4("project", camera->Projection);
		// Render block
		glBindVertexArray(VAO);
		for (int i = 0; i < map.size(); i++)
		{
			Chunk currentChunk = map.at(i);
			for (int j = 0; j < currentChunk.layers.size(); j++)
			{
				for (int k = 0; k < currentChunk.layers[j].size(); k++)
				{
					for (int l = 0; l < currentChunk.layers.at(j).at(k).size(); l++)
					{
						glm::mat4 blockTransform = glm::translate(glm::mat4(1.0), glm::vec3(k + (currentChunk.xCoord * 16), j, l + (currentChunk.yCoord * 16)));
						shader->setMat4("transform", blockTransform);
						glBindTexture(GL_TEXTURE_2D, BlockDictionary[currentChunk.layers.at(j).at(k).at(l)].texture);
                				glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY, &aniFiltering);
						glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY, aniFiltering);
						glDrawArrays(GL_TRIANGLES, 0, 36);
					}
				}
			}
		}
		// Update GLFW
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

void Universe::Cleanup()
{

}

void Universe::ResizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	camera->SetProjection(width, height, camera->Fov);
}

void Universe::MouseCallback(GLFWwindow* window, double xPos, double yPos)
{
	float xDistance, yDistance;
	xDistance = xPos - oldXpos;
	yDistance = yPos - oldYpos;
	oldXpos = xPos;
	oldYpos = yPos;
	if (firstFrame)
	{
		firstFrame = false;
	}
		
	else
	{
		camera->RotateYaw(xDistance);
		camera->RotatePitch(yDistance);
	}
}

void Universe::MoveCharacter()
{
	float deltaTime = oldTime - glfwGetTime();
	oldTime = glfwGetTime();
	float cameraSpeed = 15.0f;
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		camera->MoveForward(cameraSpeed * deltaTime, false);
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		camera->MoveForward(-cameraSpeed * deltaTime, false);
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		camera->MoveAlong(cameraSpeed * deltaTime, false);
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		camera->MoveAlong(-cameraSpeed * deltaTime, false);
	}
}

void Universe::MakeMap()
{
	for (int i = 0; i < 1; i++)
	{
		Chunk currentChunk;
		std::array<std::array<int, 16>, 16> layer;
		currentChunk.yCoord = i;
		for (int j = 0; j < 1; j++)
		{
			currentChunk.xCoord = j;
			currentChunk.layers.clear();
			for (int k = 0; k < 1; k++)
			{
				for (int l = 0; l < 16; l++)
				{
					for (int m = 0; m < 16; m++)
					{
						layer[l][m] = 0;
					}
				}
				currentChunk.layers.push_back(layer);
			}
			map.push_back(currentChunk);
		}
	}
}

void Universe::FindBlock()
{
	for (int i = 0; i < map.size(); i++)
	{

	}
}