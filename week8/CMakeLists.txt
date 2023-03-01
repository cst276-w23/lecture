cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
FetchContent_Declare(SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG 2.6.x
)
FetchContent_MakeAvailable(SFML)

project(Week8)

add_executable(
  Week8
  src/main.cpp
)

target_link_libraries(Week8 sfml-graphics)

if (WIN32 AND BUILD_SHARED_LIBS)
  add_custom_command(TARGET Week8 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:Week8> $<TARGET_FILE_DIR:Week8> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS Week8)
