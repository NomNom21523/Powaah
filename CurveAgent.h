#ifndef CURVEAGENT_H
#define CURVEAGENT_H

#include "Agent.h"
#include "TrackInfo.h"

class CurveAgent : public Agent
{
public:
    CurveAgent();
    ~CurveAgent();

    void update(CarState &carState, const float dt);
    void calculatePotentialToAgentOptions(std::vector<AgentOption> &options);

private:
    const float calculateKValue(const float lengthToCurvature);
private:
    TrackInfo trackInfo;
    static const float distanceToCurvatureReaction;
    float left;
    float right;
};

#endif // CURVEAGENT_H
