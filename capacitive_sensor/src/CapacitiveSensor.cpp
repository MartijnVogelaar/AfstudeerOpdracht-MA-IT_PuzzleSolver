#include "CapacitiveSensor.hpp"
#include "capacitive_sensor/capacitive_sensor_measurements.h"
#include <boost/asio.hpp>

#define MESSAGE_TYPE 1
#define LOOP_RATE 1 //hz
#define IP "192.168.125.1"
#define PORT 2020

CapacitiveSensor::CapacitiveSensor(uint8_t aId) : id(aId), sensorValue(0)
{
    p = n.advertise<capacitive_sensor::capacitive_sensor_measurements>("capacitive_sensor", 1000);
}

CapacitiveSensor::~CapacitiveSensor()
{
}

void CapacitiveSensor::runMeasurements()
{
    ros::Rate r(LOOP_RATE); // 10 hz

    while (ros::ok())
    {
        runMeasurement();
        r.sleep();
    }
}

void CapacitiveSensor::runMeasurement()
{
    std::array<char, 1> request = {MESSAGE_TYPE};
    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string(IP), PORT);
    boost::asio::io_service ios;
    try
    {
        boost::asio::ip::tcp::socket socket(ios);

        socket.connect(endpoint);
        socket.write_some(boost::asio::buffer(request, sizeof(request)));

        std::array<char, 2> response;
        socket.receive(boost::asio::buffer(response, sizeof(response)));

        capacitive_sensor::capacitive_sensor_measurements message;
        message.id = id;
        message.value = response[1];
        p.publish(message);
        socket.close();
    }
    catch (const boost::system::system_error &ex)
    {
        ROS_ERROR("Socket failure!");
        ROS_ERROR(ex.what());
    }
}
