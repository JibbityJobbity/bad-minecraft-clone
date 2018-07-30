#include <Camera.hpp>

Camera::Camera(int width, int height)
{
	View = glm::lookAt(CameraPos, CameraPos + target, up);
	Projection = glm::perspective(glm::radians(70.0f), (float)width / (float)height, 0.1f, 1000.0f);
}

void Camera::SetProjection(int width, int height, float fov)
{
	Projection = glm::perspective(glm::radians(fov), (float)width / (float)height, 0.1f, 1000.0f);
}

void Camera::MoveForward(float distance, bool relativeToWorld)
{
	if (relativeToWorld)
	{
		CameraPos.z += distance;
	}
	else
	{
		CameraPos.x += sin(glm::radians(Yaw)) * distance;
		CameraPos.z -= cos(glm::radians(Yaw)) * distance;
	}

	SetTarget();
}

void Camera::MoveAlong(float distance, bool relativeToWorld)
{
	if (relativeToWorld)
	{
		CameraPos.x += distance;
	}
	else
	{
		CameraPos -= glm::normalize(glm::cross(target, up)) * distance;
	}

	SetTarget();
}

void Camera::MoveUp(float distance, bool relativeToWorld)
{
	if (relativeToWorld)
	{
		CameraPos.y += distance;
	}
	else
	{
		CameraPos += glm::normalize(glm::cross(target, glm::cross(target, up))) * distance;
	}
	
	SetTarget();
}

void Camera::RotateYaw(float amount)
{
	float modifiedAmount = amount * LookSensitivity;
	if (up.y > 0.0f)
		Yaw += glm::radians(modifiedAmount);
	else if (up.y < 0.0f)
		Yaw -= glm::radians(modifiedAmount);
	SetTarget();
}

void Camera::RotatePitch(float amount)
{
	float modifiedAmount = amount * LookSensitivity;
	Pitch -= glm::radians(modifiedAmount);
	SetTarget();
}

void Camera::SetTarget(float yaw, float pitch)
{
	Yaw = yaw;
	Pitch = pitch;
	SetTarget();
}

void Camera::SetTarget()
{
	up = glm::vec3(0.0, 1.0, 0.0);
	if (Pitch > 90.0f)
	{
		//Pitch = 89.9f;
		up = glm::vec3(0.0, -1.0, 0.0);
		//Yaw += 180.0f;
	}
	if (Pitch < -90.0f)
	{
		//Pitch = -89.9f;
		up = glm::vec3(0.0, -1.0, 0.0);
		//Yaw += 180.0f;
	}
	if (Pitch > 180.0f)
	{
		Pitch = -180.0f;
	}
	else if (Pitch < -180.0f)
	{
		Pitch = 180.0f;
	}
	
	target.x = cos(glm::radians(Pitch)) * cos(glm::radians(Yaw + 90));
	target.y = sin(glm::radians(Pitch));
	target.z = cos(glm::radians(Pitch)) * sin(glm::radians(Yaw + 90));
	target = glm::normalize(target);
	//up.x = cos(glm::radians(Pitch)) * cos(glm::radians(Yaw + 90));
	up.y = cos(glm::radians(Pitch));
	//up.z = cos(glm::radians(Pitch)) * sin(glm::radians(Yaw + 90));
	//up = glm::normalize(up);
	if (!ThirdPerson)
	{
		View = glm::lookAt(CameraPos, CameraPos + target, up);
	}
	else
	{
		View = glm::lookAt(CameraPos + target, CameraPos, up);
	}
}