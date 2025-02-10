#include "genosc.hpp"

std::complex<double> Oscillator::compute_epsilon_at(double photonEnergy) const {
  throw std::logic_error("This method should be implemented by subclasses");
}

int Oscillator::compute_permittivity(const std::vector<double>& photonEnergies) {

  if (photonEnergies.empty()) {
    return 1;
  };

  size_t e_size = photonEnergies.size();

  permittivity.resize(e_size);

  for (size_t i = 0; i < e_size; ++i) {
    permittivity[i] = compute_epsilon_at(photonEnergies[i]);
  }

  return 0;
}

const std::string& Oscillator::getName() const {
  return name;
}

OscillatorTypes Oscillator::getType() const {
  return type;
}

void Oscillator::setType(const OscillatorTypes oscillatorType) {
  type = oscillatorType;
}

std::vector<std::complex<double>> Oscillator::getPermittivity() const {
  return permittivity;
}
