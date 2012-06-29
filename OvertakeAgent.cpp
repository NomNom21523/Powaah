#include "OvertakeAgent.h"
#include "Charge.h"
#include "MathUtility.h"

OvertakeAgent::OvertakeAgent()
{
    float angle = -180.0f;
    for(int i = 0; i < OPPONENTS_SENSORS_NUM; i++) {
        angles[i] = angle;
        angle += 10.0f;
    }
}

OvertakeAgent::~OvertakeAgent()
{

}

void OvertakeAgent::update(CarState &carState, const float dt)
{
    potentialField.clear();

    for (int i = 0; i < OPPONENTS_SENSORS_NUM; i++) {

        if (carState.getOpponents(i) < 20.0f && carState.getOpponents(i) > -1) {
            Charge charge;
            charge.setAngle(angles[i]);
            charge.setCharge(-5.0f);
            charge.setPosition(MathUtility::calculatePosition(MathUtility::convertDegToRad(charge.getAngle()), carState.getOpponents(i)));
            potentialField.push_back(charge);

            charge.setAngle(angles[i]);
            charge.setCharge(-8.0f);
            charge.setPosition(MathUtility::calculatePosition(MathUtility::convertDegToRad(charge.getAngle()), carState.getOpponents(i) - 2));
            potentialField.push_back(charge);

            charge.setAngle(angles[i]);
            charge.setCharge(-7.0f);
            charge.setPosition(MathUtility::calculatePosition(MathUtility::convertDegToRad(charge.getAngle()), carState.getOpponents(i) - 4));
            potentialField.push_back(charge);

            charge.setAngle(angles[i]);
            charge.setCharge(-5.0f);
            charge.setPosition(MathUtility::calculatePosition(MathUtility::convertDegToRad(charge.getAngle()), carState.getOpponents(i) - 6));
            potentialField.push_back(charge);

            charge.setAngle(angles[i]);
            charge.setCharge(-5.0f);
            charge.setPosition(MathUtility::calculatePosition(MathUtility::convertDegToRad(charge.getAngle()), carState.getOpponents(i) - 8));
            potentialField.push_back(charge);

            charge.setAngle(angles[i]);
            charge.setCharge(-5.0f);
            charge.setPosition(MathUtility::calculatePosition(MathUtility::convertDegToRad(charge.getAngle()), carState.getOpponents(i) - 10));
            potentialField.push_back(charge);

            charge.setAngle(angles[i]);
            charge.setCharge(-5.0f);
            charge.setPosition(MathUtility::calculatePosition(MathUtility::convertDegToRad(charge.getAngle()), carState.getOpponents(i) - 12));
            potentialField.push_back(charge);

            charge.setAngle(angles[i]);
            charge.setCharge(-5.0f);
            charge.setPosition(MathUtility::calculatePosition(MathUtility::convertDegToRad(charge.getAngle()), carState.getOpponents(i) - 14));
            potentialField.push_back(charge);

            charge.setAngle(angles[i]);
            charge.setCharge(-5.0f);
            charge.setPosition(MathUtility::calculatePosition(MathUtility::convertDegToRad(charge.getAngle()), carState.getOpponents(i) - 16));
            potentialField.push_back(charge);
        }
    }
    /*
    for (int i = 0; i < TRACK_SENSORS_NUM; i++) {
        Charge charge;
        if (carState.getTrack(i) < 200.0f && carState.getTrack(i) > -1) {
            charge.setAngle(angles[i]);
            charge.setCharge(-5.0f);
            charge.setPosition(MathUtility::calculatePosition(MathUtility::convertDegToRad(charge.getAngle()), carState.getTrack(i)));
            potentialField.push_back(charge);
        }
    }*/
}

void OvertakeAgent::calculatePotentialToAgentOptions(std::vector<AgentOption> &options)
{
    for (unsigned int i = 0; i < options.size(); i++) {
        float OvertakeAgentPotentialValue = 0.0f;
        for (unsigned int j = 0; j < potentialField.size(); j++) {
            Vector2 lengthVector = potentialField[j].getPosition();
            lengthVector -= options[i].getPosition();

            float length = lengthVector.length();
            OvertakeAgentPotentialValue += (potentialField[j].getCharge() / sqrtf(length));
        }
        options[i].setOvertakeAgentPotentialValue(OvertakeAgentPotentialValue);
    }
}
