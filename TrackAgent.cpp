#include "TrackAgent.h"
#include "Charge.h"
#include "MathUtility.h"

TrackAgent::TrackAgent()
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

TrackAgent::~TrackAgent()
{

}

void TrackAgent::update(CarState &carState, const float dt)
{
    potentialField.clear();

    for (int i = 0; i < TRACK_SENSORS_NUM; i++) {
        Charge charge;
        if (carState.getTrack(i) < 200.0f && carState.getTrack(i) > -1) {
            charge.setAngle(angles[i]);
            charge.setCharge(-5.0f);
            charge.setPosition(MathUtility::calculatePosition(MathUtility::convertDegToRad(charge.getAngle()), carState.getTrack(i)));
            potentialField.push_back(charge);
        }
    }
}

void TrackAgent::calculatePotentialToAgentOptions(std::vector<AgentOption> &options)
{
    for (unsigned int i = 0; i < options.size(); i++) {
        float trackAgentPotentialValue = 0.0f;
        for (unsigned int j = 0; j < potentialField.size(); j++) {
            Vector2 lengthVector = potentialField[j].getPosition();
            lengthVector -= options[i].getPosition();

            float length = lengthVector.length();
            trackAgentPotentialValue += (potentialField[j].getCharge() / sqrtf(length));
        }
        options[i].setTrackAgentPotentialValue(trackAgentPotentialValue);
    }
}
