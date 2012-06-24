#ifndef TRACKINFO_H
#define TRACKINFO_H

#include "Track.h"

class TrackInfo : public Track
{
public:
    TrackInfo(const std::string &filename);
    ~TrackInfo();

    /*!
     * Initializes track info, tries to read a file specified in
     * TrackInfo filename constructor.
     */
    void init();

    const float getTrackWidth() const;
    void setTrackWidth(const float width);

private:

    /*!
     * @todo implementation
     *
     * Normalizes curvatures
     *
     * I.e., in race mode, the track sensors have fuzzy readings. It may result in that a
     * left handed turn contain track nodes that points at right, with this function
     * the curvature is normalized so that all track sensors contain left if it is a
     * left handed curvature.
     * In some rare cases, where a curvature goes first right and then left, the normalization function
     * may convert that into a left handed one. This shall be fixed as soon as the developer
     * has time to correct it.
     */
    void normalizeCurvatures();

private:
    float trackWidth;

};

#endif // TRACKINFO_H
