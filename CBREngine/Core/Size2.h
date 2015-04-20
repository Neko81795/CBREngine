#pragma once
#include <iostream>
#include "Size2f.h"
#include "Vector2.h"

namespace CBREngine
{
  namespace Core
  {
    struct Size2
    {
      /// <summary>
      /// the Width
      /// </summary>
      int Width;
      /// <summary>
      /// the Height
      /// </summary>
      int Height;

      /// <summary>
      /// swaps the width and height vales in the size. Eg: Before- (width, height)  ->  After- (height, width) 
      /// </summary>
      Size2 SwapVariables() const;

      friend std::ostream &operator<<(std::ostream &stream, const Size2& vector);
      Size2 operator+(const Size2 &rhs) const;
      Size2 operator+(int rhs) const;
      Size2 operator-(const Size2 &rhs) const;
      Size2 operator-(int rhs) const;
      Size2 operator-() const;
      Size2 operator*(const Size2 &rhs);
      Size2 operator*(int rhs);
      friend Size2 operator*(int lhs, Size2 rhs);
      Size2 operator/(const Size2 &rhs);
      Size2 operator/(int rhs);
      bool operator==(const Size2 &rhs);
      bool operator!=(const Size2 &rhs);
      explicit operator Size2F();

      /// <summary>
      /// Converts the size2d into a size2
      /// </summary>
      /// <param name="size">The size2d to get the value from</param>
      Size2(Size2F size);
      /// <summary>
      /// Creates a size with two values being given Width and Height
      /// </summary>
      /// <param name="width">The Width</param>
      /// <param name="height">The Height</param>
      Size2(int width, int height);
      /// <summary>
      /// Creates a Size2 with the given value as both variables.
      /// </summary>
      /// <param name="widthAndHeight">Value to make both Width and Height</param>
      Size2(int widthAndHeight);
      /// <summary>
      /// Creates a size in the 2D plane with the values of height and width both being 0
      /// </summary>
      Size2();
    };
  }
}
