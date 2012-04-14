#ifndef TRACKAGENT_H
#define TRACKAGENT_H

#include "Agent.h"

class TrackAgent : public Agent
{
public:
    TrackAgent();
    ~TrackAgent();

    void update(CarState &carState, const float dt);
    void calculatePotentialToAgentOptions(std::vector<AgentOption> &options);

private:
    float angles[TRACK_SENSORS_NUM];
};

#endif // TRACKAGENT_H
