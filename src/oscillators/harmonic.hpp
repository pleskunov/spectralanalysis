#ifndef HARMONIC_HPP
#define HARMONIC_HPP

#include "genosc.hpp"
#include "types.hpp"

namespace Harmonic {
  class Parameters {
    public:
      double Amp;
      double iAmp;
      double En;
      double Br;

    Parameters(double Amp = 0.0, double iAmp = 0.0, double En = 0.0, double Br = 0.0)
      : Amp(Amp),
        iAmp(iAmp),
        En(En),
        Br(Br) {}
  };

  class OscillatorAmp : public Oscillator {
    public:
      Parameters parameters;

      OscillatorAmp(const std::string& name, double Amp, double En, double Br) : Oscillator(name, HARMONIC), parameters(Amp, 0.0, En, Br) {}

      std::complex<double> compute_epsilon_at(double photonEnergy) const override;
  };

  class OscillatorImAmp : public Oscillator {
    public:
      Parameters parameters;

      OscillatorImAmp(const std::string& name, double Amp, double iAmp, double En, double Br) : Oscillator(name, HARMONIC_IMAMP), parameters(Amp, iAmp, En, Br) {}

      std::complex<double> compute_epsilon_at(double photonEnergy) const override;
  };
} // namespace Harmonic

#endif // !HARMONIC_HPP
