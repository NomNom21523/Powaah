#ifndef AGENT_H
#define AGENT_H

#include <vector>
#include "AgentOption.h"
#include "CarState.h"
class Agent
{
public:
    Agent();
    virtual ~Agent();

    virtual void update(CarState &carState, const float dt) = 0;

    virtual void setAgentOptions(std::vector<AgentOption> &options) = 0 ;

protected:
    std::vector<Charge> potentialField;
};

#endif // AGENT_H
