cmake_minimum_required(VERSION 3.8)
project(polaris_example)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)

## INCLUDE(S)
include_directories(include)
include_directories(SYSTEM ${EIGEN3_INCLUDE_DIRS})

# executables
add_executable(error_metrics src/error_metrics.cpp)

# dependencies
ament_target_dependencies(error_metrics rclcpp tf2 tf2_ros)

target_link_libraries(error_metrics Eigen3::Eigen)

install(TARGETS error_metrics
  DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY
  launch
  DESTINATION share/${PROJECT_NAME}/
)

ament_package()
