#include "drude.hpp"
#include "constants.hpp"

std::vector<std::complex<double>> DrudeOscillatorRT::compute_permittivity(const std::vector<double>& photonEnergies) const {

  std::vector<std::complex<double>> epsilon(photonEnergies.size());

  // Compute permittivity for each photon energy
  for (size_t i = 0; i < photonEnergies.size(); ++i) {
    double energy = photonEnergies[i];

    std::complex<double> numerator = -(Constants::HBAR * Constants::HBAR) * Constants::ReU;
    std::complex<double> denominator = Constants::EPS0 * parameters.Rho * (parameters.Tau * (energy * energy + 1e-12) + Constants::HBAR * energy * Constants::ImU);

    epsilon[i] = numerator / denominator;
  }

  return epsilon;
};

std::vector<std::complex<double>> DrudeOscillatorNMu::compute_permittivity(const std::vector<double>& photonEnergies) const {

  std::vector<std::complex<double>> epsilon(photonEnergies.size());

  for (size_t i = 0; i < photonEnergies.size(); ++i) {
    double energy = photonEnergies[i];

    std::complex<double> numerator = -(Constants::HBAR * Constants::HBAR) * (Constants::Q * Constants::Q) * parameters.N * parameters.Mu * Constants::ReU;
    std::complex<double> denominator = Constants::EPS0_SI * (parameters.Mu * Constants::ME * parameters.m * (energy * energy) + Constants::HBAR * Constants::Q * energy * Constants::ImU);

    epsilon[i] = numerator / denominator;
  }

  return epsilon;
};
