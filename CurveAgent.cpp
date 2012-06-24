#include "CurveAgent.h"

#include <iostream>

#include "MathUtility.h"

const float CurveAgent::distanceToCurvatureReaction = 300.0f; // value in meter

CurveAgent::CurveAgent()
: trackInfo("test")
{
}

CurveAgent::~CurveAgent()
{

}

void CurveAgent::update(CarState &carState, const float dt)
{
    potentialField.clear();

    if (carState.getTrackPos() > 0) {
        right = trackInfo.getTrackWidth() * 0.5f + trackInfo.getTrackWidth() * 0.5f * (carState.getTrackPos());
        left = fabsf(trackInfo.getTrackWidth() - right);
    } else if (carState.getTrackPos() < 0) {
        right = fabsf(trackInfo.getTrackWidth() * 0.5f + trackInfo.getTrackWidth() * 0.5f * (carState.getTrackPos() - 1.0f));
        left = trackInfo.getTrackWidth() - right;
    } else if (carState.getTrackPos() == 0) {
        right = trackInfo.getTrackWidth() * 0.5f * carState.getTrackPos();
        left = trackInfo.getTrackWidth() * 0.5f * carState.getTrackPos();
    }

    if (carState.getTrackPos() > 1.0f || left < 0) {
        left = 0;
    } else if (carState.getTrackPos() < -1.0f || right < 0) {
        right = 0;
    }

    // TODO: To be implemented correctly
    TrackPoint trackPoint = trackInfo.getClosestCurvatureTrackPoint(carState.getTrackPos());
    if (carState.getDistFromStart() > distanceToCurvatureReaction) {
        if (trackPoint.getTrackCurvature() == TrackPoint::TRACK_CURVATURE_LEFT) {
            Charge charge;
            Vector2 pos(MathUtility::convertKilometerPerHourToMeterPerSecond(carState.getSpeedX()) * dt, right);
            charge.setAngle(pos.angle());
            charge.setCharge(0.0212f * MathUtility::convertKilometerPerHourToMeterPerSecond(carState.getSpeedX()) * 10 * calculateKValue(carState.getDistFromStart()));
            potentialField.push_back(charge);
        } else if (trackPoint.getTrackCurvature() == TrackPoint::TRACK_CURVATURE_RIGHT) {
            Charge charge;
            Vector2 pos(MathUtility::convertKilometerPerHourToMeterPerSecond(carState.getSpeedX()) * dt, left);
            charge.setAngle(pos.angle());
            charge.setCharge(0.0212f * MathUtility::convertKilometerPerHourToMeterPerSecond(carState.getSpeedX()) * 10 * calculateKValue(carState.getDistFromStart()));
            potentialField.push_back(charge);
        }
    }
    /*
	if (carState.getDistRaced() > 500 && !trackScanner.getDataWritten()) {
		trackScanner.writeTrackNodesToFile();
		std::cout << "data written" << std::endl;
	}
*/

}

void CurveAgent::calculatePotentialToAgentOptions(std::vector<AgentOption> &options)
{
    if (!options.empty() && !potentialField.empty()) {
        for (unsigned int i = 0; i < options.size(); i++) {
            Charge &charge = potentialField.front();
            AgentOption &agentOption = options.at(i);
            float length = (charge.getPosition() - agentOption.getPosition()).length();
            float width = left + right;
            float chargeValue = charge.getCharge();
            float potential = (1-(length/width));
            if (potential < 0.0f) {
                potential = 0.0f;
            }
            agentOption.setCurveAgentPotentialValue(potential * chargeValue);
        }
    }
}


const float CurveAgent::calculateKValue(const float lengthToCurvature)
{
    return (-1*powf(150-lengthToCurvature,2.0f)*0.001) + 10;
}
