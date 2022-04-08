# CMakeList.txt : CMake project for Spinning_dot, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
#$<$<STREQUAL:${WIN32},True>:WIN32>
add_executable (Spinning_dot WIN32 "App.c" "App.h" "Defines.h" "main.c")

# TODO: Add tests and install targets if needed.
target_include_directories(Spinning_dot PRIVATE "${CMAKE_SOURCE_DIR}/${SDL2_INCLUDE}")
target_link_directories(Spinning_dot PRIVATE "${CMAKE_SOURCE_DIR}/${SDL2_LIB}")
target_link_libraries(Spinning_dot PRIVATE ${SDL2_LIBS})

#Tip for myself in order to understand what this is
#CMAKE_COMMAND = The full path to the cmake executable.
#The whole command is this: cmake -E copy_if_different <file1>... <dest>
#<TARGET_FILE_DIR> = a cmake generator expression (Directory of the binary file)
#VERBATIM = Escape the argument correctly
add_custom_command(
    TARGET
        Spinning_dot POST_BUILD
    COMMAND
        ${CMAKE_COMMAND} -E copy_if_different "${CMAKE_SOURCE_DIR}/${SDL2_LIB}/SDL2.dll" $<TARGET_FILE_DIR:Spinning_dot>
    #COMMENT "Copying SDL2.dll\nfrom: \"${PROJECT_SOURCE_DIR}/SDL2/lib/${EXE_BITS}/SDL2.dll\"\nto: \"$<TARGET_FILE_DIR:Spinning_dot>\""#This did not work??
    VERBATIM)# <-- out-file