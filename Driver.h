#ifndef DRIVERAGENT_H
#define DRIVERAGENT_H

#include "AgentOption.h"
#include "CurveAgent.h"
#include "TrackAgent.h"
#include "SpeedAgent.h"
#include "OvertakeAgent.h"
#include "CarState.h"
#include "BaseDriver.h"

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

    void setStage(BaseDriver::tstage stage);


private:
    std::vector<AgentOption> agentOptions;
    CurveAgent      curveAgent;
    TrackAgent      trackAgent;
    SpeedAgent      speedAgent;
    OvertakeAgent   overtakeAgent;


    float acceleration[6];
    float decceleration;
    BaseDriver::tstage stage;
};

#endif // DRIVERAGENT_H
