#ifndef CURVEAGENT_H
#define CURVEAGENT_H

#include "Agent.h"

class CurveAgent : public Agent
{
public:
    CurveAgent();
    ~CurveAgent();

    void update();
    void setAgentOptions(std::vector<AgentOption> &options);
};

#endif // CURVEAGENT_H
