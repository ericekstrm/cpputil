cmake_minimum_required(VERSION 3.10)

# set the name of the project, and which language it uses
project(cpputil CXX)

# fetches a library from a git-repo and makes it available.
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.10.0
  )
FetchContent_MakeAvailable(googletest)

add_library(cpputil STATIC
  mylib.cc
  )

add_subdirectory(unittests)

