
# Vulkan Engine README

This README provides detailed information about the Vulkan Engine project, its structure, and how to build and run the application.

## Table of Contents

1.  [Introduction]
2.  [Project Structure]
3.  [Dependencies]
4.  [Building and Running]
5.  [CMake Configuration]
6.  [License]

## Introduction

The Vulkan Engine is a graphics engine built using the Vulkan API. It is designed to showcase Vulkan's capabilities and provide a foundation for building graphics-intensive applications.

## Project Structure

The project is organized into several directories:

-   **src**: Contains the source code for the Vulkan Engine.
-   **shaders**: Includes Vulkan shader files.
-   **external**: Houses external dependencies like GLFW, GLM, and others.
-   **CMakeLists.txt**: Configuration file for CMake to build the project.
-   **main.cpp**: Main application file that initializes and runs the Vulkan Engine.

## Dependencies

The Vulkan Engine depends on the following libraries:

-   Vulkan SDK
-   [GLFW](https://www.glfw.org/)
-   GLM
-   stb
-   tinyobjloader

Ensure that these dependencies are installed and configured properly before building the project.

## Building and Running

Follow these steps to build and run the Vulkan Engine:

1.  **Clone the Repository:**
    
    ```bash 
    git clone <repository-url>
    ```
    ```bash
    cd VulkanEngine
    ```
    
2.  **Build the Project:**
    
    ```bash
    mkdir build
    ```
    ```bash
    cd build 
    ```
    ```bash
    cmake ..
    ```
    ```bash
    cmake --build .
    ```

    
3.  **Run the Application:**
    
    `./main` 
    
    This command executes the Vulkan Engine, and you should see the application window.
    

## CMake Configuration

The CMakeLists.txt file configures the project build. Here are some key configurations:

-   **Minimum CMake Version:**
   
    `cmake_minimum_required(VERSION 3.6)` 
    
-   **Project Information:**
    
    `project(VulkanEngine CXX)` 
    
-   **C++ Standard and Library Directories:**
    
    `set(CMAKE_CXX_STANDARD 17)
    set(LIB_FOLDER C:/Programmation/Libraries)` 
    
-   **Include Directories and External Dependencies:**

    `include_directories(
        ${PROJECT_SOURCE_DIR}/src
        ${LIB_FOLDER}/glm
        ${LIB_FOLDER}/glfw-3.3.9.bin.WIN64/include
        ${LIB_FOLDER}/stb
        ${LIB_FOLDER}/tinyobjloader
        $ENV{VULKAN_SDK}/Include
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    )` 
    
-   **Link Directories and Vulkan Library:**

    
    `link_directories($ENV{VULKAN_SDK}/Lib)
    link_directories(${LIB_FOLDER}/glfw-3.3.9.bin.WIN64/lib-vc2022)` 
    
-   **Find Vulkan Package:**

    `find_package(Vulkan REQUIRED)` 
    
-   **Executable and Linking:**

    `add_executable(main ${all_SRCS})
    target_link_libraries(main vulkan-1 ${LIB_FOLDER}/glfw-3.3.9.bin.WIN64/lib-vc2022/glfw3.lib)` 
    

## License

This project is licensed under the MIT License.

Feel free to explore and modify the Vulkan Engine according to your needs! If you encounter any issues or have suggestions, please open an issue on the GitHub repository.