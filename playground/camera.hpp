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
        Camera();
		Camera(glm::vec3 position, glm::vec3 up, float yaw , float pitch);
		Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);
		Camera(Camera const & src);
		~Camera(void);

		Camera	&operator=(Camera const &rhs);

        void    ProcessMouseScroll(float yoffset);
        void    ProcessKeyboard(Camera_Movement direction, float deltaTime);
        void    ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch);
        void    DoMovement(int direction, float deltaTime);
        glm::mat4 GetViewMatrix();
        glm::vec3 GetPosition() const;
        glm::vec3 GetFront() const;
        glm::vec3 GetUp() const;
        glm::vec3 GetRight() const ;
        glm::vec3 GetWorldUp() const;
        GLfloat GetYaw() const;
        GLfloat GetPitch() const;
        GLfloat GetMovementSpeed() const;
        GLfloat GetMouseSensitivity() const;
        GLfloat GetZoom() const;
    
	private:
        void updateCameraVectors();
        // Camera Attributes
        glm::vec3 Position;
        glm::vec3 Front;
        glm::vec3 Up;
        glm::vec3 Right;
        glm::vec3 WorldUp;
        // Euler Angles
        GLfloat Yaw;
        GLfloat Pitch;
        // Camera options
        GLfloat MovementSpeed;
        GLfloat MouseSensitivity;
        GLfloat Zoom;

};

std::ostream	&operator<<(std::ostream &out, Camera const &value);

#endif