#include "SpeedAgent.h"

SpeedAgent::SpeedAgent()
    :targetSpeed(0.0f)
{
}

SpeedAgent::~SpeedAgent()
{

}

void SpeedAgent::update()
{

}

void SpeedAgent::setAgentOptions(std::vector<AgentOption> &options)
{

}

void SpeedAgent::setTargetSpeed(const float targetSpeed)
{
    this->targetSpeed = targetSpeed;
}

const float SpeedAgent::getTargetSpeed() const
{
    return targetSpeed;
}
