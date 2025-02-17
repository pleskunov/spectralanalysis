#include "drude.hpp"
#include "constants.hpp"

#include <complex>

std::complex<double> Drude::OscillatorRT::compute_epsilon_at(double photonEnergy) const {
  double E2 = photonEnergy * photonEnergy;

  std::complex<double> numerator = -Constants::HBAR2 * Constants::ReU;
  std::complex<double> denominator = Constants::EPS0 * parameters.Rho * (parameters.Tau * E2 + Constants::HBAR * photonEnergy * Constants::ImU);

  return numerator / denominator;
};

std::complex<double> Drude::OscillatorNMu::compute_epsilon_at(double photonEnergy) const {
  double E2 = photonEnergy * photonEnergy;

  std::complex<double> numerator = -Constants::HBAR2 * Constants::Q2 * parameters.N * parameters.Mu * Constants::ReU;
  std::complex<double> denominator = Constants::EPS0_SI * (parameters.Mu * Constants::ME * parameters.mstar * E2 + Constants::HBAR * Constants::Q * photonEnergy * Constants::ImU);

  return numerator / denominator;
};
