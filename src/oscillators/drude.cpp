#include "drude.hpp"
#include "constants.hpp"

std::complex<double> DrudeOscillatorRT::compute_epsilon_at(double photonEnergy) const {
  std::complex<double> numerator = -(Constants::HBAR * Constants::HBAR) * Constants::ReU;
  std::complex<double> denominator = Constants::EPS0 * parameters.Rho * (parameters.Tau * (photonEnergy * photonEnergy + 1e-12) + Constants::HBAR * photonEnergy * Constants::ImU);

  return numerator / denominator;
};

std::complex<double> DrudeOscillatorNMu::compute_epsilon_at(double photonEnergy) const {
  std::complex<double> numerator = -(Constants::HBAR * Constants::HBAR) * (Constants::Q * Constants::Q) * parameters.N * parameters.Mu * Constants::ReU;
  std::complex<double> denominator = Constants::EPS0_SI * (parameters.Mu * Constants::ME * parameters.m * (photonEnergy * photonEnergy) + Constants::HBAR * Constants::Q * photonEnergy * Constants::ImU);

  return numerator / denominator;
};
