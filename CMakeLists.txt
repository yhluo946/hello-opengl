cmake_minimum_required(VERSION 3.0.0)
project(hello VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(hello main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_library(
  glad
  SHARED
  glad/glad.c
)

include_directories(/usr/local/include)

link_directories(/usr/local/lib)

target_link_libraries(hello GLFW glad)

if (APPLE)
  # target_link_libraries(hello "-framework OpenGL")
endif()
