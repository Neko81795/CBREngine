#include "Size2f.h"
#include <cmath>


namespace CBREngine
{
  namespace Core
  {
    static float PI = 3.141592653589793238f;

    Size2f Size2f::SwapVariables() const
    {
      return Size2f(Height, Width);
    }

    Size2f Size2f::operator+(const Size2f & rhs) const
    {
      return Size2f(Width + rhs.Width, Height + rhs.Height);
    }

    Size2f Size2f::operator+(float rhs) const
    {
      return Size2f(Width + rhs, Height + rhs);
    }

    Size2f Size2f::operator-(const Size2f & rhs) const
    {
      return Size2f(Width - rhs.Width, Height - rhs.Height);;
    }

    Size2f Size2f::operator-(float rhs) const
    {
      return Size2f(Width - rhs, Height - rhs);
    }

    Size2f Size2f::operator-() const
    {
      return Size2f(-Width, -Height);
    }

    Size2f Size2f::operator*(const Size2f & rhs)
    {
      return Size2f(Width * rhs.Width, Height * rhs.Height);
    }

    Size2f Size2f::operator*(float rhs)
    {
      return Size2f(Width * rhs, Height * rhs);
    }

    Size2f Size2f::operator/(const Size2f & rhs)
    {
      return Size2f(Width / rhs.Width, Height / rhs.Height);
    }

    Size2f Size2f::operator/(float rhs)
    {
      return Size2f(Width / rhs, Height / rhs);
    }

    bool Size2f::operator==(const Size2f & rhs)
    {
      if (Width != rhs.Width)
        return false;
      if (Height != rhs.Height)
        return false;
      return true;
    }

    bool Size2f::operator!=(const Size2f & rhs)
    {
      return !(*this == rhs);
    }

    Size2f::Size2f(float x, float y)
    {
      Width = x;
      Height = y;
    }

    Size2f::Size2f(float x_and_y)
    {
      Width = x_and_y;
      Height = x_and_y;
    }

    Size2f::Size2f()
    {
      Width = 0;
      Height = 0;
    }

    std::ostream & operator<<(std::ostream & stream, const Size2f & vector)
    {
      stream << "(" << vector.Width << ", " << vector.Height << ")";
      return stream;
    }
    Size2f operator*(float lhs, Size2f rhs)
    {
      return rhs * lhs;
    }
  }
}
