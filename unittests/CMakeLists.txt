add_executable(cpputil_unittest
  test_mylib.cc
  )

target_link_libraries(cpputil_unittest cpputil gtest gtest_main)
