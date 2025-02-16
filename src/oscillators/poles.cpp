#include "poles.hpp"
#include "constants.hpp"

std::complex<double> IR_PoleOscillator::compute_epsilon_at(double photonEnergy) const {
  return (parameters.Amp / ((parameters.En * parameters.En) - (photonEnergy * photonEnergy))) * Constants::ReU;
}

std::complex<double> UV_PoleOscillator::compute_epsilon_at(double photonEnergy) const {
  return (-parameters.Amp / (photonEnergy * photonEnergy)) * Constants::ReU;
}
