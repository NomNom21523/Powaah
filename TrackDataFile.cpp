#include "TrackDataFile.h"

bool TrackDataFile::readTrackPointsFromFile(std::vector<TrackPoint> &trackData, std::string &trackname)
{
    FileDesc description;
    description.file_name += trackname;
    description.file_name += ".trk";
    description.elements = File::fetchElementSizeFromFile(description);
    description.size = sizeof(TrackPoint);

    trackData.resize(description.elements);
    trackData.reserve(description.elements);

    description.data = (char*)&trackData.front();
    if (description.elements > 0) {
        File::readDataFromFile(description);
        return true;
    }
    return false;
}

bool TrackDataFile::writeTrackPointsToFile(std::vector<TrackPoint> &trackData, std::string &trackname)
{
    if (!trackData.empty()) {
        FileDesc description;
        description.file_name += trackname;
        description.file_name += ".trk";
        description.elements = trackData.size();
        description.size = sizeof(TrackPoint);
        description.data = (char*)&trackData.front();
        File::writeDataToFile(description);
        return true;
    }

    return false;
}
