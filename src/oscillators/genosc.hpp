#ifndef GENOSC_HPP
#define GENOSC_HPP

#include <complex>
#include <vector>

#include "types.hpp"

class Oscillator {
  protected:
    std::string           name;
    std::complex<double>  permittivity;
    std::string           material;
    OscillatorTypes       type;

  public:
    // Constructor
    Oscillator(const std::string& oscillatorName, OscillatorTypes oscillatorType = GENERIC) 
      : name(oscillatorName), permittivity(0.0, 0.0), material(""), type(oscillatorType) {}

    // Destructor
    virtual ~Oscillator() = default;

    virtual std::vector<std::complex<double>>     compute_permittivity(const std::vector<double>& photonEnergy) const;
    const std::string&                            getName() const;
    const std::string&                            getMaterial() const;
    void                                          setMaterial(const std::string& mat);
    OscillatorTypes                               getType() const;
    void                                          setType(const OscillatorTypes oscillatorType);
};

#endif // GENOSC_HPP
