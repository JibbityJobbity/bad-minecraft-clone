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

	camera = new Camera(WIDTH_DEFAULT, HEIGHT_DEFAULT);
    	shader = new Shader("shaders/vertex.vs", "shaders/fragment.fs");

	return 0;
}

void Universe::EventLoop()
{
	while (!glfwGetKey(window, GLFW_KEY_ESCAPE) && !glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		MoveCharacter();
		// Clear framebuffer
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Use shader
		shader->use();
		//shader->setMat4("transform", glm::mat4(1.0f));
		shader->setMat4("view", camera->View);
		shader->setMat4("project", camera->Projection);
		// Render block
		glBindVertexArray(VAO);
		glBindTexture(GL_TEXTURE_2D, BlockDictionary[0].texture);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		// Update GLFW
		glfwSwapBuffers(window);
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
	float cameraSpeed = 5.0f;
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