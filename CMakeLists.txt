# CMakeLists.txt for Pico-Torch-CPP project
cmake_minimum_required(VERSION 3.16)

# Project name and version
project(PicoTorchCPP 
    VERSION 1.0.0
    DESCRIPTION "A lightweight C++ tensor library"
    LANGUAGES CXX
)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set build type if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Compiler flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Wextra")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

# Add include directory
add_subdirectory(include)

# Add source directory (if you have library sources and CMakeLists.txt)
if(EXISTS "${CMAKE_SOURCE_DIR}/src/CMakeLists.txt")
    add_subdirectory(src)
endif()

# Find all source files in the root directory for the main executable
file(GLOB MAIN_SOURCES 
    "${CMAKE_SOURCE_DIR}/*.cpp"
    "${CMAKE_SOURCE_DIR}/*.cc"
    "${CMAKE_SOURCE_DIR}/*.cxx"
)

# Create executable if main source files are found
if(MAIN_SOURCES)
    # Get the first main source file for the executable name
    list(GET MAIN_SOURCES 0 FIRST_MAIN)
    get_filename_component(MAIN_NAME ${FIRST_MAIN} NAME_WE)
    
    # Create executable
    add_executable(${MAIN_NAME} ${MAIN_SOURCES})
    
    # Link with header library
    target_link_libraries(${MAIN_NAME} PRIVATE pico_torch_headers)
    
    # Set output directory
    set_target_properties(${MAIN_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    )
    
    message(STATUS "Created executable: ${MAIN_NAME}")
    message(STATUS "Source files: ${MAIN_SOURCES}")
else()
    message(STATUS "No main source files found in root directory")
endif()

# Optional: Create a sample main.cpp if none exists
if(NOT EXISTS "${CMAKE_SOURCE_DIR}/main.cpp")
    message(STATUS "Consider creating a main.cpp file in the root directory")
endif()

# Print build information
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Install prefix: ${CMAKE_INSTALL_PREFIX}")
