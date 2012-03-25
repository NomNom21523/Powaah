#ifndef VECTOR2_H
#define VECTOR2_H

#include <ostream>
#include <cmath>

class Vector2
{
public:
        Vector2();
        Vector2(float x, float y);
        ~Vector2();

        Vector2 &       operator=       ( const Vector2 & vec );
        Vector2 &       operator+=      ( const Vector2 & vec );
        Vector2 &       operator+=      ( const float   &  f  );
        Vector2 &       operator-=      ( const Vector2 & vec );
        Vector2 &       operator-=      ( const float   &  f  );
        Vector2 &       operator*=      ( const Vector2 & vec );
        Vector2 &       operator*=      ( const float   &  f  );
        Vector2 &       operator/=      ( const Vector2 & vec );
        Vector2 &       operator/=      ( const float   &  f  );


        Vector2         operator+       ( const Vector2 & vec ) const;
        Vector2         operator+       ( const float   &  f  ) const;
        Vector2         operator-       ( const Vector2 & vec ) const;
        Vector2         operator-       ( const float   &  f  ) const;
        Vector2         operator*       ( const Vector2 & vec ) const;
        Vector2         operator*       ( const float   &  f  ) const;
        Vector2         operator/       ( const Vector2 & vec ) const;
        Vector2         operator/       ( const float   &  f  ) const;

    Vector2     operator-   ()                      const;


        float           dot                     ( const Vector2 & vec ) const;
        Vector2         cross           () const;
        Vector2         abs             () const;
        float           length          () const;
        float           lengthSq        () const;

        Vector2         normalize       () const;

        const float     angle           () const;

        const Vector2   rotate          (const Vector2 &c, const float arc) const;

        friend  std::ostream & operator<<( std::ostream & stream , const Vector2 & self );

public:
        float x;
        float y;
};

#endif
