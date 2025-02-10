#include "lorentz.hpp"
#include "constants.hpp"

std::complex<double> LorentzOscillator::compute_epsilon_at(double photonEnergy) const {

    std::complex<double> numerator = parameters.Amp * parameters.Br * parameters.En;
    std::complex<double> denominator = (parameters.En * parameters.En) - (photonEnergy * photonEnergy) - parameters.Br * photonEnergy * Constants::ImU;

    return numerator / denominator;
};

std::complex<double> LorentzImAmpOscillator::compute_epsilon_at(double photonEnergy) const {

    std::complex<double> numerator = (parameters.Amp + parameters.iAmp * Constants::ImU) * parameters.Br * parameters.En;
    std::complex<double> denominator = (parameters.En * parameters.En) - (photonEnergy * photonEnergy) - parameters.Br * photonEnergy * Constants::ImU;

    return numerator / denominator;
};
