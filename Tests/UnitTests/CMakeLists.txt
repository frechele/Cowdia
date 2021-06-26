# Target name
set(target UnitTests)

# Includes
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Sources
file(GLOB_RECURSE sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cc)

add_executable(${target} ${sources})

target_compile_definitions(${target}
    PRIVATE
    
    PUBLIC
    ${DEFAULT_COMPILE_DEFINITIONS}
    
    INTERFACE
)

target_compile_options(${target}
    PRIVATE
    
    PUBLIC
    ${DEFAULT_COMPILE_OPTIONS}
    
    INTERFACE
)

set_target_properties(${target}
    PROPERTIES
    ${DEFAULT_PROJECT_OPTIONS}
)

target_link_libraries(${target}
    PRIVATE

    PUBLIC
    ${DEFAULT_LINKER_OPTIONS}

    INTERFACE
)
