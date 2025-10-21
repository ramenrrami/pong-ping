cmake_minimum_required(VERSION 3.10)
project(PongPing CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(RAYLIB_DIR "${CMAKE_SOURCE_DIR}/lib")

# Executable hier anlegen – damit es global existiert
add_executable(PongPing)

target_include_directories(PongPing PRIVATE
    "${CMAKE_SOURCE_DIR}/include"
    "${RAYLIB_DIR}"
)
if (WIN32)
    set(EXTRA_LIBS
        "${RAYLIB_DIR}/libraylib.a"
        winmm gdi32 opengl32
    )
else()
    set(EXTRA_LIBS
        "${RAYLIB_DIR}/libraylib.a"
        m pthread dl
    )
endif()

# Unterordner, die Dateien hinzufügen
add_subdirectory(src)

# Nachträgliche Einstellungen fürs Ziel
target_link_libraries(PongPing PRIVATE ${EXTRA_LIBS})
if(APPLE)
    target_link_libraries(PongPing
        PRIVATE
        "-framework Cocoa"
        "-framework IOKit"
        "-framework CoreVideo"
        "-framework CoreFoundation"
        "-framework CoreGraphics"
        "-framework CoreServices"
        "-framework Foundation"
        "-framework AppKit"
    )
endif()

set_target_properties(PongPing PROPERTIES
    VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
)

add_custom_command(TARGET PongPing POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:PongPing>/resources"
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_SOURCE_DIR}/resources" "$<TARGET_FILE_DIR:PongPing>/resources"
)


if (MSVC)
    target_compile_options(PongPing PRIVATE /W4)
else()
    target_compile_options(PongPing PRIVATE -Wall -Wextra -pedantic)
endif()
