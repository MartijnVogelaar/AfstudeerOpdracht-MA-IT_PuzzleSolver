#include "ControlGripperServerSimulator.hpp"
#include <std_msgs/Float64.h>

ControlGripperServerSimulator::ControlGripperServerSimulator(std::string aName) : actionServer(nodeHandler, aName, boost::bind(&ControlGripperServerSimulator::goalCallback, this, _1), false),
                                                                                  actionName(aName)
{
    attachClient = nodeHandler.serviceClient<gazebo_ros_link_attacher::Attach>("/link_attacher_node/attach");
    detachClient = nodeHandler.serviceClient<gazebo_ros_link_attacher::Attach>("/link_attacher_node/detach");
    pub1 = nodeHandler.advertise<std_msgs::Float64>("/joint7_controller/command", 1000);
    pub2 = nodeHandler.advertise<std_msgs::Float64>("/joint8_controller/command", 1000);
    pub3 = nodeHandler.advertise<std_msgs::Float64>("/joint9_controller/command", 1000);

    actionServer.start();
}

ControlGripperServerSimulator::~ControlGripperServerSimulator()
{
}

void ControlGripperServerSimulator::goalCallback(const abb_controller_messages::ControlGripperGoalConstPtr &goal)
{
    static bool secondCircle = false;
    bool open = goal->open;
    gazebo_ros_link_attacher::Attach srv;
    srv.request.model_name_1 = "EmptyPuzzle";
    srv.request.link_name_1 = "bottom_plate";

    if (goal->puzzleID == 1 && !secondCircle)
    {
        srv.request.model_name_2 = "Circle2";
        srv.request.link_name_2 = "circle_2_link_0";
    }
    else if (goal->puzzleID == 1 && secondCircle)
    {
        srv.request.model_name_2 = "Circle1";
        srv.request.link_name_2 = "circle_1_link_0";
    }
    else if (goal->puzzleID == 3)
    {
        srv.request.model_name_2 = "Square";
        srv.request.link_name_2 = "square_link_0";
    }
    else if (goal->puzzleID == 5 || goal->puzzleID == 9)
    {
        srv.request.model_name_2 = "Rectangle";
        srv.request.link_name_2 = "rectangle_link_0";
    }
    std_msgs::Float64 message;
    if (open)
    {
        srv.request.model_name_1 = "abb_irb120_3_58";
        srv.request.link_name_1 = "link_6";
        message.data = 100;
        if (goal->puzzleID != 99)
        {
            if (attachClient.call(srv))
            {
                ROS_INFO("Attached!");
            }
            else
            {
                ROS_ERROR("Something went wrong attaching!!");
            }
        }
    }
    else
    {
        if (goal->puzzleID == 1)
        {
            secondCircle = true;
        }
        if (goal->puzzleID != 99)
        {
            if (attachClient.call(srv))
            {

                srv.request.model_name_1 = "abb_irb120_3_58";
                srv.request.link_name_1 = "link_6";
                detachClient.call(srv);
                ROS_INFO("Detached!");
            }
            else
            {
                ROS_ERROR("Something went wrong detaching!!");
            }
        }
        message.data = -100;
    }

    pub1.publish(message);
    pub2.publish(message);
    pub3.publish(message);
    actionResult.robotID = goal->robotID;
    actionResult.open = !open;
    actionResult.success = true;
    actionServer.setSucceeded(actionResult);
}
