#ifndef SPEEDAGENT_H
#define SPEEDAGENT_H

#include "Agent.h"

class SpeedAgent : public Agent
{
public:
    SpeedAgent();
    ~SpeedAgent();

    void update();
    void setAgentOptions(std::vector<AgentOption> &options);

    void setTargetSpeed(const float targetSpeed);
    const float getTargetSpeed() const;

private:
    float targetSpeed;

};

#endif // SPEEDAGENT_H
