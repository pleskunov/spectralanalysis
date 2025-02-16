#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "oscillators/genosc.hpp"

#include <iostream>
#include <vector>
#include <complex>
#include <string>

class Material {
  public:
    std::string                       name;
    double                            thickness;
    unsigned int                      position;
    double                            epsilon_inf;
    std::vector<Oscillator>           poles;
    std::vector<Oscillator>           oscillators;

    unsigned int                      num_of_oscillators;
    std::vector<std::complex<double>> permittivity;

    Material(const std::string& name, const double thickness, const unsigned int position, 
             const double epsilon_inf, const std::vector<Oscillator>& poles, 
             const std::vector<Oscillator>& oscillators)
        : name(name), 
          thickness(thickness), 
          position(position), 
          epsilon_inf(epsilon_inf), 
          poles(poles), 
          oscillators(oscillators),
          num_of_oscillators(static_cast<unsigned int>(oscillators.size())) // Compute oscillator count
    {}

    ~Material() {
      // TODO: implement
      std::cout << "Destroying Material: " << name << std::endl;

    }
};

#endif // !MATERIAL_HPP
