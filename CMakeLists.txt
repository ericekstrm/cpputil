cmake_minimum_required(VERSION 3.10)

# set the name of the project, and which language it uses
project(cpputil CXX)

# fetches a library from a git-repo and makes it available.
include(FetchContent)
FetchContent_Declare(googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.13.0
  )
FetchContent_MakeAvailable(googletest)

add_library(cpputil INTERFACE)

target_include_directories(cpputil INTERFACE
  include)
target_include_directories(cpputil INTERFACE
  src)

if (PROJECT_IS_TOP_LEVEL)
   add_subdirectory(test)
endif()
