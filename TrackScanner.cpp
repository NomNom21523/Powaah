#include "TrackScanner.h"

const float TrackScanner::LENGTH_BETWEEN_TRACKPOINTS = 30.0f; // meter

TrackScanner::TrackScanner(const std::string &filename)
    : Track(filename)
{
}

TrackScanner::~TrackScanner()
{

}

void TrackScanner::init()
{

}

void TrackScanner::update(CarState &carState, const float dt)
{
    if (newTrackNode(carState)) {
        // scan the track and record TrackPoint data
        TrackPoint trackPoint;
        trackPoint.setCarState(carState);
    }
}


// private helper functions below

const bool TrackScanner::newTrackNode(CarState &carState)
{
    if (trackPoints.empty()) {
        return true;
    } else {
        TrackPoint trackPoint = trackPoints.back();
        float offset = carState.getTrackPos() - trackPoint.getCarState().getTrackPos();
        if (offset > LENGTH_BETWEEN_TRACKPOINTS) {
                return true;
        }
    }
    return false;
}