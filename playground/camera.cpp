#include "camera.hpp"

// Constructor with vectors
Camera::Camera(){
    this->Position = glm::vec3(0.0f, 0.0f, 0.0f);
    this->WorldUp = glm::vec3(0.0f, 1.0f, 0.0f);
    this->Front = glm::vec3(0.0f, 0.0f, -1.0f);
    this->Yaw = YAW;
    this->Pitch = PITCH;
    this->MovementSpeed = SPEED;
    this->MouseSensitivity = SENSITIVITY;
    this->Zoom = ZOOM;    
    this->updateCameraVectors();
    return;
}

Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch) :
Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM) {
    this->Position = position;
    this->WorldUp = up;
    this->Yaw = yaw;
    this->Pitch = pitch;
    this->updateCameraVectors();
}

// Constructor with scalar values
Camera::Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) :
Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM) {
    this->Position = glm::vec3(posX, posY, posZ);
    this->WorldUp = glm::vec3(upX, upY, upZ);
    this->Yaw = yaw;
    this->Pitch = pitch;
    this->updateCameraVectors();
}

glm::mat4
Camera::GetViewMatrix() {
    return glm::lookAt(this->Position, this->Position + this->Front, this->Up);
}

// Processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
void
Camera::ProcessKeyboard(Camera_Movement direction, float deltaTime) {
    float velocity = this->MovementSpeed * deltaTime;
    
    if (direction == FORWARD)
        this->Position += this->Front * velocity;
    if (direction == BACKWARD)
        this->Position -= this->Front * velocity;

    if (direction == RIGHT)
        this->Position += this->Right * velocity;\
    if (direction == LEFT)
        this->Position -= this->Right * velocity;
}

// Processes input received from a mouse input system. Expects the offset value in both the x and y direction.
void
Camera::ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true) {
    xoffset *= this->MouseSensitivity;
    yoffset *= this->MouseSensitivity;

    Yaw   += xoffset;
    Pitch += yoffset;

    // Make sure that when pitch is out of bounds, screen doesn't get flipped
    if (constrainPitch)
    {
        if (Pitch > 89.0f)
            Pitch = 89.0f;
        if (Pitch < -89.0f)
            Pitch = -89.0f;
    }

    // Update Front, Right and Up Vectors using the updated Euler angles
    updateCameraVectors();
}

// Processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
void
Camera::ProcessMouseScroll(float yoffset) {
    if (this->Zoom >= 1.0f && this->Zoom <= 45.0f)
        this->Zoom -= yoffset;
    if (this->Zoom <= 1.0f)
        this->Zoom = 1.0f;
    if (this->Zoom >= 45.0f)
        this->Zoom = 45.0f;
}

void
Camera::DoMovement(int direction, float deltaTime) {
     switch(direction){
        case 1:
            ProcessKeyboard(FORWARD, deltaTime);
            break;
        case 2:  
            ProcessKeyboard(BACKWARD, deltaTime);
            break;
        case 3:       
            ProcessKeyboard(LEFT, deltaTime);
            break;
        case 4:
            ProcessKeyboard(RIGHT, deltaTime);
            break;
     }
}



void Camera::updateCameraVectors()
{
    // Calculate the new Front vector
    glm::vec3 front;
    front.x = cos(glm::radians(this->Yaw)) * cos(glm::radians(this->Pitch));
    front.y = sin(glm::radians(this->Pitch));
    front.z = sin(glm::radians(this->Yaw)) * cos(glm::radians(this->Pitch));
    this->Front = glm::normalize(this->Front);
    // Also re-calculate the Right and Up vector
    this->Right = glm::normalize(glm::cross(this->Front, this->WorldUp));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
    this->Up = glm::normalize(glm::cross(this->Right, this->Front));
}

Camera::Camera(Camera const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;

	return ;
}

Camera::~Camera(void)
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Camera	&Camera::operator=(Camera const &rhs)
{
	std::cout << "Assignment operator called" << std::endl;
	this->Position = rhs.GetPosition();
    this->Front = rhs.GetFront();
    this->Up = rhs.GetUp();
    this->Right = rhs.GetRight();
    this->WorldUp = rhs.GetWorldUp();
    this->Yaw = rhs.GetYaw();
    this->Pitch = rhs.GetPitch();
    this->MovementSpeed = rhs.GetMovementSpeed();
    this->MouseSensitivity = rhs.GetMouseSensitivity();
    this->Zoom = rhs.GetZoom();
	return (*this);
}

glm::vec3
Camera::GetPosition() const{
    return (this->Position);
}

glm::vec3
Camera::GetFront() const{
    return (this->Front);
}

glm::vec3
Camera::GetUp() const{
    return (this->Up);
}

glm::vec3
Camera::GetRight() const{
    return (this->Right);
}

glm::vec3
Camera::GetWorldUp() const{
    return (this->WorldUp);
}

GLfloat
Camera::GetYaw() const{
    return (this->Yaw);
}

GLfloat
Camera::GetPitch() const{
    return (this->Pitch);
}

GLfloat
Camera::GetMovementSpeed() const{
    return (this->MovementSpeed);
}

GLfloat
Camera::GetMouseSensitivity() const{
    return (this->MouseSensitivity);
}

GLfloat
Camera::GetZoom() const{
    return (this->Zoom);
}

