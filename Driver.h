#ifndef DRIVERAGENT_H
#define DRIVERAGENT_H

#include "AgentOption.h"
#include "CurveAgent.h"
#include "TrackAgent.h"
#include "SpeedAgent.h"
#include "CarState.h"

class Driver
{
public:
    /*!
     * Constructor
     */
    Driver();

    /*!
     * Destructor
     */
    ~Driver();

    /*!
     * Updates agent options depending on current CarState
     * @carstate - Current carstate
     * @dt - the delta time, time between frames
     */
    void update(CarState &carState, const float dt);

    /*!
     * Sends agentoptions into all agents and calculates
     * a potential value for each agent options.
     */
    const AgentOption getAgentOption();

private:
    std::vector<AgentOption> agentOptions;
    CurveAgent curveAgent;
    TrackAgent trackAgent;
    SpeedAgent speedAgent;


    float acceleration[6];
    float decceleration;

};

#endif // DRIVERAGENT_H
