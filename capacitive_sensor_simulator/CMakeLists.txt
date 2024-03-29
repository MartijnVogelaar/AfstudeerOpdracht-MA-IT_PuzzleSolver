cmake_minimum_required(VERSION 3.7.2)
project(capacitive_sensor_simulator)
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  # using Clang
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  add_compile_options( -Wall -Wconversion -Wextra -std=c++14)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
  # using Intel C++
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  set(CMAKE_CXX_STANDARD 14)
  set(CMAKE_CXX_EXTENSIONS OFF)
endif()

find_package(catkin REQUIRED COMPONENTS
        gazebo_msgs
        gazebo_plugins
        gazebo_ros
        message_runtime
        message_generation
        roscpp
        sensor_msgs
        std_msgs
        capacitive_sensor
        )
        
find_package(Boost REQUIRED COMPONENTS
  system
  filesystem
  unit_test_framework
  regex
  signals
)

find_package(gazebo REQUIRED)

include_directories(
        include
        SYSTEM # everything after system is seen as system include (no compiler warnings)
        ${GAZEBO_INCLUDE_DIRS}
        ${catkin_INCLUDE_DIRS})

catkin_package()
        
add_executable(${PROJECT_NAME}_plugin src/main.cpp src/CapacitiveSensor.cpp)

add_dependencies(${PROJECT_NAME}_plugin ${catkin_EXPORTED_TARGETS})

		
target_link_libraries(${PROJECT_NAME}_plugin
        ${GAZEBO_LIBRARIES}
        ${catkin_LIBRARIES}
        )