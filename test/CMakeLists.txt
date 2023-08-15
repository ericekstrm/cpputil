add_executable(cpputil-vector-test
  vector.test.cc)
target_link_libraries(cpputil-vector-test cpputil gtest gtest_main)

add_executable(cpputil-container-test
  container.test.cc)
target_link_libraries(cpputil-container-test cpputil gtest gtest_main)

#target_include_directories(cpputil-vector-test PUBLIC
#  ../include
#  ../src)

