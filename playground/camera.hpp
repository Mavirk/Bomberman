#ifndef CAMERA_HPP
# define CAMERA_HPP
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <vector>

#include <iostream>

// Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
enum Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

// Default camera values
const float YAW         = -90.0f;
const float PITCH       =  0.0f;
const float SPEED       =  2.5f;
const float SENSITIVITY =  0.1f;
const float ZOOM        =  45.0f;

class Camera
{
	public:
		//start canonical form
		Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH);
		Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);
		Camera(Camera const & src);
		~Camera(void);
        glm::mat4 GetViewMatrix();
        void ProcessKeyboard(Camera_Movement direction, float deltaTime);
        void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true);
        void ProcessMouseScroll(float yoffset);
        // Camera Attributes
        glm::vec3 Position;
        glm::vec3 Front;
        glm::vec3 Up;
        glm::vec3 Right;
        glm::vec3 WorldUp;
        // Euler Angles
        float Yaw;
        float Pitch;
        // Camera options
        float MovementSpeed;
        float MouseSensitivity;
        float Zoom;

		Camera	&operator=(Camera const &rhs);
		//end canonical form

		int	getfoo(void) const;
	private:
        void updateCameraVectors();
		int _foo;
};

std::ostream	&operator<<(std::ostream &out, Camera const &value);

#endif