cmake_minimum_required(VERSION 3.10)

project(googletest-test)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.10.0
  )
FetchContent_MakeAvailable(googletest)

# Specifies an executable.
# add_executable(<name> <item>
#     - name is the name of the executable
#     - item is a source file
add_executable(run main.cc)

# Specifies libraries to use when linking.
# target_link_libraries(<target> <item> ...)
#      - target is the executable created with add_executable.
#      - item is a library. Must be created with add_library, or be imported.
target_link_libraries(run gtest gtest_main)
