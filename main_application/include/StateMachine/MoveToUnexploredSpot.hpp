#ifndef MOVE_TO_UNEXPLORED_SPOT_HPP
#define MOVE_TO_UNEXPLORED_SPOT_HPP

// Local
#include "State.hpp"
#include "TF2Handler.hpp"

class Context;
/**
   * @class MoveToUnexploredSpot
   *
   * @brief MoveToUnexploredSpot is the class which represents the MoveToUnexploredSpot state.
   *
   *
   * @details   The state MoveToUnexplored spot takes care of making the movement towards an
   *            unexplored-spot and fitting spot in the puzzle. If no spot can be found a transition
   *            to the MoveUnknownPiece state will be made.
   */
class MoveToUnexploredSpot : public State
{
public:
    /**
     * @brief Construct a new MoveToUnexploredSpot object
     *
     */
    MoveToUnexploredSpot();
    /**
     * @brief Destroy the MoveToUnexploredSpot object
     *
     */
    ~MoveToUnexploredSpot();
    /**
     * @brief entryAction is being called when the MoveToUnexploredSpot state is being entered.
     *
     * @details When the MoveToUnexploredSpot state is entered the robotarm will be set to the
     * begin position.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void entryAction(Context *aContext) override;

    /**
     * @brief doActivity is continiously being called while the system is in the
     * MoveToUnexploredSpot.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void doActivity(Context *aContext) override;
    /**
     * @brief exitAction is being called when the MoveToUnexploredSpot state is being exited.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void exitAction(Context *aContext) override;

private:
    TF2Handler tf2Handler;
};
#endif // MOVE_TO_UNEXPLORED_SPOT_HPP