#include "Charge.h"

Charge::Charge()
{
}

Charge::Charge(const float angle, const Vector2 &position, const float charge)
{
    this->angle = angle;
    this->position = position;
    this->charge = charge;
}

Charge::~Charge()
{

}

void Charge::update()
{

}

void Charge::setAngle(const float angle)
{
    this->angle = angle;
}

const float Charge::getAngle() const
{
    return this->angle;
}

void Charge::setPosition(const Vector2 &position)
{
    this->position = position;
}

const Vector2 Charge::getPosition() const
{
    return this->position;
}

void Charge::setCharge(const float charge)
{
    this->charge = charge;
}

const float Charge::getCharge() const
{
    return this->charge;
}
