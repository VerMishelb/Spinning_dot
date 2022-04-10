# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("Spinning_dot")

#Global (technically) variables
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 17)
if (CMAKE_SIZEOF_VOID_P EQUAL 8)#Check whether the size of any pointer is 8 bytes or not
	set(EXE_BITS "x64")
else()
	set(EXE_BITS "x86")
endif()

#Set some libs manually because I don't trust packet manager on Windows, especially without internet
#{CMAKE_SOURCE_DIR} can be used to get the root but here it's not needed
set(SDL2_INCLUDE "libs/SDL2/include/")
set(SDL2_LIB "libs/SDL2/lib/${EXE_BITS}/")
set(SDL2_LIBS SDL2 SDL2main)
set(SDL2_DLL "${CMAKE_SOURCE_DIR}/${SDL2_LIB}/SDL2.dll")

set(SDL2_ttf_INCLUDE "libs/SDL2_ttf/include/")
set(SDL2_ttf_LIB "libs/SDL2_ttf/lib/${EXE_BITS}/")
set(SDL2_ttf_LIBS SDL2_ttf)
set(SDL2_ttf_DLL "${CMAKE_SOURCE_DIR}/${SDL2_ttf_LIB}/SDL2_ttf.dll")

message(SDL2_INCLUDE= ${SDL2_INCLUDE})
message(SDL2_LIB= ${SDL2_LIB})
message(SDL2_LIBS= ${SDL2_LIBS})

# Include sub-projects.
add_subdirectory ("Spinning_dot")
