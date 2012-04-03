#include "SpeedAgent.h"
#include "MathUtility.h"

SpeedAgent::SpeedAgent()
    :targetSpeed(0.0f)
{
    for (int i=0; i<5; i++)
    {
        angles[i]=-90+i*15;
        angles[18-i]=90-i*15;
    }

    for (int i=5; i<9; i++)
    {
        angles[i]=-20+(i-5)*5;
        angles[18-i]=20-(i-5)*5;
    }

}

SpeedAgent::~SpeedAgent()
{

}

void SpeedAgent::update(CarState &carState, const float dt)
{
    // find the sensor that has the longest length
    int longestTrackSensor = 0;
    for (int i = 0; i < TRACK_SENSORS_NUM; i++) {
        if (carState.getTrack(i) > carState.getTrack(longestTrackSensor)) {
            longestTrackSensor = i;
        }
    }
    angles[9]=0;

    // put a charge at the longest sensor position
    Vector2 position = MathUtility::calculatePosition(angles[longestTrackSensor], carState.getTrack(longestTrackSensor));
    Charge charge;
    charge.setPosition(position);
    charge.setCharge(24.0f);

}

void SpeedAgent::setAgentOptions(std::vector<AgentOption> &options)
{
    for (unsigned int i = 0; i < options.size(); i++) {
        AgentOption option = options[i];
        Vector2 lengthVector = potentialField.front().getPosition() - option.getPosition();
        float length = lengthVector.length();
        float potentialValue = 60 + (-1*pow(length,2.0f)*potentialField.front().getCharge());
        option.setPotentialValue(potentialValue);
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
