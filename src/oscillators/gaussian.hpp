#ifndef GAUSSIAN_HPP
#define GAUSSIAN_HPP

#include "genosc.hpp"
#include "types.hpp"

namespace Gaussian {
  class Parameters {
    public:
      double Amp;
      double En;
      double Br;

    Parameters(double Amp, double En, double Br)
      : Amp(Amp),
        En(En),
        Br(Br) {}
  };

  class OscillatorAmp : public Oscillator {
    public:
      Parameters parameters;

      OscillatorAmp(const std::string& name, double Amp, double En, double Br) : Oscillator(name, GAUSSIAN), parameters(Amp, En, Br) {}

      std::complex<double>  compute_epsilon_at(double photonEnergy) const override;
  };
} // namespace Gaussian

#endif // GAUSSIAN_HPP
