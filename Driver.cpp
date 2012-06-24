#include "Driver.h"
#include "MathUtility.h"

Driver::Driver()
{
    agentOptions.reserve(500);

    /************************************************************
    *   some precalculated acceleration values for each gear    *
    *   calculated at forza track, but should be enough for our *
    *   look ahead-points                                       *
    *   m/s^2                                                   *
    ************************************************************/

    acceleration[0] = 7.1666667f;
    acceleration[1] = 6.045f;
    acceleration[2] = 4.8783f;
    acceleration[3] = 4.05f;
    acceleration[4] = 2.81f;
    acceleration[5] = 2.04f;
    decceleration = -21.16f;

    for (float angle = -45.0f; angle <= 45.0f; angle += 5.0f) {
        for (float ab = 0.0f; ab <= 1.0f; ab += 0.2f)
        {
            AgentOption option;
            option.setLength(0.0f);
            option.setAngle(angle);
            option.setAcceleratorValue(ab);
            agentOptions.push_back(option);
        }


        for (float ab = 0.6f; ab <= 1.0f; ab += 0.2f)
        {
            AgentOption option;
            option.setLength(0.0f);
            option.setAngle(angle);
            option.setBrakeValue(ab);
            agentOptions.push_back(option);
        }
    }

}

Driver::~Driver()
{

}

void Driver::update(CarState &carState, const float dt)
{
    int gear = carState.getGear();

    if (gear > 1) {
        gear --;
    }
    else if (gear < 1) {
        gear = 0;
    }


    for (unsigned int i = 0; i < agentOptions.size(); i++) {
        float currentVelocity = carState.getSpeedX() / 3.6f;
        float resVelocity = currentVelocity;
        float currentAcceleration = acceleration[gear] * agentOptions[i].getAcceleratorValue();

        if (carState.getSpeedX() > 5.0f) {
            currentAcceleration += decceleration * agentOptions[i].getBrakeValue();
        }
        resVelocity += currentAcceleration;

        agentOptions[i].setLength(((currentVelocity + resVelocity)*0.5f)*dt);

        agentOptions[i].setPosition(MathUtility::calculatePosition(MathUtility::convertDegToRad(agentOptions[i].getAngle()), agentOptions[i].getLength()));
    }

    // add the five front sensors
    float targetSpeed = carState.getTrack(7) + carState.getTrack(8) + carState.getTrack(9) + carState.getTrack(10) + carState.getTrack(11);

    // divide them by five to get roughly calculated target speed
    targetSpeed /= 5.f;

    if (stage == BaseDriver::WARMUP) {
        targetSpeed = 8.33333333;
    }

    // multiply by frame time
    targetSpeed *= dt;

    speedAgent.setTargetSpeed(targetSpeed);
    speedAgent.update(carState, dt);
    speedAgent.calculatePotentialToAgentOptions(agentOptions);

    trackAgent.update(carState, dt);
    trackAgent.calculatePotentialToAgentOptions(agentOptions);

    curveAgent.setSpeed(targetSpeed);
    curveAgent.update(carState, dt);
    curveAgent.calculatePotentialToAgentOptions(agentOptions);

    for (unsigned int i = 0; i < agentOptions.size(); i++) {
        float potentialValue = 0.0f;
        potentialValue += agentOptions[i].getSpeedAgentPotentialValue();
        potentialValue += agentOptions[i].getTrackAgentPotentialValue();
        potentialValue += agentOptions[i].getCurveAgentPotentialValue();
        agentOptions[i].setPotentialValue(potentialValue);
    }
}


const AgentOption Driver::getAgentOption() {
    AgentOption &option = agentOptions[0];
    for (unsigned int i = 1; i < agentOptions.size(); i++) {
        if (agentOptions[i].getPotentialValue() > option.getPotentialValue()) {
            option = agentOptions[i];
        }
    }
    return option;
}

void Driver::setStage(BaseDriver::tstage stage)
{
    this->stage = stage;
    curveAgent.setStage(stage);
    speedAgent.setStage(stage);
}
