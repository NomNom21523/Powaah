#ifndef TRACKPOINT_H
#define TRACKPOINT_H

#include "Vector2.h"

class TrackPoint
{
public:
    TrackPoint();
    ~TrackPoint();

    void setPosition(const Vector2 &position);
    const Vector2 getPosition() const;

    void setTrackPosition(const float trackPosition);
    const float getTrackPosition() const;

private:
    Vector2 position;
    float trackPosition;

};

#endif // TRACKPOINT_H
