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
