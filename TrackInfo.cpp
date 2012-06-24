#include "TrackInfo.h"
#include "TrackDataFile.h"

TrackInfo::TrackInfo(const std::string &filename)
    : Track(filename)
{
}

TrackInfo::~TrackInfo()
{

}

void TrackInfo::init()
{
	// fetch track nodes from saved track file
	TrackDataFile::readTrackPointsFromFile(trackPoints, trackName);

}

const float TrackInfo::getTrackWidth() const {
    return trackWidth;
}

void TrackInfo::setTrackWidth(const float width) {
    trackWidth = width;
}

// private helper functions below

void TrackInfo::normalizeCurvatures()
{
    if (trackPoints.size() > 0) {
        float width = 0.0f;

        for (unsigned int i = 0; i < trackPoints.size(); i++) {
            TrackPoint &trackPoint =  trackPoints[i];
            CarState &carState = trackPoint.getCarState();
            float left = 0, right = 0;

            if (carState.getTrack(18) > 0) {
                right = (cosf(carState.getAngle() * carState.getTrack(18)));
            } else if(carState.getTrack(18) <= 0) {
                right = 0;
            }

            if (carState.getTrack(0) > 0) {
                left = (cosf(-carState.getAngle() * carState.getTrack(0)));
            } else if (carState.getTrack(0) <= 0) {
                left = 0;
            }
            width += left + right;
        }
        trackWidth = width / (float)trackPoints.size();
    }
}
