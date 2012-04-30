#ifndef AGENTOPTION_H
#define AGENTOPTION_H

#include "Vector2.h"

/*!
 * @class AgentOption
 * @author Tim Uusitalo
 * @date 2012-04-30
 *
 * @brief AgentOption is a class that defines an approximated point to where
 * the driver may go to until next frame.
 *
 * AgentOption defines an approximated point on the track to where the PowaahDriver may go to
 * until next frame. The approximation shall not be thought of as a real point where the
 * car may go to, since it does not calculate the approximation with real car physics. Instead
 * one could say that it's an approximation of where the "driver" (Powaah in this case) thinks
 * it can go to until the next frame.
 *
 * AgentOption has a length, an angle and a 2D position where it is placed relative from the car position
 * and the car direction. The actual calculation of the point can be found in the update function of the
 * class Driver.
 *
 * AgentOption has several potential values, one for each Agent, this so one can easily observe
 * what potential value each Agent calculates. It sums all potential values into one final value,
 * so that when a desicion is to be made, the AgentOption with highest potential value shall be chosen.
 *
 */
class AgentOption
{
public:

    /*!
     * Constructor
     */
    AgentOption();

    /*!
     * Destructor
     */
    ~AgentOption();

    /*!
     * Sets length to a new length value
     * @param length The new length value
     */
    void setLength(const float length);

    /*!
     * Retrieves length value
     * @return The value of length
     */
    const float getLength() const;

    /*!
     * Sets angle to a new angle value
     * @param angle The new angle value
     */
    void setAngle(const float angle);

    /*!
     * Retrieves angle value
     * @return The value of angle
     */
    const float getAngle() const;

    /*!
     * Sets position to a new value
     * @param position The new position value
     */
    void setPosition(const Vector2 &position);

    /*!
     * Retrieves the value of position
     * @return The value of position
     */
    const Vector2 getPosition() const;

    // TODO: Check if this shall exist
    /*!
     * Sets the final potential value (maybe this shall not exist)
     * @param potential_value The new value of potential_value
     */
    void setPotentialValue(const float potential_value);

    /*!
     * Retrieves the final summed potential value
     * @return The final summed potential value
     */
    const float getPotentialValue() const;

    /*!
     * Sets the accelerator value (should have a value between 0.0f and 1.0f)
     * @param accelerator_value The new accelerator value
     */
    void setAcceleratorValue(const float accelerator_value);

    /*!
     * Retrieves the accelerator value (should have a value between 0.0f and 1.0f)
     * @return The accelerator value
     */
    const float getAcceleratorValue() const;

    /*!
     * Sets the brake value (should have a value between 0.0f and 1.0f)
     * @param brakeValue The new brake value
     */
    void setBrakeValue(const float brakeValue);

    /*!
     * Retrieves the brake value (should have a value between 0.0f and 1.0f)
     * @return The brake value
     */
    const float getBrakeValue() const;

    /*!
     * Sets the potential value for curve agent
     * @param curveAgentPotentialValue The new potential value for curve agent
     */
    void setCurveAgentPotentialValue(const float curveAgentPotentialValue);

    /*!
     * Retrieves the potential value for curve agent
     * @return The current potential value for curve agent
     */
    const float getCurveAgentPotentialValue() const;

    /*!
     * Sets the potential value for speed agent
     * @param speedAgentPotentialValue The current potential value for speed agent
     */
    void setSpeedAgentPotentialValue(const float speedAgentPotentialValue);

    /*!
     * Retrieves the potential value for speed agent
     * @return The current potential value for speed agent
     */
    const float getSpeedAgentPotentialValue() const;

    /*!
     * Sets the potential value for track agent
     * @param trackAgentPotentialValue The new potential value for track agent
     */
    void setTrackAgentPotentialValue(const float trackAgentPotentialValue);

    /*!
     * Retrieves the potential value for track agent
     * @return The current potential value for track agent
     */
    const float getTrackAgentPotentialValue() const;
private:
    float length;
    float angle;
    Vector2 position;
    float potential_value;
    float accelerator_value;
    float brakeValue;
    float curveAgentPotentialValue;
    float speedAgentPotentialValue;
    float trackAgentPotentialValue;

    int counter;
};

#endif // AGENTOPTION_H
