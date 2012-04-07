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

    // put a charge at the longest sensor position
    Vector2 position = MathUtility::calculatePosition(MathUtility::convertDegToRad(angles[longestTrackSensor]), carState.getTrack(longestTrackSensor) * 0.0025f);
    Charge charge;
    charge.setPosition(position);
    charge.setCharge(24.0f);
    charge.setAngle(angles[longestTrackSensor]);

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
        option.setPotentialValue(potentialValue);
        std::cout << "Option pf: " << option.getPotentialValue() << " angle " << option.getAngle() << " length " << option.getLength() << " charge" << potentialField.front().getCharge() << " length " << length << std::endl;

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
