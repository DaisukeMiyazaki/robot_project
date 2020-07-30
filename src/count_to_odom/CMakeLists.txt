cmake_minimum_required(VERSION 3.0.2)
project(count_to_odom)

#add_executable(count_to_odom src/main.cpp)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  tf
  nav_msgs
  message_generation
)


## Generate messages in the 'msg' folder
add_message_files(
   FILES
   count2odom.msg
)

## Generate added messages and services with any dependencies listed here
generate_messages(
   DEPENDENCIES
   std_msgs
   tf
   nav_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES count_to_odom
#  CATKIN_DEPENDS roscpp std_msgs
#  DEPENDS system_lib
  CATKIN_DEPENDS message_runtime roscpp std_msgs nav_msgs tf
)

###########
## Build ##
###########

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(count_to_odomNode src/count_to_odom.cpp)
target_link_libraries(count_to_odomNode ${catkin_LIBRARIES})

