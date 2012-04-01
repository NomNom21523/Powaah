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
    // find the sensor that has the longest length
    int longestTrackSensor = 0;
    for (int i = 0; i < TRACK_SENSORS_NUM; i++) {
        if (carState.getTrack(i) > carState.getTrack(longestTrackSensor)) {
            longestTrackSensor = i;
        }
    }

    // put a charge at the longest sensor position


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
