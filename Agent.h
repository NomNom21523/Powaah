#ifndef AGENT_H
#define AGENT_H

#include <vector>
#include "AgentOption.h"
#include "CarState.h"
#include "Charge.h"

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
