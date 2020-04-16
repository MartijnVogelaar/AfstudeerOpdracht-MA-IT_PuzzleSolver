#ifndef SUB_CONTEXT_HPP
#define SUB_CONTEXT_HPP

#include "PlaceCorrectly/SubState.hpp"
#include "MoveRobotClient.hpp"
#include "Context.hpp"
#include <memory>

#define QUEUE_SIZE 1000

class SubState;
/**
   * @class SubContext
   *
   * @brief SubContext is a class which gives the states an interface to the
   * "outside world".
   *
   */
class SubContext : public Context
{
public:

   SubContext();
  /**
     * @brief Construct a new SubContext object
     *
     */
  SubContext(Context *aParentContext);

  Context* getParentContext();

  /**
     * @brief Set the currentState by supplying a shared_ptr to a state.
     *
     * @param state
     */
  void setState(const std::shared_ptr<SubState> &state);

  /**
     * @brief Run is the function which takes care of the handling of the
     * EventQueue and calling the doActivity functions of the different states.
     */
  void run();

private:
  Context *parentContext;
  std::shared_ptr<SubState> currentSubState;
};
#endif // SUB_CONTEXT_HPP