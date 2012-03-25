#ifndef CHARGE_H
#define CHARGE_H

#include "Vector2.h"
class Charge
{
public:
    Charge();
    Charge(const float angle, const Vector2 &position, const float charge);
    ~Charge();

    void update();

    void setAngle(const float angle);
    const float getAngle() const;

    void setPosition(const Vector2 &position);
    const Vector2 getPosition() const;

    void setCharge(const float charge);
    const float getCharge() const;

private:
    float angle;
    Vector2 position;
    float charge;
};

#endif // CHARGE_H
