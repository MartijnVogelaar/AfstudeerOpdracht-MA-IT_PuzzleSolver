cmake_minimum_required(VERSION 3.7.2)
project(capacitive_sensor_simulator)
add_compile_options(-Wall -Wconversion -Wextra -std=c++14)
SET(GCC_OPENCV_FLAGS "-lopencv_core -lopencv_highgui")
SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_OPENCV_FLAGS}")

find_package(catkin REQUIRED COMPONENTS
        gazebo_msgs
        gazebo_plugins
        gazebo_ros
        message_runtime
        message_generation
        roscpp
        sensor_msgs
        std_msgs)
        
find_package(Boost REQUIRED COMPONENTS
  system
  filesystem
  unit_test_framework
  regex
  signals
)

find_package(gazebo REQUIRED)
add_message_files(
  FILES
  capacitive_sensor_simulator_measurements.msg
)

generate_messages(
  DEPENDENCIES
  std_msgs
)

#Enable CTest which is used for the codecoverage
include(CTest)
enable_testing()

link_directories(${GAZEBO_LIBRARY_DIRS})

include_directories(
        include
        SYSTEM # everything after system is seen as system include (no compiler warnings)
        ${GAZEBO_INCLUDE_DIRS}
        ${catkin_INCLUDE_DIRS})
		
catkin_package(
    DEPENDS
    message_runtime
    roscpp
    gazebo_ros
    sensor_interfaces)

add_executable(${PROJECT_NAME}_plugin src/main.cpp src/CapacitiveSensor.cpp)

add_dependencies(${PROJECT_NAME}_plugin ${catkin_EXPORTED_TARGETS})

		
target_link_libraries(${PROJECT_NAME}_plugin
        ${GAZEBO_LIBRARIES}
        ${catkin_LIBRARIES}
        ${OpenCV_LIBS}
        )