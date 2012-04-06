#ifndef AGENTOPTION_H
#define AGENTOPTION_H

#include "Vector2.h"
class AgentOption
{
public:
    AgentOption();
    ~AgentOption();

    void setLength(const float length);
    const float getLength() const;

    void setAngle(const float angle);
    const float getAngle() const;

    void setPosition(const Vector2 &position);
    const Vector2 getPosition() const;

    void setPotentialValue(const float potential_value);
    const float getPotentialValue() const;

    void setAcceleratorValue(const float accelerator_value);
    const float getAcceleratorValue() const;

    void setBrakeValue(const float brakeValue);
    const float getBrakeValue() const;

    void setCurveAgentPotentialValue(const float curveAgentPotentialValue);
    const float getCurveAgentPotentialValue() const;

    void setSpeedAgentPotentialValue(const float speedAgentPotentialValue);
    const float getSpeedAgentPotentialValue() const;

    void setTrackAgentPotentialValue(const float trackAgentPotentialValue);
    const float getTrackAgentPotentialValue() const;
private:
    float length;
    float angle;
    Vector2 position;
    float potential_value;
    float accelerator_value;
    float brakeValue;
    float curveAgentPotentialValue;
    float speedAgentPotentialValue;
    float trackAgentPotentialValue;

    int counter;
};

#endif // AGENTOPTION_H
