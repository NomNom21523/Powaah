#ifndef TRACKDATAFILE_H
#define TRACKDATAFILE_H

#include "File.h"
#include "TrackPoint.h"
#include <vector>

class TrackDataFile : public File
{
public:
    bool readTrackPointsFromFile(std::vector<TrackPoint> &trackData, std::string &trackname);
    bool writeTrackPointsToFile(std::vector<TrackPoint> &trackData, std::string &trackname);
};

#endif // TRACKDATAFILE_H
