#include "AgentOption.h"

AgentOption::AgentOption()
{
}

AgentOption::~AgentOption()
{

}

void AgentOption::setLength(const float length)
{
    this->length = length;
}

const float AgentOption::getLength() const
{
    return this->length;
}

void AgentOption::setAngle(const float angle)
{
    this->angle = angle;
}

const float AgentOption::getAngle() const
{
    return this->angle;
}

void AgentOption::setPosition(const Vector2 &position)
{
    this->position = position;
}

const Vector2 AgentOption::getPosition() const
{
    return this->position;
}

void AgentOption::setPotentialValue(const float potential_value)
{
    this->potential_value = potential_value;
}

const float AgentOption::getPotentialValue() const
{
    return this->potential_value;
}

void AgentOption::setAcceleratorValue(const float accelerator_value)
{
    this->accelerator_value = accelerator_value;
}

const float AgentOption::getAcceleratorValue() const
{
    return this->accelerator_value;
}


void AgentOption::setCurveAgentPotentialValue(const float curveAgentPotentialValue)
{
    this->curveAgentPotentialValue = curveAgentPotentialValue;
}

const float AgentOption::getCurveAgentPotentialValue() const
{
    return this->curveAgentPotentialValue;
}

void AgentOption::setSpeedAgentPotentialValue(const float speedAgentPotentialValue)
{
    this->speedAgentPotentialValue = speedAgentPotentialValue;
}

const float AgentOption::getSpeedAgentPotentialValue() const
{
    return speedAgentPotentialValue;
}

void AgentOption::setTrackAgentPotentialValue(const float trackAgentPotentialValue)
{
    this->trackAgentPotentialValue = trackAgentPotentialValue;
}

const float AgentOption::getTrackAgentPotentialValue() const
{
    return this->trackAgentPotentialValue;
}
