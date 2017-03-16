cmake_minimum_required(VERSION 2.8)
project(actic)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Werror")
add_library(${PROJECT_NAME}_lib STATIC src/Goal.cpp src/GoalManager.cpp src/GoalFactory.cpp)
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_lib)

#gtest
set(PROJECT_TEST_NAME ${PROJECT_NAME}_test)
enable_testing()

if(WIN32)
	INCLUDE_DIRECTORIES(googletest src)
	LINK_DIRECTORIES(D:/projects/iplan/googletest)
endif(WIN32)

if(UNIX)
	find_package(GTest REQUIRED)
	include_directories(${GTEST_INCLUDE_DIRS})
endif(UNIX)

include_directories(src)
file(GLOB TEST_SRC_FILES test/*.cpp)
add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})
target_link_libraries(${PROJECT_TEST_NAME} gtest pthread)
target_link_libraries(${PROJECT_TEST_NAME} ${PROJECT_NAME}_lib)
