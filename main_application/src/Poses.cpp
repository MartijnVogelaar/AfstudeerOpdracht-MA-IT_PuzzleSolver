#include "Poses.hpp"
#include <tf2/LinearMath/Quaternion.h>
#include "ros/ros.h"
#include <math.h> /* sin */

geometry_msgs::Pose PICKUP_POINT_PREPERATION_POSE_1;
geometry_msgs::Pose PICKUP_POINT_PREPERATION_POSE_2;
geometry_msgs::Pose PICKUP_POINT_MOVE_BACK_1;
geometry_msgs::Pose PICKUP_POINT_MOVE_BACK_2;
geometry_msgs::Pose PICKUP_POINT_MOVE_SLIDER;
geometry_msgs::Pose PICKUP_POINT_MOVE_PIECE;
geometry_msgs::Pose ROBOT_HOME_POSE;
geometry_msgs::Pose ROBOT_HOME_POSE2;
geometry_msgs::Pose ROBOT_HOME_POSE3;
geometry_msgs::Pose ROBOT_DROP_POSITION;
geometry_msgs::Pose ROBOT_DROP_POSITION2;

PuzzlePiecePoses Circle1Poses;
PuzzlePiecePoses Circle2Poses;
PuzzlePiecePoses SquarePoses;
PuzzlePiecePoses Rectangle1Poses;
PuzzlePiecePoses Rectangle2Poses;

const double pickupPointAngle = 2.10; //radians

const double prepareDistance = 0.04; //cm


