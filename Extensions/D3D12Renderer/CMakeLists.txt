# Target name
set(target D3D12Renderer)

include(${CMAKE_CURRENT_SOURCE_DIR}/../../CMake/FindD3D12.cmake)

# Includes
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${D3D12_INCLUDE_DIRS})

# Sources
file(GLOB_RECURSE sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cc)

add_library(${target} SHARED ${sources})

target_compile_definitions(${target}
    PRIVATE
    ${DEFAULT_COMPILE_DEFINITIONS}
)

target_compile_options(${target}
    PRIVATE
    ${DEFAULT_COMPILE_OPTIONS}
)

set_target_properties(${target}
    PROPERTIES
    ${DEFAULT_PROJECT_OPTIONS}
)

target_link_libraries(${target}
    PRIVATE
    ${DEFAULT_LINKER_OPTIONS}
    ${D3D12_LIB_NAMES}
    Cowdia
)

# Install
install(TARGETS ${target} DESTINATION lib)
