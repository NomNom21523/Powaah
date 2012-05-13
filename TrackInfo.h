#ifndef TRACKINFO_H
#define TRACKINFO_H

#include "Track.h"

class TrackInfo : public Track
{
public:
    TrackInfo(const std::string &filename);
    ~TrackInfo();

    void init();

};

#endif // TRACKINFO_H
