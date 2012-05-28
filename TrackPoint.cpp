#include "TrackPoint.h"

TrackPoint::TrackPoint()
{
}

TrackPoint::~TrackPoint()
{
}

void TrackPoint::setPosition(const Vector2 &position)
{
    this->position = position;
}

const Vector2 TrackPoint::getPosition() const
{
    return position;
}

void TrackPoint::setTrackCurvature(const TrackPoint::TrackCurvature trackCurvature)
{
    this->trackCurvature = trackCurvature;
}

const TrackPoint::TrackCurvature TrackPoint::getTrackCurvature() const
{
    return trackCurvature;
}

void TrackPoint::setCarState(CarState &carState)
{
    this->carState = carState;
}

CarState &TrackPoint::getCarState()
{
    return carState;
}

