#include <ros/ros.h>
#include "MoveEndEffectorServer.hpp"
#include "MoveEndEffectorStraightServer.hpp"
#include "ControlGripperServer.hpp"
#include "RotateGripperServer.hpp"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "MoveEndEffectorAction");
  ros::AsyncSpinner spinner(1);

  spinner.start();
  MoveEndEffectorServer moveNormalServer("MoveEndEffectorAction");
  MoveEndEffectorStraightServer moveStraightServer("MoveEndEffectorStraightAction");
  ControlGripperServer controlGripperServer("ControlGripperAction");
  RotateGripperServer rotateGripperServer("RotateGripperAction");
  while (ros::ok)
  {
  }

  return 0;
}