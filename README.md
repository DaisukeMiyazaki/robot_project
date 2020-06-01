# robot_project

This is a repository for my robot project. All the work are currenly under progress.

# The basic idea

The basic idea of this is to integrate a ready-to-make, commercial robot-kit and Jetson nano from Nvidia, such that creating a semi-autonomous robot. 

Along the way, I also integrate sensors, such as cameras, sonic sensor and so forth if needed. 

The main language will be c, c++ and python. 

For the robot, I chose Metal Chassis Mecanum Wheel Robotic[https://osoyoo.com/2019/11/08/omni-direction-mecanum-wheel-robotic-kit-v1/]. It has 4 special wheels, so that it can move to any directions in x and y coordinate in theory.

This comes with Arduino micro controller( Arduino Mega2560), and thier IDE(which you can download it for free). This is written in c.

Jetson nano runs on Ubuntu OS, and has a powerful GPU that can execute machine learning computation faster than the CPU does. This can be used for image processing, object detection and so forth with some live video stream from a camera module. Even though at this point, I'm not sure at this point if computaion for those would be sufficient enough for Jetson nano. 

I'm considering to use ROS for combining all the features once they're all complete. 

I should be dealing with perception, localization, path-planning, vehicle control and system integration if I want it to have a full functional autonomous capability. This all depends on how much it can be done within the days to come, as well as all the potential limitation for hardware and hardware.


