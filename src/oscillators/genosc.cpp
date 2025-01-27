#include "genosc.hpp"

std::vector<std::complex<double>> Oscillator::compute_permittivity(const std::vector<double>& photonEnergy) const {
  throw std::logic_error("This method should be implemented by subclasses");
}

const std::string& Oscillator::getName() const {
  return name;
}

const std::string& Oscillator::getMaterial() const {
  return material;
}

void Oscillator::setMaterial(const std::string& mat) {
  material = mat;
}

OscillatorTypes Oscillator::getType() const {
  return type;
}

void Oscillator::setType(const OscillatorTypes oscillatorType) {
  type = oscillatorType;
}
