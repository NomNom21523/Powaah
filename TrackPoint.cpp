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

void TrackPoint::setTrackPosition(const float trackPosition)
{
    this->trackPosition = trackPosition;
}

const float TrackPoint::getTrackPosition() const
{
    return trackPosition;
}
