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
    angles[9]=0;
}

SpeedAgent::~SpeedAgent()
{

}

void SpeedAgent::update(CarState &carState, const float dt)
{
    // find the sensor that has the longest length
    int longestTrackSensor = 0;
    for (int i = 1; i < TRACK_SENSORS_NUM; i++) {
        if (carState.getTrack(i) > carState.getTrack(longestTrackSensor)) {
            longestTrackSensor = i;
        }
    }

    // put a charge at next available position
    Vector2 position(0,0);
    if (stage != BaseDriver::WARMUP) {
        position = MathUtility::calculatePosition(MathUtility::convertDegToRad(angles[longestTrackSensor]), targetSpeed);
    } else if (stage == BaseDriver::WARMUP && carState.getLastLapTime() <= 0) {
        position = MathUtility::calculatePosition(-1*(2 * carState.getAngle() - (carState.getTrackPos()*0.5f)), targetSpeed);
    }
    Charge charge;
    charge.setPosition(position);
    charge.setCharge(24.0f);
    charge.setAngle(MathUtility::convertRadToDeg(position.angle()));
    potentialField.clear();
    potentialField.push_back(charge);

}

void SpeedAgent::calculatePotentialToAgentOptions(std::vector<AgentOption> &options)
{
    for (unsigned int i = 0; i < options.size(); i++) {
        AgentOption &option = options[i];
        Vector2 lengthVector = potentialField.front().getPosition() - option.getPosition();
        float length = lengthVector.length();
        float potentialValue = 60 + (-1*pow(length,2.0f)*potentialField.front().getCharge());
        option.setSpeedAgentPotentialValue(potentialValue);
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

void SpeedAgent::setStage(BaseDriver::tstage stage)
{
    this->stage = stage;
}
