#pragma once
#include <iostream>
#include "Vector2.h"

namespace CBREngine
{
  namespace Core
  {
    struct Size2f
    {
      /// <summary>
      /// the Width
      /// </summary>
      float Width;
      /// <summary>
      /// the Height
      /// </summary>
      float Height;

      /// <summary>
      /// swaps the width and height vales in the size. Eg: Before- (width, height)  ->  After- (height, width) 
      /// </summary>
      Size2f SwapVariables() const;

      friend std::ostream &operator<<(std::ostream &stream, const Size2f& vector);
      Size2f operator+(const Size2f &rhs) const;
      Size2f operator+(float rhs) const;
      Size2f operator-(const Size2f &rhs) const;
      Size2f operator-(float rhs) const;
      Size2f operator-() const;
      Size2f operator*(const Size2f &rhs);
      Size2f operator*(float rhs);
      friend Size2f operator*(float lhs, Size2f rhs);
      Size2f operator/(const Size2f &rhs);
      Size2f operator/(float rhs);
      bool operator==(const Size2f &rhs);
      bool operator!=(const Size2f &rhs);
      //conversion to Size2 in Size2.h

      /// <summary>
      /// Creates a size with two values being given Width and Height
      /// </summary>
      /// <param name="width">The Width</param>
      /// <param name="height">The Height</param>
      Size2f(float width, float height);
      /// <summary>
      /// Creates a Size2 with the given value as both variables.
      /// </summary>
      /// <param name="widthAndHeight">Value to make both Width and Height</param>
      Size2f(float widthAndHeight);
      /// <summary>
      /// Creates a size in the 2D plane with the values of height and width both being 0
      /// </summary>
      Size2f();
    };
  }
}
