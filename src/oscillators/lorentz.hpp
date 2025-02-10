#ifndef LORENTZ_HPP
#define LORENTZ_HPP

#include "genosc.hpp"
#include "types.hpp"

class Parameters {
  public:
    double Amp;
    double iAmp;
    double En;
    double Br;

  Parameters(double Amp = 0.0, double iAmp = 0.0, double En = 0.0, double Br = 0.0)
    : Amp(Amp),
      iAmp(iAmp),
      En(En),
      Br(Br) {}
};

/**
 * @class LorentzOscillator
 * @brief The classic Lorentz oscillator model.
 *
 * This class models the classic Lorentz oscillator, which is commonly used in 
 * optical modeling to describe resonances in the dielectric function.
 *
 * @details
 * The model is defined by the following parameters:
 * - **Amp**: The unitless amplitude of the oscillator. It approximately equals e^2 at its peak value.
 * - **Br**: The broadening of the oscillator in eV. It approximates the full width at half-maximum (FWHM).
 * - **En**: The center energy (resonance energy) of the oscillator in eV.
 *
 * **Note:**
 * - The maximum position shifts to lower energies compared to the center energy @c En as broadening @c Br increases.
 */
class LorentzOscillator : public Oscillator {
  public:
    Parameters parameters;

    LorentzOscillator(const std::string& name, double Amp, double En, double Br) : Oscillator(name, LORENTZ), parameters(Amp, 0.0, En, Br) {}

    std::complex<double> compute_epsilon_at(double photonEnergy) const override;
};

class LorentzImAmpOscillator : public Oscillator {
  public:
    Parameters parameters;

    LorentzImAmpOscillator(const std::string& name, double Amp, double iAmp, double En, double Br) : Oscillator(name, LORENTZ_IMAMP), parameters(Amp, iAmp, En, Br) {}

    std::complex<double> compute_epsilon_at(double photonEnergy) const override;
};

#endif // !LORENTZ_HPP
