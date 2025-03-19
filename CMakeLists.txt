cmake_minimum_required(VERSION 3.24.2)
project(testproj CXX)

#add_executable(${PROJECT_NAME} main.cpp)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

#add_executable(
#  hello_test
#  hello_test.cc
#)
add_library(candle candle.cpp)
add_executable(${PROJECT_NAME} main.cpp)


target_link_libraries(
  ${PROJECT_NAME}
  PRIVATE
  candle
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

