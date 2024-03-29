#ifndef CONTROL_GRIPPER_SERVER_REAL_HPP
#define CONTROL_GRIPPER_SERVER_REAL_HPP

#include <actionlib/server/simple_action_server.h>
#include <abb_controller_messages/ControlGripperAction.h>
#include <actionlib/client/simple_action_client.h>
#include "custom_server_client/TcpIpAction.h"

#define TCP_IP_ACTION "customServerClient"

/**
 * @class ControlGripperServer
 * 
 * @brief The class ControlGripperServer is a class which can be used to catch action requests from the ControlGripper action.
 *        The class handles the incoming requests and provides feedback during the handling of the requests. Eventually
 *        a result will be presented to the node which send the request.
 * 
 */
class ControlGripperServer
{
protected:
    ros::NodeHandle nodeHandler;

    std::string actionName;
    actionlib::SimpleActionServer<abb_controller_messages::ControlGripperAction> actionServer;
    actionlib::SimpleActionClient<custom_server_client::TcpIpAction> tcpIpActionClient;

    abb_controller_messages::ControlGripperFeedback actionFeedback;
    abb_controller_messages::ControlGripperResult actionResult;

public:
    /**
     * @brief Construct a new Control Gripper Server object
     * 
     * @param name Name which will be used to present this node to ROS
     */
    ControlGripperServer(std::string name);

    /**
     * @brief Destroy the Control Gripper Server object
     * 
     */
    ~ControlGripperServer();

    /**
     * @brief Callback function which is called when any node uses the ControlGripper action.
     * 
     * @param goal Message with the request of the action.
     */
    void goalCallback(const abb_controller_messages::ControlGripperGoalConstPtr &goal);
};

#endif //CONTROL_GRIPPER_SERVER_REAL_HPP