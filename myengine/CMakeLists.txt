# CMakeList.txt : CMake project for game, include source and define
# project specific logic here.
#

cmake_minimum_required (VERSION 3.8)
project(MYENGINE)

include_directories(
	src
	contrib/windows-cl-amd64/SDL2/include
	contrib/windows-cl-amd64/glew/include
)

link_directories(
 contrib/windows-cl-amd64/SDL2/lib
 contrib/windows-cl-amd64/glew/lib
)

add_library(myengine
	src/myengine/Core.cpp
	src/myengine/Core.h
	src/myengine/Entity.cpp
	src/myengine/Entity.h
	src/myengine/Component.cpp
	src/myengine/Component.h
	src/myengine/myengine.h

	src/myengine/TriangleRenderer.cpp
)

add_library(rend
  src/rend/Animation.cpp
  src/rend/Buffer.cpp
  src/rend/Mesh.cpp
  src/rend/ModelRenderer.cpp
  src/rend/RenderTexture.cpp
  src/rend/Renderer.cpp
  src/rend/Shader.cpp
  src/rend/Texture.cpp
  src/rend/rendmath.cpp
)


add_executable(game
	src/game/main.cpp

)

target_link_libraries(rend GLEW32 OpenGL32)
target_link_libraries(game myengine)
target_link_libraries(myengine rend SDL2)

