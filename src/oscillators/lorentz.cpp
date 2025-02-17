#include "lorentz.hpp"
#include "constants.hpp"

std::complex<double> Lorentz::OscillatorAmp::compute_epsilon_at(double photonEnergy) const {
  double E2 = photonEnergy * photonEnergy;

  std::complex<double> numerator = (parameters.Amp * parameters.Br * parameters.En) * Constants::ReU;
  std::complex<double> denominator = (parameters.En * parameters.En) - E2 - parameters.Br * photonEnergy * Constants::ImU;

  return numerator / denominator;
};

std::complex<double> Lorentz::OscillatorImAmp::compute_epsilon_at(double photonEnergy) const {
  double E2 = photonEnergy * photonEnergy;

  std::complex<double> numerator = (parameters.Amp + parameters.iAmp * Constants::ImU) * parameters.Br * parameters.En;
  std::complex<double> denominator = (parameters.En * parameters.En) - E2 - parameters.Br * photonEnergy * Constants::ImU;

  return numerator / denominator;
};
