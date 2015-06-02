#pragma once

#if WIN32
#pragma warning(disable: 4838) //disable conversion warnings
#pragma warning(disable: 4458) //disable hiding class members
#include <d2d1.h>
#include <d2d1helper.h>
#pragma warning(default: 4458) //enable hiding class members
#pragma warning(default: 4838) //enable conversion warnings
#endif

namespace MistThread
{
  namespace Graphics
  {
    struct Color
    {
    private:
      float arr[4];

    public:
      float R() const;
      float G() const;
      float B() const;
      float A() const;

      /// <summary>
      /// Sets the R value between 0 and 1
      /// </summary>
      void SetR(float _r);
      /// <summary>
      /// Sets the R value between 0 and 255
      /// </summary>
      void SetR(int _r);
      /// <summary>
      /// Sets the G value between 0 and 1
      /// </summary>
      void SetG(float _g);
      /// <summary>
      /// Sets the G value between 0 and 255
      /// </summary>
      void SetG(int _g);
      /// <summary>
      /// Sets the B value between 0 and 1
      /// </summary>
      void SetB(float _b);
      /// <summary>
      /// Sets the B value between 0 and 255
      /// </summary>
      void SetB(int _b);
      /// <summary>
      /// Sets the A value between 0 and 1
      /// </summary>
      void SetA(float _a);
      /// <summary>
      /// Sets the A value between 0 and 255
      /// </summary>
      void SetA(int _a);

      /// <summary>
      /// returns the underlying array
      /// </summary>
      const float *ToRGBA() const;

      /// <summary>
      /// returns the underlying array
      /// </summary>
      float *ToRGBA();

      /// <summary>
      /// fills the array (ARGB) and returns it. Array must be of size 4
      /// </summary>
      /// <param name="_arr"> The array to populate.  MUST BE SIZE 4 </param>
      float *ToARGB(float *_arr) const;

      /// <summary>
      /// fills the array (RGB) and returns it. Array must be of size 3
      /// </summary>
      /// <param name="_arr"> The array to populate.  MUST BE SIZE 3 </param>
      float *ToRGB(float * _arr) const;

      int ToIntRGB() const;

      Color operator+(const Color &other) const;
      Color operator-(const Color &other) const;
      Color operator*(const Color &other) const;

      Color &operator+=(const Color &other);
      Color &operator-=(const Color &other);
      Color &operator*=(const Color &other);

#if WIN32
      operator D2D_COLOR_F&();
      D2D_COLOR_F Col;
      operator const D2D_COLOR_F&() const;
#endif

      /// <summary>
      /// Creates a new Color object using a float[4] array in either RGBA or ARGB format
      /// </summary>
      /// <param name="_arr"> The array to populate with. MUST BE SIZE 4 </param>
      /// <param name="useARGB"> whether to use ARGB instead of RGBA </param>
      Color(float *_arr, bool useARGB = false);
      /// <summary>
      /// Creates a new Color object using the given r g b and a values
      /// </summary>
      Color(float r, float g, float b, float a = 1.0f);
      /// <summary>
      /// Creates a new Color object using the given r g b and a values
      /// </summary>
      Color(int r, int g, int b, int a = 255);
      /// <summary>
      /// Creates a new Color object using the given r g b and a values
      /// </summary>
      Color(unsigned int argb);
    };
  }
}
