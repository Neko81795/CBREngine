#pragma once

#if WIN32
#pragma warning(disable: 4838) //disable conversion warnings
#pragma warning(disable: 4458) //disable hiding class members
#include <d2d1.h>
#include <d2d1helper.h>
#pragma warning(default: 4458) //enable hiding class members
#pragma warning(default: 4838) //enable conversion warnings
#endif

namespace CBREngine
{
  namespace Core
  {
    struct RectangleF
    {
      float X;
      float Y;
      float Height;
      float Width;

      float GetLeft() const;
      float GetRight() const;
      float GetTop() const;
      float GetBottom() const;

      void SetLeft(float left);
      void SetRight(float right);
      void SetTop(float top);
      void SetBottom(float bottom);

#if WIN32
      operator D2D_RECT_F&();
      D2D_RECT_F Rect;
      operator D2D_RECT_F() const;
#endif

      RectangleF();
      RectangleF(float x, float y, float width, float height);

    };

  }
}
