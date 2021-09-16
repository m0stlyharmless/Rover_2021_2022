#!/bin/bash

docker run --net=host -e DISPLAY=:0 --mount src=$HOME/Github/Rover_2020_2021/,target=/home/rover/Github/Rover_2020_2021,type=bind -t -i osumrc
