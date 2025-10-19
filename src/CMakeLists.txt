# src/CMakeLists.txt
cmake_policy(SET CMP0076 NEW)

target_sources(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

add_subdirectory(core)
add_subdirectory(gameplay)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
