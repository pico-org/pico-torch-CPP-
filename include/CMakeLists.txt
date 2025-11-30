# CMakeLists.txt for include directory
# This file handles the header files for the Pico-Torch-CPP project

# Get all header files in this directory
file(GLOB_RECURSE HEADER_FILES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp"
)

# Create a header-only library target
add_library(pico_torch_headers INTERFACE)

# Set the include directory for the target
target_include_directories(pico_torch_headers INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:include>
)

# Add header files to the target (for IDE support)
target_sources(pico_torch_headers INTERFACE
    $<BUILD_INTERFACE:${HEADER_FILES}>
)

# Set C++ standard requirements
target_compile_features(pico_torch_headers INTERFACE cxx_std_17)

# Optional: Install headers
if(INSTALL_HEADERS)
    install(FILES ${HEADER_FILES}
        DESTINATION include
        COMPONENT Development
    )
endif()

# Print header files found (for debugging)
message(STATUS "Found header files in include/:")
foreach(HEADER ${HEADER_FILES})
    get_filename_component(HEADER_NAME ${HEADER} NAME)
    message(STATUS "  - ${HEADER_NAME}")
endforeach()



