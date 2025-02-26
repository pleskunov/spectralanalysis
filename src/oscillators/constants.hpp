#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <complex>

namespace Constants {
  // Reduced Planck's constant, eV·s
  constexpr double HBAR = 6.582119569e-16;

  // Reduced Planck's constant, squared
  constexpr double HBAR2 = HBAR * HBAR;

  // Permittivity of free space (vacuum dielectric constant) in F·cm^-1
  constexpr double EPS0 = 8.854187818e-14;

  // Vacuum permittivity, F/m (SI units)
  constexpr double EPS0_SI = EPS0 * 1e2;

  // Elementary charge, C
  constexpr double Q = 1.602176634e-19;

  // Elementary charge, squared
  constexpr double Q2 = Q * Q;

  // Electron rest mass, kg
  constexpr double ME = 9.10938371e-31;

  // Speed of light in m/s
  constexpr double C = 299792458;

  // Planck's constant in eV·s
  constexpr double H = 4.135667697e-15;

  // Complex real unit
  constexpr std::complex<double> ReU = std::complex<double>(1.0, 0.0);

  // Complex imag unit
  constexpr std::complex<double> ImU = std::complex<double>(0.0, 1.0);

  // Square root of natural logarithm of 2.0
  constexpr double M_SQRT_LN2 = 0.8325546111576976;
}

#endif // CONSTANTS_HPP
