#pragma once

#include "fmod.hpp"
#include "Spectrum.h"
#include <string>



namespace MistThread
{
  namespace Audio
  {
    enum SpectrumSize
    {
      SPECTRUM_64 = 64,
      SPECTRUM_128 = 128,
      SPECTRUM_256 = 256,
      SPECTRUM_512 = 512,
      SPECTRUM_1024 = 1024,
      SPECTRUM_2048 = 2048
    };

    class Sound
    {
    public:
      
      /// <summary>
      /// The constructor for the sound object, setting the channel to null.
      /// </summary>
      Sound();
      /// <summary>
      /// DESTRUCTION BRUH
      /// </summary>
      ~Sound();

      /// <summary>
      /// Loads the specified audio file into memory, also setting it as the active file for the
      /// current sound object.
      /// </summary>
      /// <param name="localPath">The path of the current audio file, name and extension included.</param>
      /// <returns>A reference to the current sound object.</returns>
      Sound& Load(const std::string &localPath);
      /// <summary>
      /// Streams a sound as opposed to loading it into the system. Great for one-off sounds or tests, but
      /// it is recommended that any sound used multiple times is loaded.
      /// </summary>
      /// <param name="localPath">The path of the current audio file, name and extension included.</param>
      /// <returns>Returns a reference to the current sound object.</returns>
      Sound& Stream(const std::string &localPath);
      /// <summary>
      /// Plays the specified audio file. If the sound has not been loaded into the game, the sound is
      /// added then played.
      /// </summary>
      /// <param name="localPath">The path of the current audio file, name and extension included.</param>
      /// <returns>Returns a reference to the current sound object.</returns>
      Sound& Play(const std::string &localPath);
      /// <summary>
      /// Loops a song instead of just playing it once.
      /// </summary>
      /// <param name="localPath">The path of the current audio file, name and extension included.</param>
      /// <returns>A reference to the current sound object.</returns>
      Sound& Loop(const std::string &localPath);

      /// <summary>
      /// Stops the current sound.
      /// </summary>
      void Stop();
      /// <summary>
      /// Toggle whether or not the sound is paused.
      /// </summary>
      void TogglePaused();
      /// <summary>
      /// Toggle whether or not the sound is muted. Muted sounds still play, just without volume.
      /// Previous volume attribute is retained.
      /// </summary>
      void ToggleMute();
      /// <summary>
      /// Gets whether or not the sound is playing.
      /// </summary>
      /// <returns>Whether or not the sound is playing.</returns>
      bool IsPlaying();

      /// <summary>
      /// Gets the current volume of the sound as a value between 0 and 1.
      /// </summary>
      /// <returns>The volume of a sound as a value between 0 and 1.</returns>
      float GetVolume() const;
      /// <summary>
      /// Gets whether or not the current channel is muted.
      /// </summary>
      /// <returns>Whether or not the current channel is muted.</returns>
      bool GetMute() const;
      /// <summary>
      /// Get whether or not the sound is paused.
      /// </summary>
      /// <returns>Returns whether or not the sound is paused.</returns>
      bool GetPaused() const;

      /// <summary>
      /// Sets whether or not the current sound is muted.
      /// </summary>
      /// <param name="isMuted">If the sound is to be muted or not.</param>
      void SetMute(const bool isMuted);
      /// <summary>
      /// Set the current volume of the sound to a value between 0 and 1.
      /// </summary>
      /// <param name="newVolume">The new volume the sound will play at.</param>
      void SetVolume(const float newVolume);
      /// <summary>
      /// Set whether or not the current sound is paused.
      /// </summary>
      /// <param name="isPaused">Whether or not the sound will be paused.</param>
      void SetPaused(const bool isPaused);
      /// <summary>
      /// Sets whether or not the sound is looping.
      /// </summary>
      /// <param name="isLooping">Whether or not the sound is looping.</param>
      void SetLooping(bool isLooping);
      
      //-- GetWaveData( ??? )
      Spectrum GetSpectrum(SpectrumSize s, FMOD_DSP_FFT_WINDOW window);

    private:
      FMOD::Channel *channel;

    };

    
  }
}

