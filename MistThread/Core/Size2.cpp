#include "Size2.h"
#include <cmath>


namespace MistThread
{
  namespace Core
  {
    Size2 Size2::SwapVariables() const
    {
      return Size2(Height, Width);
    }

    Size2 Size2::operator+(const Size2 & rhs) const
    {
      return Size2(Width + rhs.Width, Height + rhs.Height);
    }

    Size2 Size2::operator+(int rhs) const
    {
      return Size2(Width + rhs, Height + rhs);
    }

    Size2 Size2::operator-(const Size2 & rhs) const
    {
      return Size2(Width - rhs.Width, Height - rhs.Height);;
    }

    Size2 Size2::operator-(int rhs) const
    {
      return Size2(Width - rhs, Height - rhs);
    }

    Size2 Size2::operator-() const
    {
      return Size2(-Width, -Height);
    }

    Size2 Size2::operator*(const Size2 & rhs)
    {
      return Size2(Width * rhs.Width, Height * rhs.Height);
    }

    Size2 Size2::operator*(int rhs)
    {
      return Size2(Width * rhs, Height * rhs);
    }

    Size2 Size2::operator/(const Size2 & rhs)
    {
      return Size2(Width / rhs.Width, Height / rhs.Height);
    }

    Size2 Size2::operator/(int rhs)
    {
      return Size2(Width / rhs, Height / rhs);
    }

    bool Size2::operator==(const Size2 & rhs)
    {
      if (Width != rhs.Width)
        return false;
      if (Height != rhs.Height)
        return false;
      return true;
    }

    bool Size2::operator!=(const Size2 & rhs)
    {
      return !(*this == rhs);
    }

    Size2::operator Size2F()
    {
      return Size2F((float)Width, (float)Height);
    }

    Size2::Size2(Size2F size)
    {
      Height = (int)size.Height;
      Width = (int)size.Width;
    }

    Size2::Size2(int x, int y)
    {
      Width = x;
      Height = y;
    }

    Size2::Size2(int x_and_y)
    {
      Width = x_and_y;
      Height = x_and_y;
    }

    Size2::Size2()
    {
      Width = 0;
      Height = 0;
    }

    std::ostream & operator<<(std::ostream & stream, const Size2 & vector)
    {
      stream << "(" << vector.Width << ", " << vector.Height << ")";
      return stream;
    }
    Size2 operator*(int lhs, Size2 rhs)
    {
      return rhs * lhs;
    }

  }
}
