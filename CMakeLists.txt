cmake_minimum_required(VERSION 3.10)
project(PongPing)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# === Quelldateien ===
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
)
file(GLOB_RECURSE HDR_FILES CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/include/*.h"
    "${CMAKE_SOURCE_DIR}/include/*.hpp"
)

add_executable(${PROJECT_NAME} ${SRC_FILES} ${HDR_FILES})

# === Raylib Setup ===
set(RAYLIB_DIR "${CMAKE_SOURCE_DIR}/lib")

# Include-Ordner (wo raylib.h liegt)
target_include_directories(${PROJECT_NAME} PRIVATE
    "${CMAKE_SOURCE_DIR}/include"
    "${RAYLIB_DIR}"
)

# === Raylib und Systembibliotheken ===
if (WIN32)
    target_link_libraries(${PROJECT_NAME}
        "${RAYLIB_DIR}/libraylib.a"  # <-- direkter Pfad zur Datei
        winmm
        gdi32
        opengl32
    )
else()
    target_link_libraries(${PROJECT_NAME}
        "${RAYLIB_DIR}/libraylib.a"
        m
        pthread
        dl
    )
endif()

# === Compiler-Warnungen ===
if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic)
endif()
