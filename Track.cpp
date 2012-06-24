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
        float closestTrackPointLength = fabs(trackPoints.front().getCarState().getDistFromStart() - currentTrackPoint);
        unsigned int iterator = 0;

        // searchfor track nodes that are closer to current track point than closestTrackPoint
        for (unsigned int i = 1; i < trackPoints.size(); i++) {
            TrackPoint &trackPoint = trackPoints.at(i);

            if (fabs(trackPoint.getCarState().getDistFromStart() - currentTrackPoint) < closestTrackPointLength) {
                iterator = i;
                closestTrackPointLength = fabs(trackPoint.getCarState().getDistFromStart() - currentTrackPoint);
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
        float closestTrackPointLength = fabs(trackPoints.front().getCarState().getDistFromStart() - currentTrackPos);
        unsigned int iterator = 0;

        // searchfor track nodes that are closer to current track point than closestTrackPoint
        for (unsigned int i = 1; i < trackPoints.size(); i++) {
            TrackPoint &trackPoint = trackPoints.at(i);

            float distanceToTrackPoint = trackPoint.getCarState().getDistFromStart() - currentTrackPos;
            if ( distanceToTrackPoint < closestTrackPointLength && distanceToTrackPoint > 0
                     && trackPoint.getTrackCurvature() != TrackPoint::TRACK_CURVATURE_NONE) {
                iterator = i;
                closestTrackPointLength = fabs(trackPoint.getCarState().getDistFromStart() - currentTrackPos);
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
