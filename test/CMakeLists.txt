file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false *.h *.cpp)

# enable_testing()

add_executable(${projectTest} ${TEST_SOURCES})
# add_test(NAME ${projectTest} COMMAND ${projectTest})
target_link_libraries(${projectTest} PUBLIC ${projectLib} gtest gtest_main)

# include(googletest)
# gtest_discover_tests(${projectTest})