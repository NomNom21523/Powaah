#ifndef CURVEAGENT_H
#define CURVEAGENT_H

#include "Agent.h"
#include "TrackScanner.h"

class CurveAgent : public Agent
{
public:
    CurveAgent();
    ~CurveAgent();

    void update(CarState &carState, const float dt);
    void calculatePotentialToAgentOptions(std::vector<AgentOption> &options);

private:
    TrackScanner trackScanner;
};

#endif // CURVEAGENT_H
