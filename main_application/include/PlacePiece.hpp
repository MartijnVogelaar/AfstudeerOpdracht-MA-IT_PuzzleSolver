#ifndef PLACE_PIECE_HPP
#define PLACE_PIECE_HPP

// Local
#include "State.hpp"
#include "PlaceCorrectly/SubContext.hpp"
#include "TF2Handler.hpp"

class Context;

/**
   * @class PlacePiece
   *
   * @brief PlacePiece is the class which represents the PlacePiece state.
   *
   */
class PlacePiece : public State
{
public:
    /**
     * @brief Construct a new PlacePiece object
     *
     */
    PlacePiece();
    /**
     * @brief Destroy the PlacePiece object
     *
     */
    ~PlacePiece();
    /**
     * @brief entryAction is being called when the PlacePiece state is being entered.
     *
     * @details When the PlacePiece state is entered the robotarm will be set to the
     * begin position.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void entryAction(Context *aContext) override;

    /**
     * @brief doActivity is continiously being called while the system is in the
     * PlacePiece.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void doActivity(Context *aContext) override;
    /**
     * @brief exitAction is being called when the PlacePiece state is being exited.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void exitAction(Context *aContext) override;

private:
    std::shared_ptr<SubContext> subContext;
    TF2Handler tf2Handler;
};
#endif // PLACE_PIECE_HPP