#include <iostream>

#include "oscillators/drude.hpp"

int main() {
    DrudeOscillatorRT drude("Drude Oscillator", 1.0, 2.0);
    Oscillator genericOscillator("Generic Oscillator", GENERIC);

    std::vector<double> energies = {1.0, 2.0, 3.0};

    int status = drude.compute_permittivity(energies);

    for (const auto& eps : drude.getPermittivity()) {
      std::cout << eps << std::endl;
    }

    std::cout << "Drude type: " << drude.getType() << std::endl;
    std::cout << "Generic type: " << genericOscillator.getType() << std::endl;

    return 0;
}
