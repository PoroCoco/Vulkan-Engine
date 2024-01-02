cmake_minimum_required(VERSION 3.6)

project(VulkanEngine CXX)
set(CMAKE_CXX_STANDARD 17)
set(LIB_FOLDER C:/Programmation/Libraries)

include_directories(
        ${PROJECT_SOURCE_DIR}/src
)

file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

include_directories(${LIB_FOLDER}/glm)
include_directories(${LIB_FOLDER}/glfw-3.3.9.bin.WIN64/include)
include_directories(${LIB_FOLDER}/stb)
include_directories(${LIB_FOLDER}/tinyobjloader)
include_directories($ENV{VULKAN_SDK}/Include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

link_directories($ENV{VULKAN_SDK}/Lib)
link_directories(${LIB_FOLDER}/glfw-3.3.9.bin.WIN64/lib-vc2022)

find_package(Vulkan REQUIRED)

add_executable(main ${all_SRCS})

target_link_libraries(main vulkan-1 ${LIB_FOLDER}/glfw-3.3.9.bin.WIN64/lib-vc2022/glfw3.lib)
set_target_properties(main PROPERTIES LINK_FLAGS "/NODEFAULTLIB:MSVCRT")