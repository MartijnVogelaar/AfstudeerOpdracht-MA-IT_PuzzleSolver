#ifndef POWER_OFF_HPP
#define POWER_OFF_HPP

// Local
#include "State.hpp"
class Context;
/**
   * @class PowerOff
   *
   * @brief PowerOff is the class which represents the PowerOff state.
   *
   */
class PowerOff : public State
{
public:
    /**
     * @brief Construct a new PowerOff object
     *
     */
    PowerOff();
    /**
     * @brief Destroy the PowerOff object
     *
     */
    ~PowerOff();
    /**
     * @brief entryAction is being called when the PowerOff state is being entered.
     *
     * @details When the PowerOff state is entered the robotarm will be set to the
     * begin position.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void entryAction(Context *aContext) override;

    /**
     * @brief doActivity is continiously being called while the system is in the
     * PowerOff.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void doActivity(Context *aContext) override;
    /**
     * @brief exitAction is being called when the PowerOff state is being exited.
     *
     * @param aContext is an object which gives the states an interface to the
     * "outside world".
     */
    void exitAction(Context *aContext) override;
};
#endif // POWER_OFF_HPP