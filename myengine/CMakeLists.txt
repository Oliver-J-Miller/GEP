# CMakeList.txt : CMake project for game, include source and define
# project specific logic here.
#

cmake_minimum_required (VERSION 3.8)
project(MYENGINE)

include_directories(
	src
)


add_library(myengine
	src/myengine/Core.cpp
	src/myengine/Core.h
	src/myengine/Entity.cpp
	src/myengine/Entity.h
	src/myengine/Component.cpp
	src/myengine/Component.h
	src/myengine/myengine.h
)

add_executable(game
	src/game/main.cpp

)
target_link_libraries(game myengine)

