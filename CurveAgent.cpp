#include "CurveAgent.h"

#include <iostream>

CurveAgent::CurveAgent()
: trackScanner("test")
{
}

CurveAgent::~CurveAgent()
{

}

void CurveAgent::update(CarState &carState, const float dt)
{
	trackScanner.update(carState, dt);

	if (carState.getDistRaced() > 500 && !trackScanner.getDataWritten()) {
		trackScanner.writeTrackNodesToFile();
		std::cout << "data written" << std::endl;
	}
}

void CurveAgent::calculatePotentialToAgentOptions(std::vector<AgentOption> &options)
{

}
