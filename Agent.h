#ifndef AGENT_H
#define AGENT_H

#include <vector>
#include "AgentOption.h"
#include "CarState.h"
#include "Charge.h"

/*!
 * @class Agent.h
 * @author Tim Uusitalo
 * @date 2012-04-30
 *
 * @brief Base class for agents.
 *
 * Base class for all of the agents. It has an interface defined how an agent should look like.
 *
 * An agent shall have an update function and a function that
 * calculates a potential field for given agent options.
 * An AgentOption should have one potential value for each agent,
 * which it sums together to one final potentialvalue.
 *
 */
class Agent
{
public:
    Agent();
    virtual ~Agent();

    virtual void update(CarState &carState, const float dt) = 0;

    virtual void calculatePotentialToAgentOptions(std::vector<AgentOption> &options) = 0 ;

protected:
    std::vector<Charge> potentialField;
};

#endif // AGENT_H
