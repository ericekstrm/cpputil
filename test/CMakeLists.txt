
set(CTEST_OUTPUT_ON_FAILURE 1)
add_executable(cpputil-test
  vector.test.cc
  string.test.cc
  container.test.cc
  logger.test.cc
  json.test.cc
  meta.test.cc
  geometry.test.cc)
target_link_libraries(cpputil-test cpputil gtest gtest_main)
add_test(
  cpputil-test
  cpputil-test
  --rerun-failed
  --output-on-failure)
