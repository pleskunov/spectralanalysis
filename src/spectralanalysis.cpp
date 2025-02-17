#include <iostream>

#include "oscillators/lorentz.hpp"
#include "oscillators/harmonic.hpp"
#include "oscillators/drude.hpp"
#include "oscillators/gaussian.hpp"

//#include <iomanip>

int main() {

  Drude::OscillatorRT drudeRT("DrudeRT", 0.001, 5.0);
  Drude::OscillatorNMu drudeNMu("DrudeNmu", 1.0e20, 50.0, 0.260);

  Lorentz::OscillatorAmp lorentz("Lorentz", 10.0, 3.0, 0.10);
  Lorentz::OscillatorImAmp lorentzIm("LorentzImAmp", 10.0, 5.0, 3.0, 0.10);

  Harmonic::OscillatorAmp harmonic("Harmonic", 10.0, 3.0, 0.10);
  Harmonic::OscillatorImAmp harmonicIm("HarmonicIm", 10.0, 5.0, 3.0, 0.10);

  Gaussian::OscillatorAmp gauss("Gaussian", 10.0, 3.0, 0.10);

  std::vector<double> energies = {4.0, 3.02439, 2.0, 1.24};

  drudeRT.compute_permittivity(energies);
  drudeNMu.compute_permittivity(energies);
  lorentz.compute_permittivity(energies);
  lorentzIm.compute_permittivity(energies);
  harmonic.compute_permittivity(energies);
  harmonicIm.compute_permittivity(energies);

  gauss.compute_permittivity(energies);

  int i = 0;
  std::cout << "Energy (ev) e1 e2" << std::endl;
  for (const auto& eps : drudeRT.getPermittivity()) {
    std::cout << energies[i] << " " << eps << std::endl;
    i++;
  }

  std::cout << std::endl;
  i = 0;
  std::cout << "Energy (ev) e1 e2" << std::endl;
  for (const auto& eps : drudeNMu.getPermittivity()) {
    std::cout << energies[i] << " " << eps << std::endl;
    i++;
  }

  std::cout << std::endl;
  i = 0;
  std::cout << "Energy (ev) e1 e2" << std::endl;
  for (const auto& eps : lorentz.getPermittivity()) {
    std::cout << energies[i] << " " << eps << std::endl;
    i++;
  }

  std::cout << std::endl;
  i = 0;
  std::cout << "Energy (ev) e1 e2" << std::endl;
  for (const auto& eps : lorentzIm.getPermittivity()) {
    std::cout << energies[i] << " " << eps << std::endl;
    i++;
  }

  std::cout << std::endl;
  i = 0;
  std::cout << "Energy (ev) e1 e2" << std::endl;
  for (const auto& eps : harmonic.getPermittivity()) {
    std::cout << energies[i] << " " << eps << std::endl;
    i++;
  }

  // TODO: check
  //std::cout << std::endl;
  //i = 0;
  //std::cout << "Energy (ev) e1 e2" << std::endl;
  //for (const auto& eps : harmonicIm.getPermittivity()) {
  //  std::cout << energies[i] << " " << eps << std::endl;
  //  i++;
  //}

  //std::cout << std::endl;
  //i = 0;
  //std::cout << "Energy (ev) e1 e2" << std::endl;
  //for (const auto& eps : gauss.getPermittivity()) {
  //  std::cout << energies[i] << " " << eps << std::endl;
  //  i++;
  //}
  //std::cout << "Drude type: " << drudeRT.getType() << std::endl;

  return 0;
}