void initializePoses()
{
    tf2::Quaternion pickupPointQuaternion;
    pickupPointQuaternion.setRPY(0, pickupPointAngle, M_PI / 2);

    tf2::Quaternion puzzleAngleCircle;
    puzzleAngleCircle.setRPY(-M_PI / 2, M_PI / 2, 0);

    tf2::Quaternion puzzleAngleSquare;
    puzzleAngleSquare.setRPY(0, M_PI / 2, -M_PI / 4 * 3);

    tf2::Quaternion puzzleAngleRectangle;
    puzzleAngleRectangle.setRPY(0, M_PI / 2, -M_PI / 4);
    tf2::Quaternion puzzleAngleRectangle2;
    puzzleAngleRectangle2.setRPY(0, M_PI / 2, M_PI / 4);

    tf2::Quaternion pickupPointMovementAngle;
    pickupPointMovementAngle.setRPY(0, M_PI / 2, 0);

    /**
     * Poses seen from the "eyes" of the pickuppoint
    **/

    PICKUP_POINT_PREPERATION_POSE_1.position.x = -0.23;
    PICKUP_POINT_PREPERATION_POSE_1.position.y = -0.47;
    PICKUP_POINT_PREPERATION_POSE_1.position.z = 0.42;
    PICKUP_POINT_PREPERATION_POSE_1.orientation.x = pickupPointMovementAngle.x();
    PICKUP_POINT_PREPERATION_POSE_1.orientation.y = pickupPointMovementAngle.y();
    PICKUP_POINT_PREPERATION_POSE_1.orientation.z = pickupPointMovementAngle.z();
    PICKUP_POINT_PREPERATION_POSE_1.orientation.w = pickupPointMovementAngle.w();

    PICKUP_POINT_PREPERATION_POSE_2.position.x = -0.23;
    PICKUP_POINT_PREPERATION_POSE_2.position.y = -0.47;
    PICKUP_POINT_PREPERATION_POSE_2.position.z = 0.25;
    PICKUP_POINT_PREPERATION_POSE_2.orientation.x = pickupPointMovementAngle.x();
    PICKUP_POINT_PREPERATION_POSE_2.orientation.y = pickupPointMovementAngle.y();
    PICKUP_POINT_PREPERATION_POSE_2.orientation.z = pickupPointMovementAngle.z();
    PICKUP_POINT_PREPERATION_POSE_2.orientation.w = pickupPointMovementAngle.w();

    PICKUP_POINT_MOVE_SLIDER.position.x = -0.23;
    PICKUP_POINT_MOVE_SLIDER.position.y = -0.25;
    PICKUP_POINT_MOVE_SLIDER.position.z = 0.25;
    PICKUP_POINT_MOVE_SLIDER.orientation.x = pickupPointMovementAngle.x();
    PICKUP_POINT_MOVE_SLIDER.orientation.y = pickupPointMovementAngle.y();
    PICKUP_POINT_MOVE_SLIDER.orientation.z = pickupPointMovementAngle.z();
    PICKUP_POINT_MOVE_SLIDER.orientation.w = pickupPointMovementAngle.w();

    PICKUP_POINT_MOVE_BACK_1.position.x = -0.23;
    PICKUP_POINT_MOVE_BACK_1.position.y = -0.3;
    PICKUP_POINT_MOVE_BACK_1.position.z = 0.25;
    PICKUP_POINT_MOVE_BACK_1.orientation.x = pickupPointMovementAngle.x();
    PICKUP_POINT_MOVE_BACK_1.orientation.y = pickupPointMovementAngle.y();
    PICKUP_POINT_MOVE_BACK_1.orientation.z = pickupPointMovementAngle.z();
    PICKUP_POINT_MOVE_BACK_1.orientation.w = pickupPointMovementAngle.w();

    PICKUP_POINT_MOVE_BACK_2.position.x = -0.23;
    PICKUP_POINT_MOVE_BACK_2.position.y = -0.3;
    PICKUP_POINT_MOVE_BACK_2.position.z = 0.5;
    PICKUP_POINT_MOVE_BACK_2.orientation.x = pickupPointMovementAngle.x();
    PICKUP_POINT_MOVE_BACK_2.orientation.y = pickupPointMovementAngle.y();
    PICKUP_POINT_MOVE_BACK_2.orientation.z = pickupPointMovementAngle.z();
    PICKUP_POINT_MOVE_BACK_2.orientation.w = pickupPointMovementAngle.w();

    /*************************************
     * Poses seen from the ROBOT         *
     *************************************/
    ROBOT_HOME_POSE.position.x = 0.424;
    ROBOT_HOME_POSE.position.y = 0;
    ROBOT_HOME_POSE.position.z = 0.65;
    ROBOT_HOME_POSE.orientation.x = 0.0;
    ROBOT_HOME_POSE.orientation.y = 0.0;
    ROBOT_HOME_POSE.orientation.z = 0.0;
    ROBOT_HOME_POSE.orientation.w = 1.0;

    ROBOT_HOME_POSE2.position.x = 0.424;
    ROBOT_HOME_POSE2.position.y = 0;
    ROBOT_HOME_POSE2.position.z = 0.45;
    ROBOT_HOME_POSE2.orientation.x = 0.0;
    ROBOT_HOME_POSE2.orientation.y = 0.0;
    ROBOT_HOME_POSE2.orientation.z = 0.0;
    ROBOT_HOME_POSE2.orientation.w = 1.0;

    ROBOT_HOME_POSE3.position.x = 0.424;
    ROBOT_HOME_POSE3.position.y = 0.2;
    ROBOT_HOME_POSE3.position.z = 0.45;
    ROBOT_HOME_POSE3.orientation.x = 0.0;
    ROBOT_HOME_POSE3.orientation.y = 0.0;
    ROBOT_HOME_POSE3.orientation.z = 0.0;
    ROBOT_HOME_POSE3.orientation.w = 1.0;

    ROBOT_DROP_POSITION.position.x = 0.45;
    ROBOT_DROP_POSITION.position.y = 0.0;
    ROBOT_DROP_POSITION.position.z = 0.15;
    ROBOT_DROP_POSITION.orientation.x = 0.0;
    ROBOT_DROP_POSITION.orientation.y = 0.707;
    ROBOT_DROP_POSITION.orientation.z = 0;
    ROBOT_DROP_POSITION.orientation.w = 0.707;

    ROBOT_DROP_POSITION2.position.x = 0.45;
    ROBOT_DROP_POSITION2.position.y = 0.0;
    ROBOT_DROP_POSITION2.position.z = 0.10;
    ROBOT_DROP_POSITION2.orientation.x = 0.0;
    ROBOT_DROP_POSITION2.orientation.y = 0.707;
    ROBOT_DROP_POSITION2.orientation.z = 0;
    ROBOT_DROP_POSITION2.orientation.w = 0.707;

    /*************************************
     * Circle1 POSES                      *
     *************************************/

    Circle1Poses.pickupPose.position.x = 0;
    Circle1Poses.pickupPose.position.y = 0.2515;
    Circle1Poses.pickupPose.position.z = 0.092;
    Circle1Poses.pickupPose.orientation.x = pickupPointQuaternion.x();
    Circle1Poses.pickupPose.orientation.y = pickupPointQuaternion.y();
    Circle1Poses.pickupPose.orientation.z = pickupPointQuaternion.z();
    Circle1Poses.pickupPose.orientation.w = pickupPointQuaternion.w();

    Circle1Poses.placePose.position.x = -0.065;
    Circle1Poses.placePose.position.y = 0.102;
    Circle1Poses.placePose.position.z = 0.015;
    Circle1Poses.placePose.orientation.x = puzzleAngleCircle.x();
    Circle1Poses.placePose.orientation.y = puzzleAngleCircle.y();
    Circle1Poses.placePose.orientation.z = puzzleAngleCircle.z();
    Circle1Poses.placePose.orientation.w = puzzleAngleCircle.w();


     /*************************************
     * Circle2 POSES                      *
     *************************************/

    Circle2Poses.pickupPose.position.x = 0;
    Circle2Poses.pickupPose.position.y = 0.2515;
    Circle2Poses.pickupPose.position.z = 0.092;
    Circle2Poses.pickupPose.orientation.x = pickupPointQuaternion.x();
    Circle2Poses.pickupPose.orientation.y = pickupPointQuaternion.y();
    Circle2Poses.pickupPose.orientation.z = pickupPointQuaternion.z();
    Circle2Poses.pickupPose.orientation.w = pickupPointQuaternion.w();

    Circle2Poses.placePose.position.x = 0.074;
    Circle2Poses.placePose.position.y = -0.115;
    Circle2Poses.placePose.position.z = 0.015;
    Circle2Poses.placePose.orientation.x = puzzleAngleCircle.x();
    Circle2Poses.placePose.orientation.y = puzzleAngleCircle.y();
    Circle2Poses.placePose.orientation.z = puzzleAngleCircle.z();
    Circle2Poses.placePose.orientation.w = puzzleAngleCircle.w();


    /*************************************
     * Square POSES                      *
     *************************************/

    SquarePoses.pickupPose.position.x = 0;
    SquarePoses.pickupPose.position.y = 0.2515;
    SquarePoses.pickupPose.position.z = 0.092;
    SquarePoses.pickupPose.orientation.x = pickupPointQuaternion.x();
    SquarePoses.pickupPose.orientation.y = pickupPointQuaternion.y();
    SquarePoses.pickupPose.orientation.z = pickupPointQuaternion.z();
    SquarePoses.pickupPose.orientation.w = pickupPointQuaternion.w();

    SquarePoses.placePose.position.x = -0.0675;
    SquarePoses.placePose.position.y = -0.076;
    SquarePoses.placePose.position.z = 0.016;
    SquarePoses.placePose.orientation.x = puzzleAngleSquare.x();
    SquarePoses.placePose.orientation.y = puzzleAngleSquare.y();
    SquarePoses.placePose.orientation.z = puzzleAngleSquare.z();
    SquarePoses.placePose.orientation.w = puzzleAngleSquare.w();

    /*************************************
     * Rectangle5 POSES                  *
     *************************************/

    Rectangle1Poses.pickupPose.position.x = -0.021;
    Rectangle1Poses.pickupPose.position.y = 0.251;
    Rectangle1Poses.pickupPose.position.z = 0.0920;
    Rectangle1Poses.pickupPose.orientation.x = pickupPointQuaternion.x();
    Rectangle1Poses.pickupPose.orientation.y = pickupPointQuaternion.y();
    Rectangle1Poses.pickupPose.orientation.z = pickupPointQuaternion.z();
    Rectangle1Poses.pickupPose.orientation.w = pickupPointQuaternion.w();

    Rectangle1Poses.placePose.position.x = 0.0780;
    Rectangle1Poses.placePose.position.y = 0.09;
    Rectangle1Poses.placePose.position.z = 0.015;
    Rectangle1Poses.placePose.orientation.x = puzzleAngleRectangle.x();
    Rectangle1Poses.placePose.orientation.y = puzzleAngleRectangle.y();
    Rectangle1Poses.placePose.orientation.z = puzzleAngleRectangle.z();
    Rectangle1Poses.placePose.orientation.w = puzzleAngleRectangle.w();

    /*************************************
     * Rectangle 9 POSES                  *
     *************************************/

    Rectangle2Poses.pickupPose.position.x = 0.021;
    Rectangle2Poses.pickupPose.position.y = 0.251;
    Rectangle2Poses.pickupPose.position.z = 0.0920;
    Rectangle2Poses.pickupPose.orientation.x = pickupPointQuaternion.x();
    Rectangle2Poses.pickupPose.orientation.y = pickupPointQuaternion.y();
    Rectangle2Poses.pickupPose.orientation.z = pickupPointQuaternion.z();
    Rectangle2Poses.pickupPose.orientation.w = pickupPointQuaternion.w();

    Rectangle2Poses.placePose.position.x = 0.0780;
    Rectangle2Poses.placePose.position.y = 0.09;
    Rectangle2Poses.placePose.position.z = 0.015;
    Rectangle2Poses.placePose.orientation.x = puzzleAngleRectangle2.x();
    Rectangle2Poses.placePose.orientation.y = puzzleAngleRectangle2.y();
    Rectangle2Poses.placePose.orientation.z = puzzleAngleRectangle2.z();
    Rectangle2Poses.placePose.orientation.w = puzzleAngleRectangle2.w();

    PICKUP_POINT_MOVE_PIECE.position.x = 0;
    PICKUP_POINT_MOVE_PIECE.position.y = 0.248;
    PICKUP_POINT_MOVE_PIECE.position.z = 0.30;
    PICKUP_POINT_MOVE_PIECE.orientation.x = pickupPointQuaternion.x();
    PICKUP_POINT_MOVE_PIECE.orientation.y = pickupPointQuaternion.y();
    PICKUP_POINT_MOVE_PIECE.orientation.z = pickupPointQuaternion.z();
    PICKUP_POINT_MOVE_PIECE.orientation.w = pickupPointQuaternion.w();

    /**
     * Poses seen from the eyes of the Puzzle
     * 
     * rectangle = induc 0
     * circle left under = induc 1
     * circle right up = induc 2
     * square = induc 3
     */
}

geometry_msgs::Pose getPuzzlePiecePickup(Shape puzzlePiece)
{
    switch (puzzlePiece)
    {
    case Shape::CIRCLE:
        return Circle1Poses.pickupPose;
    case Shape::SQUARE:
        return SquarePoses.pickupPose;
    case Shape::RECTANGLE_1:
        return Rectangle1Poses.pickupPose;
    case Shape::RECTANGLE_2:
        return Rectangle2Poses.pickupPose;
    default:
        return Circle1Poses.pickupPose;
    }
    return Circle1Poses.pickupPose;
}

geometry_msgs::Pose getPuzzlePiecePreparePickup(Shape puzzlePiece)
{
    geometry_msgs::Pose pickupPoint = getPuzzlePiecePickup(puzzlePiece);
    pickupPoint.position.y = pickupPoint.position.y - prepareDistance * cos(pickupPointAngle);
    pickupPoint.position.z = pickupPoint.position.z + prepareDistance * sin(pickupPointAngle);
    return pickupPoint;
}

