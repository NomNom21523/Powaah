/*
 *  MathUtility.h
 *  powaah
 *
 *  Created by Tim Uusitalo on 4/4/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef MATH_UTILITY_H

#define MATH_UTILITY_H

#include <cmath>

#include "Vector2.h"

namespace MathUtility
{
    extern const float pi;
    extern const float DEG_TO_RAD;
    extern const float VEL_KM_TO_M;
    extern const float MAX_VELOCITY;
    extern const float MAX_DISTANCE;
    extern const float RAD_TO_DEG;
    /**
     * Converts incoming angle (measured in degree) to radians
     * @param angle - Incoming angle
     */
    const float convertDegToRad(const float angle);

    /**
     * Converts incoming angle (measured in radians) to degrees
     * @param angle - incoming angle
     * @return - returns converted angle in degrees
     */
    const float convertRadToDeg(const float angle);

    /**
     * To get the side C in a triangle using The law of Cosinus
     * @param a - The side a in the triangle
     * @param b - The side b in the triangle
     * @param alpha - The angle between these two sides
     */
    const float cosineLawGetC(const float a, const float b, const float alpha);

    /**
     * To get the side C-squared in a triangle using The law of Cosinus
     * This might be used for various speed boost since it does not use the square root
     * @param a - The side a in the triangle
     * @param b - The side b in the triangle
     * @param alpha - The angle between these two sides
     */
    const float cosineLawGetCSquared(const float a, const float b, const float alpha);

    /**
     * Linear interpolates two points (a and b) with a time-value (t, usually between 0-1)
     * @param a - Point a
     * @param b -Point b
     * @param t - Time value, a value between 0-1
     */
    const float lerp(const float a, const float b, const float t);

    /**
     * Circular interpolates two points (a and b) with a time-value, t, and
     * uses a angle between the two points for the circularity
     * @param a - Point a
     * @param b - Point b
     * @param alpha - The angle between these two points
     * @param t - The time constant, a value between 0-1
     */
    const float slerp(const float a, const float b, const float alpha, const float t);

    /**
     * Calculates a potential for a charge and the length between
     * the charge and where I'm currently standing at
     * @param charge - incoming charge
     * @ param length - incoming length
     * @return - charge / length^2
     */
    const float potential(const float charge, const float length);

    /**
     * Calculates a potential for a charge and the length between
     * the charge and where I'm currently standing at
     * @param charge - incoming charge
     * @ param length - incoming length
     * @return - charge / sqrt(length)
     */
    const float potentialSquareRoot(const float charge, const float length);

    /**
     * Calculates a position from a current angle and
     * a current length
     * @param angle - Incoming angle, in radians
     * @param length - in meter (or any unit really)
     * @return - Returns calculated position
     */
    const Vector2 calculatePosition(const float angle, const float length);

    /*!
     * \brief convertKilometerPerHourToMeterPerSecond
     *
     * Converts a velocity from kilometer per hour to meter per second
     * \param velocityInKilometerPerSecond incoming velocity en kilometer per hour
     * \return converted velocity in meter per second
     */
    const float convertKilometerPerHourToMeterPerSecond(const float velocityInKilometerPerHour);
};


#endif
