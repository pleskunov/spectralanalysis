#include "lorentz.hpp"
#include "constants.hpp"

std::vector<std::complex<double>> LorentzOscillator::compute_permittivity(const std::vector<double>& photonEnergies) const {

  std::vector<std::complex<double>> epsilon;
  epsilon.reserve(photonEnergies.size());

  for (const auto& energy : photonEnergies) {

    std::complex<double> numerator = parameters.Amp * parameters.Br * parameters.En;
    std::complex<double> denominator = (parameters.En * parameters.En) - (energy * energy) - parameters.Br * energy * Constants::ImU;

    epsilon.push_back(numerator / denominator);
  }

  return epsilon;
};

std::vector<std::complex<double>> LorentzImAmpOscillator::compute_permittivity(const std::vector<double>& photonEnergies) const {

  std::vector<std::complex<double>> epsilon;
  epsilon.reserve(photonEnergies.size());

  for (const auto& energy : photonEnergies) {

    std::complex<double> numerator = (parameters.Amp + parameters.iAmp * Constants::ImU) * parameters.Br * parameters.En;
    std::complex<double> denominator = (parameters.En * parameters.En) - (energy * energy) - parameters.Br * energy * Constants::ImU;

    epsilon.push_back(numerator / denominator);
  }

  return epsilon;
};
