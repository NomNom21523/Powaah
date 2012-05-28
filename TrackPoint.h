#ifndef TRACKPOINT_H
#define TRACKPOINT_H

#include "Vector2.h"
#include "CarState.h"

class TrackPoint
{
public:
    enum TrackCurvature {
        TRACK_CURVATURE_NONE,
        TRACK_CURVATURE_LEFT,
        TRACK_CURVATURE_RIGHT
    };

public:
    TrackPoint();
    ~TrackPoint();

    void setPosition(const Vector2 &position);
    const Vector2 getPosition() const;

    void setTrackCurvature(const TrackCurvature trackCurvature);
    const TrackCurvature getTrackCurvature() const;

    void setCarState(CarState &carState);
    CarState &getCarState();


private:
    Vector2 position;
    TrackCurvature trackCurvature;
    CarState carState;
};

#endif // TRACKPOINT_H
