#ifndef TRACKSCANNER_H
#define TRACKSCANNER_H

#include "Track.h"

class TrackScanner : public Track
{
public:
    TrackScanner(const std::string &filename);
    ~TrackScanner();

    void init();

    void update(const CarState &carState, const float dt);

};

#endif // TRACKSCANNER_H
