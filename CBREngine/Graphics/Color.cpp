#include "Color.h"

namespace CBREngine
{
  namespace Graphics
  {
    float Color::R() const
    {
      return arr[0];
    }

    float Color::G() const
    {
      return arr[1];
    }

    float Color::B() const
    {
      return arr[2];
    }

    float Color::A() const
    {
      return arr[3];
    }

    void Color::SetR(float _r)
    {
      arr[0] = _r;

      if (arr[0] < 0)
        arr[0] = 0;
      if (arr[0] > 1)
        arr[0] = 1;
    }

    void Color::SetR(unsigned char _r)
    {
      arr[0] = _r / 255.0f;
    }

    void Color::SetG(float _g)
    {
      arr[1] = _g;

      if (arr[1] < 0)
        arr[1] = 0;
      if (arr[1] > 1)
        arr[1] = 1;
    }

    void Color::SetG(unsigned char _g)
    {
      arr[1] = _g / 255.0f;
    }

    void Color::SetB(float _b)
    {
      arr[2] = _b;

      if (arr[2] < 0)
        arr[2] = 0;
      if (arr[2] > 1)
        arr[2] = 1;
    }

    void Color::SetB(unsigned char _b)
    {
      arr[2] = _b / 255.0f;
    }

    void Color::SetA(float _a)
    {
      arr[3] = _a;

      if (arr[3] < 0)
        arr[3] = 0;
      if (arr[3] > 1)
        arr[3] = 1;
    }

    void Color::SetA(unsigned char _a)
    {
      arr[3] = _a / 255.0f;
    }

    const float * Color::ToRGBA() const
    {
      return arr;
    }

    float * Color::ToRGBA()
    {
      return arr;
    }

    float * Color::ToARGB(float * _arr) const
    {
      _arr[0] = arr[3];
      _arr[1] = arr[0];
      _arr[2] = arr[1];
      _arr[3] = arr[2];
      return _arr;
    }

    float * Color::ToRGB(float * _arr) const
    {
      _arr[0] = arr[0];
      _arr[1] = arr[1];
      _arr[2] = arr[2];
      return _arr;
    }

    Color Color::operator+(const Color & other) const
    {
      return Color(R() + other.R(), G() + other.G(), B() + other.B, A() + other.A());
    }

    Color Color::operator-(const Color & other) const
    {
      return Color(R() - other.R(), G() - other.G(), B() - other.B, A() - other.A());
    }

    Color Color::operator*(const Color & other) const
    {
      return Color(R() * other.R(), G() * other.G(), B() * other.B, A() * other.A());
    }

    Color & Color::operator+=(const Color & other)
    {
      SetR(R() + other.R());
      SetG(G() + other.G());
      SetB(B() + other.B());
      SetA(A() + other.A());
      return *this;
    }

    Color & Color::operator-=(const Color & other)
    {
      SetR(R() - other.R());
      SetG(G() - other.G());
      SetB(B() - other.B());
      SetA(A() - other.A());
      return *this;
    }

    Color & Color::operator*=(const Color & other)
    {
      SetR(R() * other.R());
      SetG(G() * other.G());
      SetB(B() * other.B());
      SetA(A() * other.A());
      return *this;
    }

    Color::Color(float * _arr, bool useARGB)
    {
      if (!useARGB)
      {
        SetR(_arr[0]);
        SetG(_arr[1]);
        SetB(_arr[2]);
        SetA(_arr[3]);
      }
      else
      {
        SetA(_arr[0]);
        SetR(_arr[1]);
        SetG(_arr[2]);
        SetB(_arr[3]);
      }
    }

    Color::Color(float r, float g, float b, float a)
    {
      SetR(r);
      SetG(g);
      SetB(b);
      SetA(a);
    }

    Color::Color(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
    {
      SetR(r / 255.0f);
      SetG(g / 255.0f);
      SetB(b / 255.0f);
      SetA(a / 255.0f);
    }

    Color::Color(unsigned int argb)
    {
      SetB((argb & 0xFF) / 255.0f);
      SetG(((argb >> 8) & 0xFF) / 255.0f);
      SetR(((argb >> 16) & 0xFF) / 255.0f);
      SetA(((argb >> 24) & 0xFF) / 255.0f);
    }
  }
}
