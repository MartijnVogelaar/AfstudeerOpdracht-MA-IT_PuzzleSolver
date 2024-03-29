#include "InductiveSensor.hpp"

int main(int argc, char **argv)
{
    if (argc > 2)
    {
        ros::init(argc, argv, std::string("inductive_sensor_simulator" + std::string(argv[1])));
        InductiveSensor inductiveSensor = InductiveSensor((uint8_t)atoi(argv[1]));
        inductiveSensor.runMeasurements(argc, argv);
        return 0;
    }
    else
    {
        ROS_ERROR("Incorrect number of arguments!");
        return 1;
    }
}
