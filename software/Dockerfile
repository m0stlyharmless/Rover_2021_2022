from ros:kinetic

run sed -i 's@http://archive.ubuntu.com/ubuntu/@http://ubuntu.osuosl.org/ubuntu@g' /etc/apt/sources.list

run useradd -ms /bin/bash rosuser

arg PROJECT_DIR=Rover_2020_2021
arg HOME_PATH=/home/rosuser

user rosuser
workdir $HOME_PATH

volume /home/rosuser/Github/$PROJECT_DIR

run mkdir -p /home/rosuser/catkin_workspace/src

add ground_station_setup.sh $HOME_PATH/ground_station_setup.sh

run bash ground_station_setup.sh

run rm ground_station_setup.sh

