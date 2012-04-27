#include "TrackDataFile.h"

bool TrackDataFile::readTrackPointsFromFile(std::vector<TrackPoint> &trackData, std::string &trackname)
{
    FileDesc description;
    description.file_name = trackname + ".trk";
    description.elements = File::fetchElementSizeFromFile(description);
    description.size = sizeof(TrackPoint);

    if (description.elements > 0) {
        trackData.resize(description.elements);
        File::readDataFromFile(description);
        return true;
    }
    return false;
}

bool TrackDataFile::writeTrackPointsToFile(std::vector<TrackPoint> &trackData, std::string &trackname)
{
    if (!trackData.empty()) {
        FileDesc description;
        description.file_name = trackname + ".trk";
        description.elements = trackData.size();
        description.size = sizeof(TrackPoint);
        description.data = (char*)&trackData.front();
        File::writeDataToFile(description);
        return true;
    }

    return false;
}
