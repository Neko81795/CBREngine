#include "Spectrum.h"



namespace MistThread
{
  namespace Audio
  {
    //Constructors
    Spectrum::Spectrum(const int size) : size_(size)
    {
      spectrum_ = new float[size];
    }
    Spectrum::Spectrum(const Spectrum &s)
    {
      spectrum_ = new float[s.size_];
      
      for (int i = 0; i < s.size_; ++i)
        spectrum_[i] = s.spectrum_[i];

      size_ = s.size_;
    }
    Spectrum::~Spectrum()
    {
      delete[] spectrum_;
    }

    //Operator Overloads
    SpectrumProxy Spectrum::operator[](int index)
    {
      if (index < 0 || index >= size_)
        throw("Accessing element out of range!");

      return SpectrumProxy(*this, index);
    }
    float Spectrum::operator[](const int& index) const
    {
      if (index < 0 || index >= size_)
        throw("Accessing element out of range!");

      return GetAt(index);
    }
    Spectrum& Spectrum::operator=(const Spectrum &s)
    {
      if (&s != this)
      {
        delete[] spectrum_;
        spectrum_ = new float[s.size_];

        for (int i = 0; i < s.size_; ++i)
          spectrum_[i] = s.spectrum_[i];

        size_ = s.size_;
      }
      return *this;
    }
    Spectrum::operator float*()
    {
      return spectrum_;
    }

    //Gets and Sets
    int Spectrum::GetSize() const
    {
      return size_;
    }
    float Spectrum::GetAt(int i) const
    {
      if (i < 0 || i >= size_)
        throw("Accessing element out of range!");

      return spectrum_[i];
    }
    void Spectrum::SetAt(int i, float value)
    {
      if (i < 0 || i >= size_)
        throw("Accessing element out of range!");

      spectrum_[i] = value;
    }
    void Spectrum::Scale(float scalar)
    {
      for (int i = 0; i < size_; ++i)
        spectrum_[i] *= scalar;
    }
  }
}

