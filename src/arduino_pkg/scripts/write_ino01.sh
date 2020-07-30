#!/bin/bash
echo "writing arduino"
echo "connect arduino on USB"

cd `dirname ${0}`/../platformio/ino01
pwd
platformio run&
echo "wait until finishing uploading code to Arduino"
sleep 10
echo "Launch other node"
roslaunch arduino_pkg pubsub1.launch
