# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "count_to_odom: 1 messages, 0 services")

set(MSG_I_FLAGS "-Icount_to_odom:/home/daisuke/catkin_ws/src/count_to_odom/msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg;-Itf:/opt/ros/melodic/share/tf/cmake/../msg;-Inav_msgs:/opt/ros/melodic/share/nav_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/melodic/share/geometry_msgs/cmake/../msg;-Isensor_msgs:/opt/ros/melodic/share/sensor_msgs/cmake/../msg;-Iactionlib_msgs:/opt/ros/melodic/share/actionlib_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(count_to_odom_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/daisuke/catkin_ws/src/count_to_odom/msg/count2odom.msg" NAME_WE)
add_custom_target(_count_to_odom_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "count_to_odom" "/home/daisuke/catkin_ws/src/count_to_odom/msg/count2odom.msg" "nav_msgs/Odometry:geometry_msgs/Twist:geometry_msgs/PoseWithCovariance:geometry_msgs/Vector3:geometry_msgs/Pose:geometry_msgs/TwistWithCovariance:std_msgs/Header:geometry_msgs/Quaternion:geometry_msgs/Point"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(count_to_odom
  "/home/daisuke/catkin_ws/src/count_to_odom/msg/count2odom.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/nav_msgs/cmake/../msg/Odometry.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/PoseWithCovariance.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/TwistWithCovariance.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/count_to_odom
)

### Generating Services

### Generating Module File
_generate_module_cpp(count_to_odom
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/count_to_odom
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(count_to_odom_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(count_to_odom_generate_messages count_to_odom_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/daisuke/catkin_ws/src/count_to_odom/msg/count2odom.msg" NAME_WE)
add_dependencies(count_to_odom_generate_messages_cpp _count_to_odom_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(count_to_odom_gencpp)
add_dependencies(count_to_odom_gencpp count_to_odom_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS count_to_odom_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(count_to_odom
  "/home/daisuke/catkin_ws/src/count_to_odom/msg/count2odom.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/nav_msgs/cmake/../msg/Odometry.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/PoseWithCovariance.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/TwistWithCovariance.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/count_to_odom
)

### Generating Services

### Generating Module File
_generate_module_eus(count_to_odom
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/count_to_odom
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(count_to_odom_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(count_to_odom_generate_messages count_to_odom_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/daisuke/catkin_ws/src/count_to_odom/msg/count2odom.msg" NAME_WE)
add_dependencies(count_to_odom_generate_messages_eus _count_to_odom_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(count_to_odom_geneus)
add_dependencies(count_to_odom_geneus count_to_odom_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS count_to_odom_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(count_to_odom
  "/home/daisuke/catkin_ws/src/count_to_odom/msg/count2odom.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/nav_msgs/cmake/../msg/Odometry.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/PoseWithCovariance.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/TwistWithCovariance.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/count_to_odom
)

### Generating Services

### Generating Module File
_generate_module_lisp(count_to_odom
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/count_to_odom
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(count_to_odom_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(count_to_odom_generate_messages count_to_odom_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/daisuke/catkin_ws/src/count_to_odom/msg/count2odom.msg" NAME_WE)
add_dependencies(count_to_odom_generate_messages_lisp _count_to_odom_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(count_to_odom_genlisp)
add_dependencies(count_to_odom_genlisp count_to_odom_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS count_to_odom_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(count_to_odom
  "/home/daisuke/catkin_ws/src/count_to_odom/msg/count2odom.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/nav_msgs/cmake/../msg/Odometry.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/PoseWithCovariance.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/TwistWithCovariance.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/count_to_odom
)

### Generating Services

### Generating Module File
_generate_module_nodejs(count_to_odom
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/count_to_odom
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(count_to_odom_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(count_to_odom_generate_messages count_to_odom_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/daisuke/catkin_ws/src/count_to_odom/msg/count2odom.msg" NAME_WE)
add_dependencies(count_to_odom_generate_messages_nodejs _count_to_odom_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(count_to_odom_gennodejs)
add_dependencies(count_to_odom_gennodejs count_to_odom_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS count_to_odom_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(count_to_odom
  "/home/daisuke/catkin_ws/src/count_to_odom/msg/count2odom.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/nav_msgs/cmake/../msg/Odometry.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Twist.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/PoseWithCovariance.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/TwistWithCovariance.msg;/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/melodic/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/count_to_odom
)

### Generating Services

### Generating Module File
_generate_module_py(count_to_odom
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/count_to_odom
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(count_to_odom_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(count_to_odom_generate_messages count_to_odom_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/daisuke/catkin_ws/src/count_to_odom/msg/count2odom.msg" NAME_WE)
add_dependencies(count_to_odom_generate_messages_py _count_to_odom_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(count_to_odom_genpy)
add_dependencies(count_to_odom_genpy count_to_odom_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS count_to_odom_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/count_to_odom)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/count_to_odom
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(count_to_odom_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET tf_generate_messages_cpp)
  add_dependencies(count_to_odom_generate_messages_cpp tf_generate_messages_cpp)
endif()
if(TARGET nav_msgs_generate_messages_cpp)
  add_dependencies(count_to_odom_generate_messages_cpp nav_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/count_to_odom)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/count_to_odom
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(count_to_odom_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET tf_generate_messages_eus)
  add_dependencies(count_to_odom_generate_messages_eus tf_generate_messages_eus)
endif()
if(TARGET nav_msgs_generate_messages_eus)
  add_dependencies(count_to_odom_generate_messages_eus nav_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/count_to_odom)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/count_to_odom
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(count_to_odom_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET tf_generate_messages_lisp)
  add_dependencies(count_to_odom_generate_messages_lisp tf_generate_messages_lisp)
endif()
if(TARGET nav_msgs_generate_messages_lisp)
  add_dependencies(count_to_odom_generate_messages_lisp nav_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/count_to_odom)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/count_to_odom
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(count_to_odom_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET tf_generate_messages_nodejs)
  add_dependencies(count_to_odom_generate_messages_nodejs tf_generate_messages_nodejs)
endif()
if(TARGET nav_msgs_generate_messages_nodejs)
  add_dependencies(count_to_odom_generate_messages_nodejs nav_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/count_to_odom)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/count_to_odom\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/count_to_odom
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(count_to_odom_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET tf_generate_messages_py)
  add_dependencies(count_to_odom_generate_messages_py tf_generate_messages_py)
endif()
if(TARGET nav_msgs_generate_messages_py)
  add_dependencies(count_to_odom_generate_messages_py nav_msgs_generate_messages_py)
endif()
