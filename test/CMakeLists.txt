add_executable(cpputil-test
  vector.test.cc
  string.test.cc
  container.test.cc
  logger.test.cc
  json.test.cc
  geometry.test.cc)
target_link_libraries(cpputil-test cpputil gtest gtest_main)
