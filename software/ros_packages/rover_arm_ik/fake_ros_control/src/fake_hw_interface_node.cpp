#include <fake_ros_control/fake_hw_interface.h>

int main(int argc, char** argv) {
    ros::init(argc, argv, "fake_hw_interface");
    ros::NodeHandle nh; //set up node handle for this node

    // NOTE: We run the ROS loop in a separate thread as external calls such
    // as service callbacks to load controllers can block the (main) control loop
    ros::AsyncSpinner spinner(3);
    spinner.start();

    FakeHWInterface fake_hw_interface(nh); //create hw interface object
    fake_hw_interface.init();
    ROS_INFO_STREAM_NAMED("hardware_interface", "Starting hardware interface...");
    fake_hw_interface.run(); /* run hw interface */
    
    return 0;
}