#ifndef TRACKSCANNER_H
#define TRACKSCANNER_H

#include "Track.h"

class TrackScanner : public Track
{
public:
    TrackScanner(const std::string &filename);
    ~TrackScanner();

    void init();

    void update(CarState &carState, const float dt);

private:
    const bool newTrackNode(CarState &carState);

private:

    // Defines the length between each track point in meters.
    static const float LENGTH_BETWEEN_TRACKPOINTS;
};

#endif // TRACKSCANNER_H
