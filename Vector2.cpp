#include "Vector2.h"

Vector2::Vector2()
{
        x = 0.0f;
        y = 0.0f;
}

Vector2::Vector2(float x, float y)
{
        this->x = x;
        this->y = y;
}

Vector2::~Vector2()
{
}


Vector2 & Vector2::operator=(const Vector2 & vec)
{
        x = vec.x;
        y = vec.y;
        return *this;
}

Vector2 & Vector2::operator+=(const Vector2 & vec)
{
        x += vec.x;
        y += vec.y;

        return *this;
}

Vector2 & Vector2::operator+=(const float & f)
{
        x += f;
        y += f;

        return *this;
}

Vector2 & Vector2::operator-=(const Vector2 & vec)
{
        x -= vec.x;
        y -= vec.y;
        return *this;
}

Vector2 & Vector2::operator-=(const float & f)
{
        x -= f;
        y -= f;
        return *this;
}

Vector2 & Vector2::operator*=(const Vector2 & vec)
{
        x *= vec.x;
        y *= vec.y;
        return *this;
}

Vector2 & Vector2::operator*=(const float & f)
{
        x *= f;
        y *= f;
        return *this;
}

Vector2 & Vector2::operator/=(const Vector2 & vec)
{
        x /= vec.x;
        y /= vec.y;
        return *this;
}

Vector2 & Vector2::operator/=(const float & f)
{
        x /= f;
        y /= f;
        return *this;
}

Vector2 Vector2::operator+(const Vector2 & vec) const
{
        return Vector2(x + vec.x, y + vec.y);
}

Vector2 Vector2::operator+(const float & f) const
{
        return Vector2(x + f, y + f);
}

Vector2 Vector2::operator-(const Vector2 & vec) const
{
        return Vector2(x - vec.x, y - vec.y);
}

Vector2 Vector2::operator-(const float & f) const
{
        return Vector2(x - f, y - f);
}

Vector2 Vector2::operator*(const Vector2 & vec) const
{
        return Vector2(x * vec.x, y * vec.y);
}

Vector2 Vector2::operator*(const float & f) const
{
        return Vector2(x * f, y * f);
}

Vector2 Vector2::operator/(const Vector2 & vec) const
{
        return Vector2(x / vec.x , y / vec.y);
}

Vector2 Vector2::operator/(const float & f) const
{
        return Vector2(x / f , y / f);
}

Vector2 Vector2::operator-() const
{
    return Vector2(-x, -y);
}

float Vector2::dot(const Vector2 &vec) const
{
        return ( (x * vec.x) + (y * vec.y) );
}

Vector2 Vector2::cross() const
{
        return Vector2( -y, x );
}

Vector2 Vector2::abs() const
{
    return Vector2(std::abs(x), std::abs(y));
}

float Vector2::length() const
{
        return sqrtf( (powf(x, 2.0f) + (powf(y, 2.0f)) ));
}

float Vector2::lengthSq() const
{
        return ( (x * x) + (y * y) );
}

Vector2 Vector2::normalize() const
{
        return Vector2( x, y ) * ( 1 / length() ) ;
}

const float Vector2::angle() const
{
        return atan2f(y, x);
}


const Vector2 Vector2::rotate(const Vector2 &c, const float arc) const
{
        Vector2 d = *this-c;
    float sina = sin(arc), cosa = cos(arc);
    return c + Vector2(d.x*cosa-d.y*sina, d.x*sina+d.y*cosa);
}

std::ostream & operator<< ( std::ostream & stream , const Vector2 & self )
{
        stream << "<" << self.x << ", " << self.y << ">";

        return stream;
}
