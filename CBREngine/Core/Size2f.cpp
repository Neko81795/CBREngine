#include "Size2f.h"
#include <cmath>


namespace CBREngine
{
  namespace Core
  {
    static float PI = 3.141592653589793238f;

    Size2F Size2F::SwapVariables() const
    {
      return Size2F(Height, Width);
    }

    Size2F Size2F::operator+(const Size2F & rhs) const
    {
      return Size2F(Width + rhs.Width, Height + rhs.Height);
    }

    Size2F Size2F::operator+(float rhs) const
    {
      return Size2F(Width + rhs, Height + rhs);
    }

    Size2F Size2F::operator-(const Size2F & rhs) const
    {
      return Size2F(Width - rhs.Width, Height - rhs.Height);;
    }

    Size2F Size2F::operator-(float rhs) const
    {
      return Size2F(Width - rhs, Height - rhs);
    }

    Size2F Size2F::operator-() const
    {
      return Size2F(-Width, -Height);
    }

    Size2F Size2F::operator*(const Size2F & rhs)
    {
      return Size2F(Width * rhs.Width, Height * rhs.Height);
    }

    Size2F Size2F::operator*(float rhs)
    {
      return Size2F(Width * rhs, Height * rhs);
    }

    Size2F Size2F::operator/(const Size2F & rhs)
    {
      return Size2F(Width / rhs.Width, Height / rhs.Height);
    }

    Size2F Size2F::operator/(float rhs)
    {
      return Size2F(Width / rhs, Height / rhs);
    }

    bool Size2F::operator==(const Size2F & rhs)
    {
      if (Width != rhs.Width)
        return false;
      if (Height != rhs.Height)
        return false;
      return true;
    }

    bool Size2F::operator!=(const Size2F & rhs)
    {
      return !(*this == rhs);
    }

    Size2F::Size2F(float x, float y)
    {
      Width = x;
      Height = y;
    }

    Size2F::Size2F(float x_and_y)
    {
      Width = x_and_y;
      Height = x_and_y;
    }

    Size2F::Size2F()
    {
      Width = 0;
      Height = 0;
    }

    std::ostream & operator<<(std::ostream & stream, const Size2F & vector)
    {
      stream << "(" << vector.Width << ", " << vector.Height << ")";
      return stream;
    }
    Size2F operator*(float lhs, Size2F rhs)
    {
      return rhs * lhs;
    }
  }
}
