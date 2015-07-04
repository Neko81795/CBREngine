#include "Vector2.h"
#include <cmath>


namespace MistThread
{
  namespace Core
  {
    static float PI = 3.141592653589793238f;

    float Vector2::GetAngleRadians() const
    {
      return std::atan2(Y, X);
    }

    void Vector2::SetAngleRadians(float value)
    {
      float mag = GetMagnitude();
      X = std::cos(value) * mag;
      Y = std::sin(value) * mag;
    }

    float Vector2::GetAngleDegrees() const
    {
      return GetAngleRadians() * (180 / PI);
    }

    void Vector2::SetAngleDegrees(float value)
    {
      SetAngleRadians(value * (PI / 180));
    }

    float Vector2::GetMagnitude() const
    {
      return std::sqrt((X * X) + (Y * Y));
    }

    void Vector2::SetMagintude(float value)
    {
      float theta = GetAngleRadians();
      X = std::cos(theta) * value;
      Y = std::sin(theta) * value;
    }

    Vector2 Vector2::Translate(float angle, float distance) const
    {
      return Vector2(X + (std::cos(angle)*distance), Y + (std::sin(angle)*distance));
    }

    Vector2 Vector2::Normalize() const
    {
      float inv = 1 / GetMagnitude();
      Vector2 normalizedVector;
      normalizedVector.X = X * inv;
      normalizedVector.Y = Y * inv;
      return normalizedVector;
    }

    float Vector2::DistanceTo(const Vector2 & other) const
    {
      return (float)std::sqrt((other.X - X) * (other.X - X) + (other.Y - Y) * (other.Y - Y));
    }

    float Vector2::DistanceSquaredTo(const Vector2 & other) const
    {
      return (other.X - X) * (other.X - X) + (other.Y - Y) * (other.Y - Y);
    }

    Vector2 Vector2::SwapVariables() const
    {
      return Vector2(Y, X);
    }

    Vector2 Vector2::operator+(const Vector2 & rhs) const
    {
      return Vector2(X + rhs.X, Y + rhs.Y);
    }

    Vector2 Vector2::operator+(float rhs) const
    {
      return Vector2(X + rhs, Y + rhs);
    }

    Vector2 Vector2::operator-(const Vector2 & rhs) const
    {
      return Vector2(X - rhs.X, Y - rhs.Y);;
    }

    Vector2 Vector2::operator-(float rhs) const
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

    Vector2 Vector2::operator*(float rhs) const
    {
      return Vector2(X * rhs, Y * rhs);
    }

    Vector2 Vector2::operator/(const Vector2 & rhs) const
    {
      return Vector2(X / rhs.X, Y / rhs.Y);
    }

    Vector2 Vector2::operator/(float rhs) const
    {
      return Vector2(X / rhs, Y / rhs);
    }

    Vector2 & Vector2::operator+=(const Vector2 & rhs)
    {
      X += rhs.X;
      Y += rhs.Y;
      return *this;
    }

    Vector2 & Vector2::operator+=(float rhs)
    {
      X += rhs;
      Y += rhs;
      return *this;
    }

    Vector2 & Vector2::operator-=(const Vector2 & rhs)
    {
      X -= rhs.X;
      Y -= rhs.Y;
      return *this;
    }

    Vector2 & Vector2::operator-=(float rhs)
    {
      X -= rhs;
      Y -= rhs;
      return *this;
    }

    Vector2 & Vector2::operator*=(const Vector2 & rhs)
    {
      X *= rhs.X;
      Y *= rhs.Y;
      return *this;
    }

    Vector2 & Vector2::operator*=(float rhs)
    {
      X *= rhs;
      Y *= rhs;
      return *this;
    }

    Vector2 & Vector2::operator/=(const Vector2 & rhs)
    {
      X /= rhs.X;
      Y /= rhs.Y;
      return *this;
    }

    Vector2 & Vector2::operator/=(float rhs)
    {
      X /= rhs;
      Y /= rhs;
      return *this;
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

    float * Vector2::ToArray(float * arr) const
    {
      arr[0] = X;
      arr[1] = Y;
      return arr;
    }


    Vector2::Vector2(float x, float y)
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
    Vector2 operator*(float lhs, const Vector2 & rhs)
    {
      return rhs * lhs;
    }


    const Vector2 Vector2::Up(0, -1);
    const Vector2 Vector2::Down(0, 1);
    const Vector2 Vector2::Left(-1, 0);
    const Vector2 Vector2::Right(1, 0);
    const Vector2 Vector2::Zero(0);
    const Vector2 Vector2::One(1);
  }
}
