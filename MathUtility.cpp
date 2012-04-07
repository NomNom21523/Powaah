/*
 *  MathUtility.cpp
 *  powaah
 *
 *  Created by Tim Uusitalo on 4/4/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "MathUtility.h"




extern const float MathUtility::pi = 3.14159265f;

extern const float MathUtility::DEG_TO_RAD = MathUtility::pi / 180.0f;

extern const float MathUtility::VEL_KM_TO_M = 1 / 3.6f;

extern const float MathUtility::MAX_VELOCITY = 302 * MathUtility::VEL_KM_TO_M;

extern const float MathUtility::MAX_DISTANCE = 1 / 200.0f;

extern const float MathUtility::RAD_TO_DEG = 180.0f / MathUtility::pi;

const float MathUtility::convertDegToRad(const float angle)
{
        return angle * DEG_TO_RAD;
}

const float MathUtility::convertRadToDeg(const float angle)
{
        return angle * RAD_TO_DEG;
}

const float MathUtility::cosineLawGetC(const float a, const float b, const float alpha)
{
        float c = pow(a,2) + pow(b,2);

        c -= 2 * a * b * cos(alpha);

        c = sqrt(c);

        return c;
}

const float MathUtility::cosineLawGetCSquared(const float a, const float b, const float alpha)
{
        float c_squared = pow(a,2) + pow(b,2);

        c_squared -= 2 * a * b * cos(alpha);

        return c_squared;

}

const float MathUtility::lerp(const float a, const float b, const float t)
{
        return ((1-t)*a) + (t*b);
}

const float MathUtility::slerp(const float a, const float b, const float alpha, const float t)
{
        return ((sin((1-t)*alpha)/sin(alpha)) * a) + (((sin(t*alpha))/sin(alpha))*b);
}

const float MathUtility::potential(const float charge, const float length)
{
        return charge / powf(length,2);
}

const float MathUtility::potentialSquareRoot(const float charge, const float length)
{
        return charge / sqrtf(length);
}

const Vector2 MathUtility::calculatePosition(const float angle, const float length)
{
        return Vector2(cos(angle) * length, sin(angle)*length);
}
