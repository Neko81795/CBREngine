#include "Vector3.h"
#include <cmath>


namespace CBREngine
{
  namespace Core
  {
    static float PI = 3.141592653589793238f;

    float Vector3::GetMagnitude() const
    {
      float xy = std::sqrt((X * X) + (Y * Y));
      return (float)std::sqrt((xy * xy) + (Z * Z));
    }

    void Vector3::SetMagintude(float value)
    {
      Normalize();
      *this *= value;
    }

    Vector3 Vector3::Normalize() const
    {
      float inv = 1 / GetMagnitude();
      Vector3 normalizedVector;
      normalizedVector.X = X * inv;
      normalizedVector.Y = Y * inv;
      normalizedVector.Z = Z * inv;
      return normalizedVector;
    }

    float Vector3::DistanceTo(const Vector3 & other) const
    {
      float xy = std::sqrt(((other.X - X) * (other.X - X)) + ((other.Y - Y) * (other.Y - Y)));
      return (float)std::sqrt((xy * xy) + ((other.Z - Z) * (other.Z - Z)));
    }

    float Vector3::DistanceSquaredTo(const Vector3 & other) const
    {
      float xy = std::sqrt(((other.X - X) * (other.X - X)) + ((other.Y - Y) * (other.Y - Y)));
      return (xy * xy) + ((other.Z - Z) * (other.Z - Z));
    }

    Vector3 Vector3::operator+(const Vector3 & rhs) const
    {
      return Vector3(X + rhs.X, Y + rhs.Y, Z + rhs.Z);
    }

    Vector3 Vector3::operator+(float rhs) const
    {
      return Vector3(X + rhs, Y + rhs, Z + rhs);
    }

    Vector3 Vector3::operator-(const Vector3 & rhs) const
    {
      return Vector3(X - rhs.X, Y - rhs.Y, Z - rhs.Z);;
    }

    Vector3 Vector3::operator-(float rhs) const
    {
      return Vector3(X - rhs, Y - rhs, Z - rhs);
    }

    Vector3 Vector3::operator-() const
    {
      return Vector3(-X, -Y, -Z);
    }

    Vector3 Vector3::operator*(const Vector3 & rhs) const
    {
      return Vector3(X * rhs.X, Y * rhs.Y, Z * rhs.Z);
    }

    Vector3 Vector3::operator*(float rhs) const
    {
      return Vector3(X * rhs, Y * rhs, Z * rhs);
    }

    Vector3 Vector3::operator/(const Vector3 & rhs) const
    {
      return Vector3(X / rhs.X, Y / rhs.Y, Z / rhs.Z);
    }

    Vector3 Vector3::operator/(float rhs) const
    {
      return Vector3(X / rhs, Y / rhs, Z / rhs);
    }

    Vector3 & Vector3::operator+=(const Vector3 & rhs)
    {
      X += rhs.X;
      Y += rhs.Y;
      Z += rhs.Z;
      return *this;
    }

    Vector3 & Vector3::operator+=(float rhs)
    {
      X += rhs;
      Y += rhs;
      Z += rhs;
      return *this;
    }

    Vector3 & Vector3::operator-=(const Vector3 & rhs)
    {
      X -= rhs.X;
      Y -= rhs.Y;
      Z -= rhs.Z;
      return *this;
    }

    Vector3 & Vector3::operator-=(float rhs)
    {
      X -= rhs;
      Y -= rhs;
      Z -= rhs;
      return *this;
    }

    Vector3 & Vector3::operator*=(const Vector3 & rhs)
    {
      X *= rhs.X;
      Y *= rhs.Y;
      Z *= rhs.Z;
      return *this;
    }

    Vector3 & Vector3::operator*=(float rhs)
    {
      X *= rhs;
      Y *= rhs;
      Z *= rhs;
      return *this;
    }

    Vector3 & Vector3::operator/=(const Vector3 & rhs)
    {
      X /= rhs.X;
      Y /= rhs.Y;
      Z /= rhs.Z;
      return *this;
    }

    Vector3 & Vector3::operator/=(float rhs)
    {
      X /= rhs;
      Y /= rhs;
      Z /= rhs;
      return *this;
    }

    bool Vector3::operator==(const Vector3 & rhs) const
    {
      if (X != rhs.X)
        return false;
      if (Y != rhs.Y)
        return false;
      if (Z != rhs.Z)
        return false;
      return true;
    }

    bool Vector3::operator!=(const Vector3 & rhs) const
    {
      return !(*this == rhs);
    }

    float * Vector3::ToArray(float * arr) const
    {
      arr[0] = X;
      arr[1] = Y;
      arr[2] = Z;
      return arr;
    }


    Vector3::Vector3(float x, float y, float z)
    {
      X = x;
      Y = y;
      Z = z;
    }

    Vector3::Vector3(float x_and_y_and_z)
    {
      X = x_and_y_and_z;
      Y = x_and_y_and_z;
      Z = x_and_y_and_z;
    }

    Vector3::Vector3(Vector2 x_and_y, float z)
    {
      X = x_and_y.X;
      Y = x_and_y.Y;
      Z = z;
    }

    Vector3::Vector3(float x, Vector2 y_and_z)
    {
      X = x;
      Y = y_and_z.X;
      Z = y_and_z.Y;
    }

    Vector3::Vector3()
    {
      X = 0;
      Y = 0;
      Z = 0;
    }

    std::ostream & operator<<(std::ostream & stream, const Vector3 & vector)
    {
      stream << "(" << vector.X << ", " << vector.Y << ", " << vector.Z << ")";
      return stream;
    }
  }
}
