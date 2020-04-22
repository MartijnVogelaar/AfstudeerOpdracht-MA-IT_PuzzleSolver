#include "PlaceCorrectly/PlacePieceInPuzzle.hpp"
#include "PlaceCorrectly/SubContext.hpp"
#include "Poses.hpp"
#include "PlaceCorrectly/RotatePieceOnPlace.hpp"
#include "PlaceCorrectly/CheckCorrectlyRotated.hpp"
#include "Shapes.hpp"
#include "Context.hpp"

PlacePieceInPuzzle::PlacePieceInPuzzle()
{
}

PlacePieceInPuzzle::~PlacePieceInPuzzle() {}

void PlacePieceInPuzzle::entryAction(SubContext *context)
{
    geometry_msgs::Pose goal = context->getParentContext()->getCurrentPuzzlePieceSpot().getPuzzlePiecePlace();
    geometry_msgs::Pose placePiece = tf2Handler.calculatePosition(PUZZLE, BASE, goal);
    if (context->getCurrentPuzzlePieceSpot().getShape() == Shape::CIRCLE)
    {
        context->getMoveRobotClient().RotateGripper(0, 0, false, false);
    }
    context->getMoveRobotClient().MoveRobotStraightNoRotation(0, placePiece.position);
}

void PlacePieceInPuzzle::doActivity(SubContext *context)
{

    if (context->getCurrentPuzzlePieceSpot().getShape() == Shape::CIRCLE)
    {
        context->setState(std::make_shared<RotatePieceOnPlace>());
    }
    else
    {
        context->setState(std::make_shared<CheckCorrectlyRotated>());
    }
}

void PlacePieceInPuzzle::exitAction(SubContext *)
{
}
