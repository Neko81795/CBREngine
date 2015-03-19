#pragma once
#include <iostream>

namespace CBREngine
{
  namespace Core
  {
    struct Vector2
    {
      /// <summary>
      /// the X value of the Vector
      /// </summary>
      double X;
      /// <summary>
      /// the Y value of the Vector
      /// </summary>
      double Y;

      /// <summary>
      /// Gets the angle(in radians) of a triangle defined by the x and y values of this vector. Y is vertical, X is horizontal.
      /// </summary>
      double GetAngleRadians() const;
      /// <summary>
      /// Sets the angle(in radians) of a triangle defined by the x and y values of this vector. Y is vertical, X is horizontal.
      /// </summary>
      void SetAngleRadians(double value);

      /// <summary>
      /// Gets the angle(in degrees) of a triangle defined by the x and y values of this vector. Y is vertical, X is horizontal.
      /// </summary>
      double GetAngleDegrees() const;
      /// <summary>
      /// Sets the angle(in degrees) of a triangle defined by the x and y values of this vector. Y is vertical, X is horizontal.
      /// </summary>
      /// <param name="value">The angle to set the Vector at</param>
      void SetAngleDegrees(double value);

      /// <summary>
      /// Gets the magnitude of this vector, with the square root computed. Slower.
      /// </summary>
      double GetMagnitude() const;
      /// <summary>
      /// Sets the magnitude of the vector
      /// </summary>
      void SetMagintude(double value);

      /// <summary>
      /// Returns a new Vector2 that has been translated x units along theta's axis
      /// </summary>
      /// <param name="angle">The angle in degrees</param>
      /// <param name="distance">The distance to move</param>
      Vector2 Translate(float angle, float distance) const;

      /// <summary>
      /// returns the normalized version of this vector as a new vector2
      /// </summary>
      /// <returns>the normalized version of this vector</returns>
      Vector2 Normalize() const;

      /// <summary>
      /// the distance to another vector2, assuming you are using it like a crappy point.
      /// </summary>
      /// <param name="other"></param>
      /// <returns>that distance</returns>
      float DistanceTo(const Vector2 &other) const;

      /// <summary>
      /// swaps the x and y vales in the vector. Eg: Before- (x, y)  ->  After- (y, x) 
      /// </summary>
      Vector2 SwapVariables() const;
      
      friend std::ostream &operator<<(std::ostream &stream, const Vector2& vector);
      Vector2 operator+(const Vector2 &rhs) const;
      Vector2 operator+(double rhs) const;
      Vector2 operator-(const Vector2 &rhs) const;
      Vector2 operator-(double rhs) const;
      Vector2 operator-() const;
      Vector2 operator*(const Vector2 &rhs) const;
      Vector2 operator*(double rhs) const;
      friend Vector2 operator*(double lhs, const Vector2 &rhs);
      Vector2 operator/(const Vector2 &rhs) const;
      Vector2 operator/(double rhs) const;
      bool operator==(const Vector2 &rhs) const;
      bool operator!=(const Vector2 &rhs) const;


      /// <summary>
      /// Creates a vector in the 2D plane with the given X and Y values
      /// </summary>
      /// <param name="x">The X value</param>
      /// <param name="y">The Y value</param>
      Vector2(double x, double y);
      /// <summary>
      /// Creates a vector2 with the given value as both variables.
      /// </summary>
      /// <param name="x_and_y">Value to make both X and Y</param>
      Vector2(float x_and_y);
      /// <summary>
      /// Creates a vector in the 2D plane with the values of X and Y both being 0
      /// </summary>
      Vector2();
    };
  }
}
