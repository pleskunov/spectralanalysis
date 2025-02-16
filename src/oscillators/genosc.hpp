#ifndef GENOSC_HPP
#define GENOSC_HPP

#include <complex>
#include <vector>

#include "types.hpp"

class Oscillator {
  protected:
    std::string                       name;
    std::vector<std::complex<double>> permittivity;
    OscillatorTypes                   type;

  public:
    // Constructor
    Oscillator(const std::string& oscillatorName, OscillatorTypes oscillatorType = GENERIC) 
      : name(oscillatorName), permittivity(), type(oscillatorType) {}

    // Destructor
    virtual ~Oscillator() = default;

    // Interface
    virtual std::complex<double>      compute_epsilon_at(double photonEnergy) const;
    int                               compute_permittivity(const std::vector<double>& photonEnergies);
    const std::string&                getName(void) const;
    OscillatorTypes                   getType(void) const;
    void                              setType(const OscillatorTypes oscillatorType);
    std::vector<std::complex<double>> getPermittivity(void) const;
};

#endif // GENOSC_HPP
