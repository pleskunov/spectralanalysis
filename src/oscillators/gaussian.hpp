#ifndef GAUSSIAN_HPP
#define GAUSSIAN_HPP

#include "genosc.hpp"
#include "types.hpp"

class Parameters {
  public:
    double Amp;
    double En;
    double Br;

  Parameters(double Amp = 0.0, double En = 0.0, double Br = 0.0)
    : Amp(Amp),
      En(En),
      Br(Br) {}
};

class GaussianOscillator : public Oscillator {
  public:
    Parameters parameters;

  GaussianOscillator(const std::string& name, double Amp, double En, double Br) : Oscillator(name, GAUSSIAN), parameters(Amp, En, Br) {}

  std::complex<double>  compute_epsilon_at(double photonEnergy) const override;
};

#endif // GAUSSIAN_HPP
