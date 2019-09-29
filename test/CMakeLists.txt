find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(test-packet-counter test-packet-counter.cpp)
target_link_libraries(test-packet-counter ${GTEST_LIBRARIES} pthread tins gtest_main)

add_test(NAME test-packet-counter
         COMMAND test-packet-counter)
