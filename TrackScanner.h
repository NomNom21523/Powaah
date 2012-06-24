#ifndef TRACKSCANNER_H
#define TRACKSCANNER_H

#include "Track.h"
#include "TrackDataFile.h"

class TrackScanner : public Track
{
public:
    TrackScanner(const std::string &filename);
    ~TrackScanner();

    void init();

    void update(CarState &carState, const float dt);

    void writeTrackNodesToFile();

    const bool getDataWritten() const;

    const CarState getLastRecordedCarState();

    const bool isTrackPointsEmpty();

private:
    const bool newTrackNode(CarState &carState);

private:

    // Defines the length between each track point in meters.
    static const float LENGTH_BETWEEN_TRACKPOINTS;
    static const float MAX_SENSOR_LENGTH = 200.0f;
    bool dataWritten;
};

#endif // TRACKSCANNER_H
