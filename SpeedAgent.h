#ifndef SPEEDAGENT_H
#define SPEEDAGENT_H

#include "Agent.h"

class SpeedAgent : public Agent
{
public:
    SpeedAgent();
    ~SpeedAgent();

    void update(CarState &carState, const float dt);
    void setAgentOptions(std::vector<AgentOption> &options);

    void setTargetSpeed(const float targetSpeed);
    const float getTargetSpeed() const;

private:
    float targetSpeed;
    float angles[TRACK_SENSORS_NUM];
};

#endif // SPEEDAGENT_H
