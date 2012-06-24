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
        float closestTrackPointLength = trackPoints.front().getCarState().getTrackPos();
        unsigned int iterator = 0;

        // searchfor track nodes that are closer to current track point than closestTrackPoint
        for (unsigned int i = 1; i < trackPoints.size(); i++) {
            TrackPoint &trackPoint = trackPoints.at(i);

            if (trackPoint.getCarState().getTrackPos() < closestTrackPointLength) {
                iterator = i;
                closestTrackPointLength = trackPoint.getCarState().getTrackPos();
            }
        }
        return trackPoints[iterator];
    }
    return TrackPoint();
}

const TrackPoint Track::getClosestCurvatureTrackPoint(const float currentTrackPos)
{
    if (!trackPoints.empty()) {
        // set closestTrackPoint to some arbitrary big number
        float closestTrackPointLength = trackPoints.front().getCarState().getTrackPos();
        unsigned int iterator = 0;

        // searchfor track nodes that are closer to current track point than closestTrackPoint
        for (unsigned int i = 1; i < trackPoints.size(); i++) {
            TrackPoint &trackPoint = trackPoints.at(i);

            if (trackPoint.getCarState().getTrackPos() < closestTrackPointLength
                    && trackPoint.getTrackCurvature() != TrackPoint::TRACK_CURVATURE_NONE) {
                iterator = i;
                closestTrackPointLength = trackPoint.getCarState().getTrackPos();
            }
        }
        return trackPoints[iterator];
    }
    return TrackPoint();
}

// protected virtual functions

void Track::update(const CarState &carState, const float dt)
{
}


// private helper functions

const TrackPoint::TrackCurvature Track::getTrackCurvature(CarState &carState)
{
    if (carState.getTrack(8) > carState.getTrack(10)) {
        return TrackPoint::TRACK_CURVATURE_LEFT;
    } else if (carState.getTrack(10) > carState.getTrack(8)) {
        return TrackPoint::TRACK_CURVATURE_RIGHT;
    }
    return TrackPoint::TRACK_CURVATURE_NONE;
}
