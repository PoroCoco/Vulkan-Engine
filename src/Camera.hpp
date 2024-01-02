#define GLFW_INCLUDE_VULKAN
#define GLM_FORCE_RADIANS
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
public:
    Camera(glm::vec3 position);

    glm::mat4 getViewMatrix();

    void processKeyboard(int direction, float deltaTime);

    void processMouseMovement(float xOffset, float yOffset, GLboolean constrainPitch = true);

    void processMouseButton(int button, bool pressed);

    enum Direction {
        FORWARD = 1,
        BACKWARD = 2,
        LEFT = 4,
        RIGHT = 8,
    };

    enum MouseButton {
        MOUSE_LEFT = 1,
        MOUSE_RIGHT = 2,
        MOUSE_MIDDLE = 4,
    };


private:
    static constexpr float SPEED = 5.0f;
    static constexpr float SENSITIVITY = 0.1f;

    glm::vec3 position;
    glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 right;
    glm::vec3 front;
    float yaw;
    float pitch;
    
    bool rightMouseButtonPressed = false;
    glm::mat4 viewMatrix;

    void updateCameraVectors();
    void updateCameraViewMatrix();
};
