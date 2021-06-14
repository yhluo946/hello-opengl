cmake_minimum_required(VERSION 3.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(CTest)
enable_testing()

file(GLOB needed_files "src/*.cpp" "include/*.hpp")

add_executable(hello main.cpp ${needed_files})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)

add_library(
  glad
  SHARED
  glad/glad.c
)

find_library(
  ASSIMP_DIR
  name assimp
  HINTS /Users/luoyuhao/Downloads/assimp-5.0.1/lib
  NO_DEFAULT_PATH
)

include_directories(/usr/local/include include /Users/luoyuhao/Downloads/assimp-5.0.1/include)

link_directories(/usr/local/lib)

target_link_libraries(
  hello
  GLFW
  glad 
  ${ASSIMP_DIR}
  # /Users/luoyuhao/Downloads/assimp-5.0.1/lib/libassimp.dylib
)

if (APPLE)
  # target_link_libraries(hello "-framework OpenGL")
endif()
