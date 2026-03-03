#!/bin/bash
LOG_LEVEL=2
source /opt/ros/humble/setup.bash
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/oliver/workspace/mpc-rbt-student/build
./build/sender_node config.json
