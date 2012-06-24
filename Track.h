#ifndef TRACK_H
#define TRACK_H

#include "TrackPoint.h"
#include "CarState.h"

#include <vector>

class Track
{
public:

    /*!
     * Constructor, sets track mode
     * @param mode - the track mode
     */
    Track(const std::string &trackName);

    /*!
     * Destructor
     */
    virtual ~Track();

    /*!
     * retrieves closest track point to current track point
     * @param currentTrackPoint - current track point
     * @return closest track point
     */
    const TrackPoint getCurrentTrackPoint(const float currentTrackPoint);

    /*!
     * \brief getClosestCurvatureTrackPoint
     * retrieves the closest trackpoint that is a TRACK_CURVATURE_LEFT or TRACK_CURVATURE_RIGHT
     * \param currentTrackPos current track position from start
     * \return the closest trackpoint that is a TRACK_CURVATURE_LEFT or TRACK_CURVATURE_RIGHT
     */
    const TrackPoint getClosestCurvatureTrackPoint(const float currentTrackPos);

protected:
    /*!
     * inits track in two different ways
     * 2 - if class TrackScanner is used - inits the track in a scanning mode
     * 3 - if class TrackInfo - reads a file containing trackpoints for current track
     */
    virtual void init() = 0;

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


private:
    /*!
     * Determines wether the track goes right, left or straight at a current point
     * @param carState Current car state
     * @return Curren track curvature for given car state.
     */
    const TrackPoint::TrackCurvature getTrackCurvature(CarState &carState);

protected:
    std::vector<TrackPoint> trackPoints;
    std::string trackName;

};

#endif // TRACK_H
