#include "harmonic.hpp"
#include "constants.hpp"

#include <complex>

std::complex<double> Harmonic::OscillatorAmp::compute_epsilon_at(double photonEnergy) const {
  double prefactor = (parameters.Amp * parameters.Br) / 2.0;

  std::complex<double> t1 = 1.0 / (parameters.En - photonEnergy - 0.5 * parameters.Br * Constants::ImU);
  std::complex<double> t2 = 1.0 / (parameters.En + photonEnergy - 0.5 * parameters.Br * Constants::ImU);

  return prefactor * (t1 + t2);
}

std::complex<double> Harmonic::OscillatorImAmp::compute_epsilon_at(double photonEnergy) const {
  std::complex<double> prefactor = ((parameters.Amp + parameters.iAmp * Constants::ImU) * parameters.Br) / 2.0;

  std::complex<double> t1 = 1.0 / (parameters.En - photonEnergy - 0.5 * parameters.Br * Constants::ImU);
  std::complex<double> t2 = 1.0 / (parameters.En + photonEnergy - 0.5 * parameters.Br * Constants::ImU);

  return prefactor * (t1 + t2);
}
