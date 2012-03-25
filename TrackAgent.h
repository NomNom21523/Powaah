#ifndef TRACKAGENT_H
#define TRACKAGENT_H

#include "Agent.h"

class TrackAgent : public Agent
{
public:
    TrackAgent();
    ~TrackAgent();

    void update(CarState &carState, const float dt);
    void setAgentOptions(std::vector<AgentOption> &options);

private:
};

#endif // TRACKAGENT_H
