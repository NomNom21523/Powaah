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
};

#endif // CURVEAGENT_H
