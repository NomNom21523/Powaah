#include "TrackScanner.h"

const float TrackScanner::LENGTH_BETWEEN_TRACKPOINTS = 30.0f; // meter

TrackScanner::TrackScanner(const std::string &trackname)
    : Track(trackname), dataWritten(false)
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

		if (carState.getTrack(9) < MAX_SENSOR_LENGTH) {
			if (carState.getTrack(8) < carState.getTrack(10)) {
				trackPoint.setTrackCurvature(TrackPoint::TRACK_CURVATURE_RIGHT);
			}
			else if (carState.getTrack(8) > carState.getTrack(10)) {
				trackPoint.setTrackCurvature(TrackPoint::TRACK_CURVATURE_LEFT);
			}
		} else {
			trackPoint.setTrackCurvature(TrackPoint::TRACK_CURVATURE_NONE);
		}

		std::cout << "Adding tracknode" << std::endl;
		trackPoints.push_back(trackPoint);
	}
}

void TrackScanner::writeTrackNodesToFile()
{
	std::cout << "Writing: " << trackPoints.size() << " number of track nodes to file: " << trackName << ".trk" << std::endl;
	dataWritten = TrackDataFile::writeTrackPointsToFile(trackPoints, trackName);
}

const bool TrackScanner::getDataWritten() const
{
	return dataWritten;
}

const CarState TrackScanner::getLastRecordedCarState()
{
    return trackPoints.back().getCarState();
}

const bool TrackScanner::isTrackPointsEmpty()
{
    return trackPoints.empty();
}

// private helper functions below

const bool TrackScanner::newTrackNode(CarState &carState)
{
    if (!trackPoints.empty()) {
    	TrackPoint &trackPoint = trackPoints.back();
		float offset = carState.getDistFromStart() - trackPoint.getCarState().getDistFromStart();

		// when starting the race, the car is behind the race line, meaning that the first track
		// node will be like 1721meters, next will be around 26meters. If we do not have the suspect
		// 'offset < 0' code here, we will never get any track nodes.
		// However, the 'offset < 0' will work due that the offset never should be lesser than 0, if
		// we don't plan to drive the car around the track in the wrong direction.
		if (offset > LENGTH_BETWEEN_TRACKPOINTS || offset < 0) {
			return true;
		}
    } else {
    	return true;
    }
    return false;
}
