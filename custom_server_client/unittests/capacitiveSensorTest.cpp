#include "gtest/gtest.h"
#include <thread>
#include <ctime>
#define private public
#include "CustomServerClient.hpp"
#include "capacitive_sensor/capacitive_sensor_measurements.h"


bool messageReceived = false;

void measurementCallback(const capacitive_sensor::capacitive_sensor_measurementsConstPtr &msg)
{
    if (msg->id == 1)
    {
        messageReceived = true;
    }
}

TEST(CustomServerClient, readmeasurement)
{
    CustomServerClient CustomServerClient(1);
    ros::NodeHandle nodeHandler;
    ros::Subscriber capacitiveMeasurementSubscriber = nodeHandler.subscribe("capacitive_sensor", 1000, measurementCallback);
    std::thread CustomServerClientThread (&CustomServerClient::runMeasurement, &CustomServerClient);
    std::clock_t start;
    double duration;

    start = std::clock();
    while(( std::clock() - start ) / (double) CLOCKS_PER_SEC < 2 && !messageReceived){
        ros::spinOnce();
    }
    EXPECT_TRUE(messageReceived);
    messageReceived = false;
    CustomServerClientThread.join();
}

