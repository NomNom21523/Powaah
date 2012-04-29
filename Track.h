#ifndef TRACK_H
#define TRACK_H

#include "TrackPoint.h"
#include "CarState.h"

#include <vector>

enum TrackMode {
    TRACK_MODE_NONE,
    TRACK_MODE_SCAN,
    TRACK_MODE_NORMAL
};

enum TrackCurvature {
    TRACK_CURVATURE_NONE,
    TRACK_CURVATURE_LEFT,
    TRACK_CURVATURE_RIGHT
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
     * When scanning track, update() may add new track points.
     * In the old Powaah, every 30m of track got a track point.
     * In this function, wherever the track is more interesting,
     * it scans more frequent than on less interesting parts of the track.
     *
     * Interesting points are:
     *  * Curvatures
     *
     * Meanwhile less interesting points are:
     *  * Straights
     *
     */
    void update(const CarState &carState, const float dt);

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
    /*!
     * Determines wether the track goes right, left or straight at a current point
     * @param carState Current car state
     * @return Curren track curvature for given car state.
     */
    const TrackCurvature getTrackCurvature(CarState &carState);

private:
    std::vector<TrackPoint> trackPoints;
    TrackMode trackMode;
    std::string trackName;

};

#endif // TRACK_H
