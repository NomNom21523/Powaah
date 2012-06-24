#ifndef CURVEAGENT_H
#define CURVEAGENT_H

#include "Agent.h"
#include "BaseDriver.h"
#include "TrackInfo.h"
#include "TrackScanner.h"

class CurveAgent : public Agent
{
public:
    CurveAgent();
    ~CurveAgent();

    void update(CarState &carState, const float dt);
    void calculatePotentialToAgentOptions(std::vector<AgentOption> &options);

    void setStage(const BaseDriver::tstage stage);

    const bool isScanning() const;

    void setSpeed(const float speed);
    const float getSpeed() const;

private:
    const float calculateKValue(const float lengthToCurvature);
private:
    TrackInfo trackInfo;
    TrackScanner trackScanner;
    static const float distanceToCurvatureReaction;
    float left;
    float right;
    BaseDriver::tstage stage;
    bool scanning;
    float speed;
};

#endif // CURVEAGENT_H
