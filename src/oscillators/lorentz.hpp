#ifndef LORENTZ_HPP
#define LORENTZ_HPP

#include "genosc.hpp"
#include "types.hpp"

namespace Lorentz {
  class Parameters {
    public:
      double Amp;
      double iAmp;
      double En;
      double Br;

    Parameters(double Amp, double iAmp, double En, double Br)
      : Amp(Amp),
        iAmp(iAmp),
        En(En),
        Br(Br) {}
  };

  class OscillatorAmp : public Oscillator {
    public:
      Parameters parameters;

      OscillatorAmp(const std::string& name, double Amp, double En, double Br) : Oscillator(name, LORENTZ), parameters(Amp, 0.0, En, Br) {}

      std::complex<double> compute_epsilon_at(double photonEnergy) const override;
  };

  class OscillatorImAmp : public Oscillator {
    public:
      Parameters parameters;

      OscillatorImAmp(const std::string& name, double Amp, double iAmp, double En, double Br) : Oscillator(name, LORENTZ_IMAMP), parameters(Amp, iAmp, En, Br) {}

      std::complex<double> compute_epsilon_at(double photonEnergy) const override;
  };
} // namespace Lorentz

#endif // !LORENTZ_HPP
