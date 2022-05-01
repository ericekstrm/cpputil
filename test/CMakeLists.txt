add_executable(cpputil-vector-test
  vector.test.cc)

#target_include_directories(cpputil-vector-test PUBLIC
#  ../include
#  ../src)

target_link_libraries(cpputil-vector-test cpputil gtest gtest_main)
