#include <Camera.hpp>


Camera::Camera(glm::vec3 position)
    :yaw(0.0f),pitch(0.0f)
{
    this->position = position;
    updateCameraVectors();
}

glm::mat4 Camera::getViewMatrix() {
    return viewMatrix;
}

void Camera::processKeyboard(int direction, float deltaTime) {
    float velocity = SPEED * deltaTime;
    if (direction & FORWARD)
        position += front * velocity;
    if (direction & BACKWARD)
        position -= front * velocity;
    if (direction & LEFT)
        position -= right * velocity;
    if (direction & RIGHT)
        position += right * velocity;

    updateCameraViewMatrix();
}

void Camera::processMouseMovement(float xOffset, float yOffset, GLboolean constrainPitch) {
    if (!rightMouseButtonPressed) return;

    xOffset *= SENSITIVITY;
    yOffset *= SENSITIVITY;

    yaw += xOffset;
    pitch -= yOffset;

    // Constrain pitch to avoid flipping
    if (constrainPitch) {
        if (pitch > 89.0f)
            pitch = 89.0f;
        if (pitch < -89.0f)
            pitch = -89.0f;
    }

    updateCameraVectors();
}

void Camera::processMouseButton(int button, bool pressed){
    if (button & MOUSE_RIGHT){
        if (pressed){
            // Right mouse button is pressed
            rightMouseButtonPressed = true;
        }else{
            // Right mouse button is released
            rightMouseButtonPressed = false;
        }
    }
}

void Camera::updateCameraVectors() {
    // Calculate the new front vector
    glm::vec3 newFront;
    newFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    newFront.y = sin(glm::radians(pitch));
    newFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    front = glm::normalize(newFront);

    // Recalculate right and up vectors
    right = glm::normalize(glm::cross(front, glm::vec3(0.0f, 1.0f, 0.0f)));
    up = glm::normalize(glm::cross(right, front));

    updateCameraViewMatrix();
}

void Camera::updateCameraViewMatrix() {
    viewMatrix = glm::lookAt(position, position+front, up);
}
