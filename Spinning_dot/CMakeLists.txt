cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
set(SHOW_CONSOLE False)
if (WIN32 AND NOT ${SHOW_CONSOLE})
    set(EXE_EXTRA "WIN32")
else()
    set(EXE_EXTRA "")
endif()
add_executable (Spinning_dot ${EXE_EXTRA} "App.c" "App.h" "Defines.h" "main.c" "Circle.h" "Input.h" "Input.c" "Circle.c" "Debug.c")

# Libs
target_include_directories(Spinning_dot
    PRIVATE "${CMAKE_SOURCE_DIR}/${SDL2_INCLUDE}"
    PRIVATE "${CMAKE_SOURCE_DIR}/${SDL2_ttf_INCLUDE}"
)
target_link_directories(Spinning_dot
    PRIVATE "${CMAKE_SOURCE_DIR}/${SDL2_LIB}"
    PRIVATE "${CMAKE_SOURCE_DIR}/${SDL2_ttf_LIB}"
)
target_link_libraries(Spinning_dot
    PRIVATE ${SDL2_LIBS}
    PRIVATE ${SDL2_ttf_LIBS}
)

#Tip for myself in order to understand what this is
#CMAKE_COMMAND = The full path to the cmake executable.
#The whole command is this: cmake -E copy_if_different <file1>... <dest>
#<TARGET_FILE_DIR> = a cmake generator expression (Directory of the binary file)
#VERBATIM = Escape the argument correctly
add_custom_command(
    TARGET
        Spinning_dot POST_BUILD
    COMMAND
        ${CMAKE_COMMAND} -E copy_if_different "${SDL2_DLL}" $<TARGET_FILE_DIR:Spinning_dot>
    COMMAND
        ${CMAKE_COMMAND} -E copy_if_different "${SDL2_ttf_DLL}" $<TARGET_FILE_DIR:Spinning_dot>
    COMMAND
        ${CMAKE_COMMAND} -E copy_if_different "${ASSETS_NEEDED}" $<TARGET_FILE_DIR:Spinning_dot>
    VERBATIM)