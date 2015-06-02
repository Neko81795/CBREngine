#pragma once
#include <iostream> //operator <<
#include "Vector2.h"

namespace CBREngine
{
  namespace Core
  {
    struct Vector3
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
      /// the Z value of the Vector
      /// </summary>
      float Z;

      //TODO add implementation here!
      /*/// <summary>
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
      void SetAngleDegrees(float value);*/

      /// <summary>
      /// Gets the magnitude of this vector, with the square root computed. Slower.
      /// </summary>
      float GetMagnitude() const;
      /// <summary>
      /// Sets the magnitude of the vector
      /// </summary>
      void SetMagintude(float value);

      /// <summary>
      /// returns the normalized version of this vector as a new vector3
      /// </summary>
      /// <returns>the normalized version of this vector</returns>
      Vector3 Normalize() const;

      /// <summary>
      /// the distance to another vector3
      /// </summary>
      /// <param name="other"> the other vector </param>
      /// <returns> that distance </returns>
      float DistanceTo(const Vector3 &other) const;

      /// <summary>
      /// the squared distance to another vector3
      /// </summary>
      /// <param name="other"> the other vector </param>
      /// <returns> that distance </returns>
      float DistanceSquaredTo(const Vector3 &other) const;

      friend std::ostream &operator<<(std::ostream &stream, const Vector3& vector);
      Vector3 operator+(const Vector3 &rhs) const;
      Vector3 operator+(float rhs) const;
      Vector3 operator-(const Vector3 &rhs) const;
      Vector3 operator-(float rhs) const;
      Vector3 operator-() const;
      Vector3 operator*(const Vector3 &rhs) const;
      Vector3 operator*(float rhs) const;
      Vector3 operator/(const Vector3 &rhs) const;
      Vector3 operator/(float rhs) const;
      
      Vector3 &operator+=(const Vector3 &rhs);
      Vector3 &operator+=(float rhs);
      Vector3 &operator-=(const Vector3 &rhs);
      Vector3 &operator-=(float rhs);
      Vector3 &operator*=(const Vector3 &rhs);
      Vector3 &operator*=(float rhs);
      Vector3 &operator/=(const Vector3 &rhs);
      Vector3 &operator/=(float rhs);

      bool operator==(const Vector3 &rhs) const;
      bool operator!=(const Vector3 &rhs) const;

      /// <summary>
      /// Populates an array of size 3 with the values of X, Y, and Z
      /// </summary>
      /// <param name="arr"> The array to populate. MUST BE OF SIZE 3 </param>
      float *ToArray(float * arr)const;


      /// <summary>
      /// Creates a vector in the 2D plane with the given X, Y, and Z values
      /// </summary>
      /// <param name="x">The X value</param>
      /// <param name="y">The Y value</param>
      /// <param name="z">The Z value</param>
      Vector3(float x, float y, float z);
      /// <summary>
      /// Creates a vector3 with the given value as all 3 variables.
      /// </summary>
      /// <param name="x_and_y_and_z">Value to make X, Y, and Z</param>
      Vector3(float x_and_y_and_z);
      /// <summary>
      /// Creates a vector3 with X and Y set by the vector2 and Z set by the given float
      /// </summary>
      /// <param name="x_and_y">Value to make X and Y</param>
      /// <param name="z">The Z value</param>
      Vector3(Vector2 x_and_y, float z);
      /// <summary>
      /// Creates a vector3 with X set by the given float and both Y and Z set by the vector2
      /// </summary>
      /// <param name="x">The X value</param>
      /// <param name="y_and_z">Value to make Y and Z. X becomes Y, Y becomes Z</param>
      Vector3(float x, Vector2 y_and_z);
      /// <summary>
      /// Creates a vector in the 3D plane with the values of X, Y, and Z all being 0
      /// </summary>
      Vector3();
    };
  }
}
