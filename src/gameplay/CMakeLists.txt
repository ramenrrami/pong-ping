# src/gameplay/CMakeLists.txt
cmake_policy(SET CMP0076 NEW)

target_sources(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/player.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/player.h
    ${CMAKE_CURRENT_SOURCE_DIR}/cpu_ai.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/cpu_ai.h
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
