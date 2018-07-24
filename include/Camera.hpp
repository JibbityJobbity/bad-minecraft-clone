#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera
{
public:
	Camera(int width, int height);
	void SetProjection(int width, int height, float fov);
	void MoveForward(float distance, bool relativeToWorld);
	void MoveAlong(float distance, bool relativeToWorld);
	void MoveUp(float distance, bool relativeToWorld);
	void RotateYaw(float degrees);
	void RotatePitch(float degrees);
	void SetTarget(float yaw, float pitch);
	void SetTarget();
	glm::vec3 CameraPos = glm::vec3(-3.0f, 16.0f, -3.0f);
	glm::mat4 View = glm::mat4(1.0f);
	glm::mat4 Projection;
	float Yaw = 0.0f;
	float Pitch = 0.0f;
	float Fov = 75.0f;
	float LookSensitivity = 5.0f;
	bool ThirdPerson = false;
private:
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 target = glm::vec3(0.0f, 0.0f, 1.0f);
};

#endif
