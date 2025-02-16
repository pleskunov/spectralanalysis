#ifndef POLES_HPP
#define POLES_HPP

#include "genosc.hpp"
#include "types.hpp"

class Parameters {
  public:
    double Amp;
    double En;

  Parameters(double Amp = 0.0, double En = 0.0)
    : Amp(Amp),
      En(En) {}
};

class IR_PoleOscillator : public Oscillator {
  public:
    Parameters parameters;

    IR_PoleOscillator(const std::string& name, double Amp, double En) : Oscillator(name, IR_POLE), parameters(Amp, En) {}

    std::complex<double> compute_epsilon_at(double photonEnergy) const override;
};

class UV_PoleOscillator : public Oscillator {
  public:
    Parameters parameters;

    UV_PoleOscillator(const std::string& name, double Amp, double En) : Oscillator(name, UV_POLE), parameters(Amp, En) {}

    std::complex<double> compute_epsilon_at(double photonEnergy) const override;
};

#endif // !POLES_HPP
