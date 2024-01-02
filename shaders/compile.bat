@echo off
set VULKAN_SDK=%VULKAN_SDK%

if not defined VULKAN_SDK (
    echo Error: VULKAN_SDK environment variable is not set.
    pause
    exit /b 1
)

@echo on
%VULKAN_SDK%\Bin\glslc.exe shader.vert -o vert.spv
%VULKAN_SDK%\Bin\glslc.exe shader.frag -o frag.spv
@echo off
pause