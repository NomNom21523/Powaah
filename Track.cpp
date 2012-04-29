#include "Track.h"

Track::Track(TrackMode mode, const std::string &trackName)
    : trackMode(mode)
{
    this->trackName = trackName;
}

Track::~Track()
{
}

void Track::init()
{
    switch(trackMode) {
    case TRACK_MODE_NONE:
        break;
    case TRACK_MODE_SCAN:
        break;
    case TRACK_MODE_NORMAL:
        break;
    }
}

void Track::update(const CarState &carState, const float dt)
{
    if (trackMode == TRACK_MODE_SCAN) {

    }
}

const TrackPoint Track::getCurrentTrackPoint(const float currentTrackPoint)
{
    switch(trackMode) {
    case TRACK_MODE_NONE:
        break;
    case TRACK_MODE_SCAN:
        break;
    case TRACK_MODE_NORMAL:
        break;
    }

    return TrackPoint();
}

const TrackMode Track::getTrackMode() const
{
    return trackMode;
}


// private helper functions

const TrackCurvature Track::getTrackCurvature(CarState &carState)
{
    if (carState.getTrack(8) > carState.getTrack(10)) {
        return TRACK_CURVATURE_LEFT;
    } else if (carState.getTrack(10) > carState.getTrack(8)) {
        return TRACK_CURVATURE_RIGHT;
    }
    return TRACK_CURVATURE_NONE;
}
