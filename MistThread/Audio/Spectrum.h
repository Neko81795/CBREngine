#pragma once



namespace MistThread
{
  namespace Audio
  {
    class SpectrumProxy;
    class Spectrum
    {
    public:
      //Constructor and Destructor
      Spectrum(const int size);
      Spectrum(const Spectrum &s);
      ~Spectrum();

      //Operator Overloads
      SpectrumProxy operator[](int index);
      float Spectrum::operator[](const int& index) const;
      Spectrum& operator=(const Spectrum &s);
      operator float*();

      //Member Functions
      int GetSize() const;
      void Scale(float scalar);
      float GetAt(int i) const;
      void SetAt(int i, float value);
      //TODO: Implement an update function to make it much more efficient. Add some more variables to make this work, like FMOD_WINDOW enum and a channel ref.

    private:
      float *spectrum_; //The managed pointer to the spectrum.
      int size_;        //The size of the spectrum.
    };

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

