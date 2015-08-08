#pragma once
#include <iostream> //operator <<

namespace MistThread
{
  namespace Core
  {
    struct Vector2
    {
      /// <summary>
      /// the X value of the Vector
      /// </summary>
      float X;
      /// <summary>
      /// the Y value of the Vector
      /// </summary>
      float Y;

      /// <summary>
      /// Gets the angle(in radians) of a triangle defined by the x and y values of this vector. Y is vertical, X is horizontal.
      /// </summary>
      float GetAngleRadians() const;
      /// <summary>
      /// Sets the angle(in radians) of a triangle defined by the x and y values of this vector. Y is vertical, X is horizontal.
      /// </summary>
      void SetAngleRadians(float value);

      /// <summary>
      /// Gets the angle(in degrees) of a triangle defined by the x and y values of this vector. Y is vertical, X is horizontal.
      /// </summary>
      float GetAngleDegrees() const;
      /// <summary>
      /// Sets the angle(in degrees) of a triangle defined by the x and y values of this vector. Y is vertical, X is horizontal.
      /// </summary>
      /// <param name="value">The angle to set the Vector at</param>
      void SetAngleDegrees(float value);

      /// <summary>
      /// Gets the magnitude of this vector, with the square root computed. Slower.
      /// </summary>
      float GetMagnitude() const;
      /// <summary>
      /// Sets the magnitude of the vector
      /// </summary>
      void SetMagintude(float value);

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
      /// the distance to another vector2
      /// </summary>
      /// <param name="other"> the other vector </param>
      /// <returns> that distance </returns>
      float DistanceTo(const Vector2 &other) const;

      /// <summary>
      /// the squared distance to another vector2
      /// </summary>
      /// <param name="other"> the other vector </param>
      /// <returns> that distance </returns>
      float DistanceSquaredTo(const Vector2 &other) const;

      /// <summary>
      /// swaps the x and y vales in the vector. Eg: Before- (x, y)  ->  After- (y, x) 
      /// </summary>
      Vector2 SwapVariables() const;

      friend std::istream &operator>>(std::istream &stream, Vector2& vector);
      friend std::ostream &operator<<(std::ostream &stream, const Vector2& vector);
      Vector2 operator+(const Vector2 &rhs) const;
      Vector2 operator+(float rhs) const;
      Vector2 operator-(const Vector2 &rhs) const;
      Vector2 operator-(float rhs) const;
      Vector2 operator-() const;
      Vector2 operator*(const Vector2 &rhs) const;
      Vector2 operator*(float rhs) const;
      Vector2 operator/(const Vector2 &rhs) const;
      Vector2 operator/(float rhs) const;

      Vector2 &operator+=(const Vector2 &rhs);
      Vector2 &operator+=(float rhs);
      Vector2 &operator-=(const Vector2 &rhs);
      Vector2 &operator-=(float rhs);
      Vector2 &operator*=(const Vector2 &rhs);
      Vector2 &operator*=(float rhs);
      Vector2 &operator/=(const Vector2 &rhs);
      Vector2 &operator/=(float rhs);
      bool operator==(const Vector2 &rhs) const;
      bool operator!=(const Vector2 &rhs) const;

      /// <summary>
      /// Populates an array of size 2 with the values of X and Y
      /// </summary>
      /// <param name="arr"> The array to populate. MUST BE OF SIZE 2 </param>
      float *ToArray(float * arr)const;


      /// <summary>
      /// Creates a vector in the 2D plane with the given X and Y values
      /// </summary>
      /// <param name="x">The X value</param>
      /// <param name="y">The Y value</param>
      Vector2(float x, float y);
      /// <summary>
      /// Creates a vector2 with the given value as both variables.
      /// </summary>
      /// <param name="x_and_y">Value to make both X and Y</param>
      Vector2(float x_and_y);
      /// <summary>
      /// Creates a vector in the 2D plane with the values of X and Y both being 0
      /// </summary>
      Vector2();

      static const Vector2 Up;
      static const Vector2 Down;
      static const Vector2 Left;
      static const Vector2 Right;
      static const Vector2 Zero;
      static const Vector2 One;
    };
  }
}
