#include "CurveAgent.h"

#include <iostream>

#include "MathUtility.h"

const float CurveAgent::distanceToCurvatureReaction = 300.0f; // value in meter

CurveAgent::CurveAgent()
    : trackInfo("test"), trackScanner("test")
{
    trackInfo.init();
    scanning = false;
}

CurveAgent::~CurveAgent()
{

}

void CurveAgent::update(CarState &carState, const float dt)
{
    if (stage != BaseDriver::WARMUP) {
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
        TrackPoint trackPoint = trackInfo.getClosestCurvatureTrackPoint(carState.getDistFromStart());
        float distanceToCurvature = carState.getTrack(9);
        // std::cout << "distance to curvature: " << distanceToCurvature << std::endl;

        if (distanceToCurvature < 200.0f) {
            if (trackPoint.getTrackCurvature() == TrackPoint::TRACK_CURVATURE_LEFT) {
                Charge charge;
                Vector2 pos(speed, right);
                charge.setAngle(pos.angle());
                charge.setCharge(0.212f * (speed/dt)*10*calculateKValue(distanceToCurvature));
                potentialField.push_back(charge);
                std::cout << "Curve go left" << std::endl;
            } else if (trackPoint.getTrackCurvature() == TrackPoint::TRACK_CURVATURE_RIGHT) {
                Charge charge;
                Vector2 pos(speed, -1*left);
                charge.setAngle(pos.angle());
                charge.setCharge(0.212f * (speed/dt)*10*calculateKValue(distanceToCurvature));
                potentialField.push_back(charge);
                std::cout << "Curve go right" << std::endl;
            }
        }
    } else if (stage == BaseDriver::WARMUP) {
        trackScanner.update(carState, dt);
        if (carState.getLastLapTime() > 0 && !trackScanner.getDataWritten()) {
            trackScanner.writeTrackNodesToFile();
            std::cout << "Writing data to file" << std::endl;
            scanning = false;
        }
    }
}

void CurveAgent::calculatePotentialToAgentOptions(std::vector<AgentOption> &options)
{
    if (!options.empty() && !potentialField.empty() && stage != BaseDriver::WARMUP) {
        for (unsigned int i = 0; i < options.size(); i++) {
            Charge &charge = potentialField.front();
            AgentOption &agentOption = options.at(i);
            float length = (charge.getPosition() - agentOption.getPosition()).length();
            float width = left + right;
            float chargeValue = charge.getCharge();
            float potential = (length/width);
            if (potential < 0.0f) {
                potential = 0.0f;
            }
            agentOption.setCurveAgentPotentialValue(potential * chargeValue);
        }
    }
}

void CurveAgent::setStage(const BaseDriver::tstage stage)
{
    this->stage = stage;
    if (stage == BaseDriver::WARMUP) {
        scanning = true;
    }
}

const bool CurveAgent::isScanning() const
{
    return scanning;
}

void CurveAgent::setSpeed(const float speed)
{
    this->speed = speed;
}

const float CurveAgent::getSpeed() const
{
    return speed;
}

const float CurveAgent::calculateKValue(const float lengthToCurvature)
{
    return (-1*powf(150-lengthToCurvature,2.0f)*0.001f) + 10;
}
