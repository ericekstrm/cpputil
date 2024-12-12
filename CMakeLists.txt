cmake_minimum_required(VERSION 3.21)

# set the name of the project, and which language it uses
project(cpputil CXX)

include(CTest)
set(CTEST_OUTPUT_ON_FAILURE 1)

set(CMAKE_CXX_STANDARD 20)

# fetches a library from a git-repo and makes it available.
include(FetchContent)
FetchContent_Declare(googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.13.0
)
FetchContent_MakeAvailable(googletest)

FetchContent_Declare(fmt
  GIT_REPOSITORY https://github.com/fmtlib/fmt.git
  GIT_TAG        11.0.2
  # GIT_TAG        0c9fce2ffefecfdce794e1859584e25877b7b592 // 11.0.2
)
FetchContent_MakeAvailable(fmt)

add_library(cpputil STATIC
  src/string_util.cc
  src/geometry.cc
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
