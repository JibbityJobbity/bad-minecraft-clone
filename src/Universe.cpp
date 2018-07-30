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

Universe::Universe(int *setupStatus)
{
	universe_pointer = this;
	// Init GLFW
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_SAMPLES, 8);

	window = glfwCreateWindow(WIDTH_DEFAULT, HEIGHT_DEFAULT, "Game", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to initialise GLFW";
		glfwTerminate();
		*setupStatus = -1;
		return;
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
		*setupStatus = -2;
		return;
	}

	glEnable(GL_MULTISAMPLE);
	glEnable(GL_DEPTH_TEST);
	// Enable culling
	#if DISABLE_CULLING== 1
	#else
	glViewport(0, 0, WIDTH_DEFAULT, HEIGHT_DEFAULT);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CW);
	#endif

	// Wireframe
	#if WIREFRAME
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	#endif

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
	oldTime = glfwGetTime();
	MakeMap();
	float deltaTime = glfwGetTime() - oldTime;
	std::cout << "Map generation in: " << deltaTime << std::endl;
	

	camera = new Camera(WIDTH_DEFAULT, HEIGHT_DEFAULT);
    	shader = new Shader("shaders/vertex.vs", "shaders/fragment.fs");

	return;
}

void Universe::EventLoop()
{
	// Anisotropic Filtering
        float aniFiltering = 0.0f;
	glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY, &aniFiltering);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY, aniFiltering);

	//glBindVertexArray(VAO);
	while (!glfwGetKey(window, GLFW_KEY_ESCAPE) && !glfwWindowShouldClose(window))
	{
		MoveCharacter();
		// Clear framebuffer
		glClearColor(0.0f, 0.1f, 0.5f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Use shader
		//debugOldTime = glfwGetTime();
		shader->use();
		shader->setMat4("view", camera->View);
		// Render each chunk
		for (int i = 0; i < map.size(); i++)
		{
			Chunk currentChunk = map[i];

			#if NEW_RENDERING
			shader->setMat4("transform", currentChunk.posMatrix);
			shader->setMat4("project", camera->Projection);
			glBindVertexArray(currentChunk.Mesh);
			glBindBuffer(GL_ARRAY_BUFFER, currentChunk.VBO);
			glDrawArrays(GL_TRIANGLES, 0, currentChunk.chunkFaces.size() / 5);

			#else
			// Old rendering which renders every single block, should only be used for diagnostics or if you're insane
			for (int j = 0; j < currentChunk.layers.size(); j++)
			{
				for (int k = 0; k < currentChunk.layers[j].size(); k++)
				{
					for (int l = 0; l < currentChunk.layers[j][k].size(); l++)
					{
						glm::mat4 blockTransform = glm::translate(glm::mat4(1.0), glm::vec3(k + (currentChunk.xCoord * 16), j, l + (currentChunk.zCoord * 16)));
						shader->setMat4("transform", blockTransform);
						glBindTexture(GL_TEXTURE_2D, BlockDictionary[currentChunk.layers[j][k][l]].texture);

						glDrawArrays(GL_TRIANGLES, 0, 36);
					}
				}
			}
			#endif
		}
		// Update GLFW
		glfwSwapBuffers(window);
		glfwPollEvents();

		if (glfwGetTime() - oldFrameTime > 5)
		{
			std::cout << frameCounter / 5.0f << " fps" << std::endl;
			oldFrameTime = glfwGetTime();
			frameCounter = 0;
		}
		else
			frameCounter++;
	}
}

Universe::~Universe()
{
	glfwDestroyWindow(window);
	
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
	float cameraSpeed = 5.0f;
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
	{
		cameraSpeed = 16.0f;
	}
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
	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		camera->MoveUp(-cameraSpeed * deltaTime, true);
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
	{
		camera->MoveUp(cameraSpeed * deltaTime, true);
	}
}

void Universe::MakeMap()
{
	std::array<std::array<int, CHUNK_SIZE>, CHUNK_SIZE> layer;
	for (int i = -8; i < 8; i++)
	{
		for (int j = -8; j < 8; j++)
		{
			map.push_back(Chunk());

			map[map.size() - 1].zCoord = i;
			map[map.size() - 1].xCoord = j;
			for (int k = 0; k < 16; k++)
			{
				for (int l = 0; l < layer.size(); l++)
				{
					for (int m = 0; m < layer.size(); m++)
					{
						layer[l][m] = 1;
						if (l == m && l == k && k == m)
							layer[l][m] = 0;
					}
				}
				//for (int l = 0; l <= j + i; l++)
					map[map.size() - 1].layers.push_back(layer);
			}
		}
	}
	for (int i = 0; i < map.size(); i++)
		map[i].GenMesh(map);
}
