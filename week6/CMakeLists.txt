cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
FetchContent_Declare(SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG 2.6.x
)
FetchContent_MakeAvailable(SFML)

project(Week6)

add_executable(
  Week6
  src/main.cpp
)

target_link_libraries(Week6 sfml-graphics)

if (WIN32 AND BUILD_SHARED_LIBS)
  add_custom_command(TARGET Week6 POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:Week6> $<TARGET_FILE_DIR:Week6> COMMAND_EXPAND_LISTS)
endif()

install(TARGETS Week6)
