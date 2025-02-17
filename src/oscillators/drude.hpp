#ifndef DRUDE_HPP
#define DRUDE_HPP

#include "genosc.hpp"
#include "types.hpp"

namespace Drude {
  class Parameters {
    public:
      double Rho;
      double Tau;
      double N;
      double Mu;
      double mstar;

      Parameters(double rho, double tau, double N, double mu, double mstar) 
        : Rho(rho),            // Ohm/cm
          Tau(tau * 1.0e-15),  // Convert femtoseconds to seconds
          N(N * 1.0e6),        // Convert cm^-3 to m^-3
          Mu(mu * 1.0e-4),     // Convert cm^2/V·s to m^2/V·s
          mstar(mstar) {}      // Unitless
  };

  class OscillatorRT : public Oscillator {
    public:
      Parameters parameters;

      OscillatorRT(const std::string& name, double rho, double tau) : Oscillator(name, DRUDE_RT), parameters(rho, tau, 0.0, 0.0, 0.0) {}

      std::complex<double> compute_epsilon_at(double photonEnergy) const override;
  };

  class OscillatorNMu : public Oscillator {
    public:
      Parameters parameters;

      OscillatorNMu(const std::string& name, double N, double mu, double mstar) : Oscillator(name, DRUDE_NMU), parameters(0.0, 0.0, N, mu, mstar) {}

      std::complex<double> compute_epsilon_at(double photonEnergy) const override;
  };
} // namespace Drude

#endif // !DRUDE_HPP
