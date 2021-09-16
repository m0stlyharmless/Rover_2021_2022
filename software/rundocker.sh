#!/bin/bash

docker run --mount src=$HOME/Github/Rover_2020_2021/,target=/home/rosuser/Github/Rover_2020_2021,type=bind -t -i osumrc
