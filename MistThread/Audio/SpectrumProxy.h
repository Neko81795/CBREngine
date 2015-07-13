#pragma once

#include "Spectrum.h"


namespace MistThread
{
  namespace Audio
  {
    class SpectrumProxy
    {
  public:
    //Constructor
    SpectrumProxy(Spectrum &s, int pos);

    //Operator Overloads!
    operator float();
    SpectrumProxy& operator=(const SpectrumProxy &s);
    SpectrumProxy& operator+=(const SpectrumProxy &s);
    SpectrumProxy& operator-=(const SpectrumProxy &s);
    SpectrumProxy& operator*=(const SpectrumProxy &s);
    SpectrumProxy& operator/=(const SpectrumProxy &s);
    SpectrumProxy& operator=(int i);
    SpectrumProxy& operator+=(int i);
    SpectrumProxy& operator-=(int i);
    SpectrumProxy& operator*=(int i);
    SpectrumProxy& operator/=(int i);

  private:
    Spectrum &s_; //A reference to the spectrum object we are a proxy of.
    int pos_;     //The index we represent.
    };
  }
}


