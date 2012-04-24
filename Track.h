#ifndef TRACK_H
#define TRACK_H

#include"TrackPoint.h"
#include <vector>

enum TrackMode {
    TRACK_MODE_NONE,
    TRACK_MODE_SCAN,
    TRACK_MODE_NORMAL
};

class Track
{
public:
    /*!
     * Constructor, sets track mode
     * @param mode - the track mode
     */
    Track(TrackMode mode, const std::string &trackName);

    /*!
     * Destructor
     */
    ~Track();

    /*!
     * inits track in three different ways
     * 1 - TRACK_MODE_NONE - does nothing
     * 2 - TRACK_MODE_SCAN - inits the track in a scanning mode
     * 3 - TRACK_MODE_NORMAL - reads a file containing trackpoints for current track
     */
    void init();

    /*!
     * retrieves closest track point to current track point
     * @param currentTrackPoint - current track point
     * @return closest track point
     */
    const TrackPoint getCurrentTrackPoint(const float currentTrackPoint);

    /*!
     * retrieves current track mode
     * @return current track mode
     */
    const TrackMode getTrackMode() const;

private:
    std::vector<TrackPoint> trackPoints;
    TrackMode trackMode;
    std::string trackName;

};

#endif // TRACK_H
