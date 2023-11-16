cmake_minimum_required(VERSION 3.21)

# set the name of the project, and which language it uses
project(cpputil CXX)

set(CMAKE_CXX_STANDARD 20)

# fetches a library from a git-repo and makes it available.
include(FetchContent)
FetchContent_Declare(googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.13.0
  )
FetchContent_MakeAvailable(googletest)

find_package(fmt)

add_library(cpputil STATIC
  src/string_util.cc
)

target_include_directories(cpputil PUBLIC
  include)
target_include_directories(cpputil PUBLIC
  src)

target_link_libraries(cpputil PUBLIC
  fmt::fmt)

if (PROJECT_IS_TOP_LEVEL)
   add_subdirectory(test)
endif()
