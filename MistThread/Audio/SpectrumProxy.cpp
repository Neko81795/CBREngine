#include "Spectrum.h"



namespace MistThread
{
  namespace Audio
  {
    //Spectrum Proxy member functions
    SpectrumProxy::SpectrumProxy(Spectrum &s, int pos) : s_(s), pos_(pos) { }
    SpectrumProxy::operator float()
    {
      return s_.GetAt(pos_);
    }

    //Spectrum Proxy Operator Overloads.
    SpectrumProxy& SpectrumProxy::operator=(const SpectrumProxy &s)
    {
      if (&s != this)
      {
        s_[pos_] = s.s_[s.pos_];
      }
      return *this;
    }
    SpectrumProxy& SpectrumProxy::operator+=(const SpectrumProxy &s)
    {
      s_.SetAt(pos_, static_cast<float>(s_[pos_] + s.s_[s.pos_]));
      return *this;
    }
    SpectrumProxy& SpectrumProxy::operator-=(const SpectrumProxy &s)
    {
      s_.SetAt(pos_, static_cast<float>(s_[pos_] - s.s_[s.pos_]));
      return *this;
    }
    SpectrumProxy& SpectrumProxy::operator*=(const SpectrumProxy &s)
    {
      s_.SetAt(pos_, static_cast<float>(s_[pos_] * s.s_[s.pos_]));
      return *this;
    }
    SpectrumProxy& SpectrumProxy::operator/=(const SpectrumProxy &s)
    {
      s_.SetAt(pos_, static_cast<float>(s_[pos_] / s.s_[s.pos_]));
      return *this;
    }
    SpectrumProxy& SpectrumProxy::operator=(int i)
    {
      s_.SetAt(pos_, static_cast<float>(i));
      return *this;
    }
    SpectrumProxy& SpectrumProxy::operator+=(int i)
    {
      s_.SetAt(pos_, s_.GetAt(pos_) + i);
      return *this;
    }
    SpectrumProxy& SpectrumProxy::operator-=(int i)
    {
      s_.SetAt(pos_, s_.GetAt(pos_) - i);
      return *this;
    }
    SpectrumProxy& SpectrumProxy::operator*=(int i)
    {
      s_.SetAt(pos_, s_.GetAt(pos_) * i);
      return *this;
    }
    SpectrumProxy& SpectrumProxy::operator/=(int i)
    {
      s_.SetAt(pos_, s_.GetAt(pos_) / i);
      return *this;
    }
  }
}
