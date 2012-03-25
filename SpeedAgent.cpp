#include "SpeedAgent.h"

SpeedAgent::SpeedAgent()
    :targetSpeed(0.0f)
{
}

SpeedAgent::~SpeedAgent()
{

}

void SpeedAgent::update(CarState &carState, const float dt)
{

}

void SpeedAgent::setAgentOptions(std::vector<AgentOption> &options)
{
    for (unsigned int i = 0; i < options.size(); i++) {

    }
}

void SpeedAgent::setTargetSpeed(const float targetSpeed)
{
    this->targetSpeed = targetSpeed;
}

const float SpeedAgent::getTargetSpeed() const
{
    return targetSpeed;
}
