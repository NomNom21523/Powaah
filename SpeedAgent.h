#ifndef SPEEDAGENT_H
#define SPEEDAGENT_H

#include "Agent.h"
#include "BaseDriver.h"

class SpeedAgent : public Agent
{
public:
    SpeedAgent();
    ~SpeedAgent();

    void update(CarState &carState, const float dt);
    void calculatePotentialToAgentOptions(std::vector<AgentOption> &options);

    void setTargetSpeed(const float targetSpeed);
    const float getTargetSpeed() const;

    void setStage(BaseDriver::tstage stage);

private:
    float targetSpeed;
    float angles[TRACK_SENSORS_NUM];
    BaseDriver::tstage stage;
};

#endif // SPEEDAGENT_H
