#ifndef DRUDE_HPP
#define DRUDE_HPP

#include "genosc.hpp"
#include "types.hpp"

class Parameters {
  public:
    double Rho;
    double Tau;
    double N;
    double Mu;
    double m;

    Parameters(double rho = 0.0, double tau = 0.0, double N = 0.0, double mu = 0.0, double m = 0.0) 
      : Rho(rho),
        Tau(tau * 1e-15),  // Convert femtoseconds to seconds
        N(N * 1e6),        // Convert cm^-3 to m^-3
        Mu(mu * 1e-4),     // Convert cm^2/V·s to m^2/V·s
        m(m) {}
};

class DrudeOscillatorRT : public Oscillator {
  public:
    Parameters parameters;

    DrudeOscillatorRT(const std::string& name, double rho, double tau) : Oscillator(name, DRUDE_RT), parameters(rho, tau) {}

    std::vector<std::complex<double>> compute_permittivity(const std::vector<double>& photonEnergies) const override;
};

class DrudeOscillatorNMu : public Oscillator {
  public:
    Parameters parameters;

    DrudeOscillatorNMu(const std::string& name, double N, double mu, double m) : Oscillator(name, DRUDE_NMU), parameters(0.0, 0.0, N, mu, m) {}

    std::vector<std::complex<double>> compute_permittivity(const std::vector<double>& photonEnergies) const override;
};

#endif // DRUDE_HPP
