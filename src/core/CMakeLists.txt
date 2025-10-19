# src/core/CMakeLists.txt
cmake_policy(SET CMP0076 NEW)

target_sources(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/camera.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/camera.h
    ${CMAKE_CURRENT_SOURCE_DIR}/config.h
    ${CMAKE_CURRENT_SOURCE_DIR}/fontloader.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/fontloader.h
    ${CMAKE_CURRENT_SOURCE_DIR}/fontmanager.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/fontmanager.h
    ${CMAKE_CURRENT_SOURCE_DIR}/fonts.h
    ${CMAKE_CURRENT_SOURCE_DIR}/game.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/game.h
    ${CMAKE_CURRENT_SOURCE_DIR}/renderer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/renderer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/scale.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/scale.h
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
