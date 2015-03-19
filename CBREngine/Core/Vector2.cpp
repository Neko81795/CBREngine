#include "Vector2.h"
#include <cmath>


namespace CBREngine
{
  namespace Core
  {
    static double PI = 3.141592653589793238;

    double Vector2::GetAngleRadians() const
    {
      return std::atan2(Y, X);
    }

    void Vector2::SetAngleRadians(double value)
    {
      double mag = GetMagnitude();
      X = std::cos(value) * mag;
      Y = std::sin(value) * mag;
    }

    double Vector2::GetAngleDegrees() const
    {
      return GetAngleRadians() * (180 / PI);
    }

    void Vector2::SetAngleDegrees(double value)
    {
      SetAngleRadians(value * (PI / 180));
    }

    double Vector2::GetMagnitude() const
    {
      return std::sqrt((X * X) + (Y * Y));
    }

    void Vector2::SetMagintude(double value)
    {
      double theta = GetAngleRadians();
      X = std::cos(theta) * value;
      Y = std::sin(theta) * value;
    }

    Vector2 Vector2::Translate(float angle, float distance) const
    {
      return Vector2(X + (std::cos(angle)*distance), Y + (std::sin(angle)*distance));
    }

    Vector2 Vector2::Normalize() const
    {
      double inv = 1 / GetMagnitude();
      Vector2 normalizedVector;
      normalizedVector.X = X * inv;
      normalizedVector.Y = Y * inv;
      return normalizedVector;
    }

    float Vector2::DistanceTo(const Vector2 & other) const
    {
      return (float)std::sqrt((other.X - X) * (other.X - X) + (other.Y - Y) * (other.Y - Y));
    }

    Vector2 Vector2::SwapVariables() const
    {
      return Vector2(Y, X);
    }

    Vector2 Vector2::operator+(const Vector2 & rhs) const
    {
      return Vector2(X + rhs.X, Y + rhs.Y);
    }

    Vector2 Vector2::operator+(double rhs) const
    {
      return Vector2(X + rhs, Y + rhs);
    }

    Vector2 Vector2::operator-(const Vector2 & rhs) const
    {
      return Vector2(X - rhs.X, Y - rhs.Y);;
    }

    Vector2 Vector2::operator-(double rhs) const
    {
      return Vector2(X - rhs, Y - rhs);
    }

    Vector2 Vector2::operator-() const
    {
      return Vector2(-X, -Y);
    }

    Vector2 Vector2::operator*(const Vector2 & rhs) const
    {
      return Vector2(X * rhs.X, Y * rhs.Y);
    }

    Vector2 Vector2::operator*(double rhs) const
    {
      return Vector2(X * rhs, Y * rhs);
    }

    Vector2 Vector2::operator/(const Vector2 & rhs) const
    {
      return Vector2(X / rhs.X, Y / rhs.Y);
    }

    Vector2 Vector2::operator/(double rhs) const
    {
      return Vector2(X / rhs, Y / rhs);
    }

    bool Vector2::operator==(const Vector2 & rhs) const
    {
      if (X != rhs.X)
        return false;
      if (Y != rhs.Y)
        return false;
      return true;
    }

    bool Vector2::operator!=(const Vector2 & rhs) const
    {
      return !(*this == rhs);
    }

    Vector2::Vector2(double x, double y)
    {
      X = x;
      Y = y;
    }

    Vector2::Vector2(float x_and_y)
    {
      X = x_and_y;
      Y = x_and_y;
    }

    Vector2::Vector2()
    {
      X = 0;
      Y = 0;
    }

    std::ostream & operator<<(std::ostream & stream, const Vector2 & vector)
    {
      stream << "(" << vector.X << ", " << vector.Y << ")";
      return stream;
    }
    Vector2 operator*(double lhs, const Vector2 & rhs)
    {
      return rhs * lhs;
    }
  }
}
