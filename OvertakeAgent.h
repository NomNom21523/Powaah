#ifndef OVERTAKEAGENT_H
#define OVERTAKEAGENT_H

#include "Agent.h"

class OvertakeAgent : public Agent
{
public:
    OvertakeAgent();
    ~OvertakeAgent();

    void update(CarState &carState, const float dt);
    void calculatePotentialToAgentOptions(std::vector<AgentOption> &options);

private:
    float angles[OPPONENTS_SENSORS_NUM];
};

#endif // OVERTAKEAGENT_H
