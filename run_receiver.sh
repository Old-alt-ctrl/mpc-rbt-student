#!/bin/bash
./build/receiver_node config.json
source /opt/ros/humble/setup.bash
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/home/oliver/workspace/mpc-rbt-student/build
