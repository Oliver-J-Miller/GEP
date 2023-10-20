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
	src/myengine/NativeWindow.h
	src/myengine/NativeWindow.cpp
	src/myengine/TriangleRenderer.h
	src/myengine/TriangleRenderer.cpp
)

add_library(rend
  src/rend/Animation.cpp
  src/rend/Animation.h
  src/rend/Buffer.cpp
  src/rend/Buffer.h
  src/rend/Debug.cpp
  src/rend/Debug.h
  src/rend/Exception.h
  src/rend/Face.h
  src/rend/Font.cpp
  src/rend/Font.h
  src/rend/glm
  src/rend/Mesh.cpp
  src/rend/Mesh.h
  src/rend/Model.cpp
  src/rend/Model.h
  src/rend/ModelShader.cpp
  src/rend/ModelShader.h
  src/rend/rend.h
  src/rend/Renderer.h
  src/rend/RenderTexture.cpp
  src/rend/RenderTexture.h
  src/rend/rendfltk.h
  src/rend/rendgl.h
  src/rend/rendmath.cpp
  src/rend/rendmath.h
  src/rend/rendsdl.h
  src/rend/Shader.cpp
  src/rend/Shader.h
  src/rend/stb_image.h
  src/rend/TextShader.cpp
  src/rend/TextShader.h
  src/rend/Texture.cpp
  src/rend/Texture.h
  src/rend/utils.cpp
  src/rend/utils.h

)


add_executable(game
	src/game/main.cpp

)

target_link_libraries(rend GLEW32 OpenGL32)
target_link_libraries(game myengine)
target_link_libraries(myengine rend SDL2)

