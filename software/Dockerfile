from ros:kinetic

arg PROJECT_DIR=Rover_2020_2021
arg HOME_PATH=/home/rosuser

# since we are all at OSU, it makes sense to use the OSU OSL's repo instead
run sed -i 's@http://archive.ubuntu.com/ubuntu/@http://ubuntu.osuosl.org/ubuntu@g' /etc/apt/sources.list

run sudo apt-get update && sudo apt-get -y dist-upgrade
run sudo apt-get -y install ros-kinetic-desktop-full ros-kinetic-ros-tutorials xserver-xephyr ros-kinetic-catkin python-catkin-tools ros-kinetic-moveit ros-kinetic-moveit-visual-tools

# set up a non-root user for running our code
run useradd -ms /bin/bash rosuser

user rosuser
workdir $HOME_PATH

volume /home/rosuser/Github/$PROJECT_DIR

add ground_station_setup.sh $HOME_PATH/ground_station_setup.sh

run bash ground_station_setup.sh

run rm ground_station_setup.sh

# add some code to the workspace
run cd ~/catkin_workspace/src && git clone -b kinetic-devel https://github.com/ros-planning/moveit_tutorials.git
run cd ~/catkin_workspace/src && git clone -b kinetic-devel https://github.com/ros-planning/panda_moveit_config.git

# apply moveit symlinks
run ln -s $HOME_PATH/Github/$PROJECT_DIR/software/ros_packages/rover_arm_moveit_config ~/catkin_workspace/src/rover_arm_moveit_config
run ln -s $HOME_PATH/Github/$PROJECT_DIR/software/ros_packages/mr1718-arm-urdf_export ~/catkin_workspace/src/mr1718-arm-urdf_export

run rosdep update
#run rosdep install -y --from-paths . --ignore-src --rosdistro kinetic

