#ifndef AGENT_H
#define AGENT_H

#include <vector>
#include "AgentOption.h"

class Agent
{
public:
    Agent();
    virtual ~Agent();

    virtual void update() = 0;

    virtual void setAgentOptions(std::vector<AgentOption> &options) = 0 ;

private:
};

#endif // AGENT_H
