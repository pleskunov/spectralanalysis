#include "harmonic.hpp"
#include "constants.hpp"

#include <complex>

std::complex<double> HarmonicOscillator::compute_epsilon_at(double photonEnergy) const {
  static double prefactor = (parameters.Amp * parameters.Br) / 2.0;

  static std::complex<double> t1 = 1.0 / (parameters.En - photonEnergy - 0.5 * parameters.Br * Constants::ImU);
  static std::complex<double> t2 = 1.0 / (parameters.En + photonEnergy - 0.5 * parameters.Br * Constants::ImU);

  return (prefactor * Constants::ReU) * (t1 + t2);
}


std::complex<double> HarmonicImAmpOscillator::compute_epsilon_at(double photonEnergy) const {
  static std::complex<double> prefactor = ((parameters.Amp + parameters.iAmp * Constants::ImU) * parameters.Br) / 2.0;

  static std::complex<double> t1 = 1.0 / (parameters.En - photonEnergy - 0.5 * parameters.Br * Constants::ImU);
  static std::complex<double> t2 = 1.0 / (parameters.En + photonEnergy - 0.5 * parameters.Br * Constants::ImU);

  return prefactor * (t1 + t2);
}
