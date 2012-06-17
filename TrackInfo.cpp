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

// private helper functions

void TrackInfo::normalizeCurvatures()
{
}
