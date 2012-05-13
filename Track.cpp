#include "Track.h"

Track::Track(const std::string &trackName)
{
    this->trackName = trackName;
}

Track::~Track()
{
}

const TrackPoint Track::getCurrentTrackPoint(const float currentTrackPoint)
{
    if (!trackPoints.empty()) {
        // set closestTrackPoint to some arbitrary big number
        float closestTrackPointLength = trackPoints.front().getTrackPosition();
        unsigned int iterator = 0;

        // searchfor track nodes that are closer to current track point than closestTrackPoint
        for (unsigned int i = 1; i < trackPoints.size(); i++) {
            TrackPoint &trackPoint = trackPoints.at(i);

            if (trackPoint.getTrackPosition() < closestTrackPointLength) {
                iterator = i;
                closestTrackPointLength = trackPoint.getTrackPosition();
            }
        }
    }
    return TrackPoint();
}

// protected virtual functions

void Track::update(const CarState &carState, const float dt)
{
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
