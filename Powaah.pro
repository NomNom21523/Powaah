### eqmake4 was here ###
CONFIG -= debug_and_release debug
CONFIG += release

TEMPLATE = app
CONFIG += console
CONFIG -= qt

SOURCES += \
    Agent.cpp \
    SpeedAgent.cpp \
    CurveAgent.cpp \
    TrackAgent.cpp \
    Track.cpp \
    AgentOption.cpp \
    Vector2.cpp \
    MathUtility.cpp \
    Driver.cpp \
    CarControl.cpp \
    CarState.cpp \
    SimpleDriver.cpp \
    SimpleParser.cpp \
    WrapperBaseDriver.cpp \
    client.cpp \
    PowaahDriver.cpp

HEADERS += \
    Agent.h \
    SpeedAgent.h \
    CurveAgent.h \
    TrackAgent.h \
    Track.h \
    AgentOption.h \
    Vector2.h \
    MathUtility.h \
    Driver.h \
    BaseDriver.h \
    CarControl.h \
    CarState.h \
    SimpleDriver.h \
    SimpleParser.h \
    WrapperBaseDriver.h \
    PowaahDriver.h

