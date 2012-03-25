#ifndef DRIVERAGENT_H
#define DRIVERAGENT_H

#include "AgentOption.h"
#include "CurveAgent.h"
#include "TrackAgent.h"
#include "SpeedAgent.h"

class Driver
{
public:
    Driver();

private:
    std::vector<AgentOption> agentOptions;
    CurveAgent curveAgent;
    TrackAgent trackAgent;
    SpeedAgent speedAgent;

};

#endif // DRIVERAGENT_H
