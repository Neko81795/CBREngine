#include "RectangleF.h"

namespace CBREngine
{
  namespace Core
  {
    float RectangleF::GetLeft() const
    {
      return X;
    }

    float RectangleF::GetRight() const
    {
      return X + Width;
    }

    float RectangleF::GetTop() const
    {
      return Y;
    }

    float RectangleF::GetBottom() const
    {
      return Y + Height;
    }

    void RectangleF::SetLeft(float left)
    {
      X = left;
    }

    void RectangleF::SetRight(float right)
    {
      Width = right - X;
    }

    void RectangleF::SetTop(float top)
    {
      Y = top;
    }

    void RectangleF::SetBottom(float bottom)
    {
      Height = bottom - Y;
    }

#if WIN32
    RectangleF::operator D2D_RECT_F&()
    {
      Rect.left = X;
      Rect.top = Y;
      Rect.right = GetRight();
      Rect.bottom = GetBottom();
      return Rect;
    }

    RectangleF::operator D2D_RECT_F() const
    {
      return D2D1::RectF(X, Y, GetRight(), GetBottom());
    }
#endif

    RectangleF::RectangleF()
    {
      X = 0;
      Y = 0;
      Height = 0;
      Width = 0;
    }

    RectangleF::RectangleF(float x, float y, float width, float height)
    {
      X = x;
      Y = y;
      Width = width;
      Height = height;
    }
  }
}
