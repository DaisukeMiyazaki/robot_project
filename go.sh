#!/bin/bash
catkin_make
source devel/setup.bash
echo "writing arduino"
echo "connect arduino on USB"

# Uploading arduino code from Jetson
#cd `dirname ${0}`/../platformio/ino01
#cd /home/daisuke/catkin_ws/src/arduino_pkg/platformio/ino01
cd /home/daisuke/catkin_ws/src/arduino_pkg/platformio/ino02
platformio run&
echo "wait until finishing uploading code to Arduino"
sleep 20

# Launching system nodes
echo "Launch other node"
#roslaunch arduino_pkg arduino_to_serial.launch
cd ~/catkin_ws
roslaunch launch/styx.launch

