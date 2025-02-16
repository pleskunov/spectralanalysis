#include "gaussian.hpp"
#include "constants.hpp"
#include "../moremath/Dawson.hpp"

#include <cmath>

std::complex<double> GaussianOscillator::compute_epsilon_at(double photonEnergy) const {
  double sigma_n = parameters.Br / (2.0 * Constants::M_SQRT_LN2);

  double z_plus = (photonEnergy + parameters.En) / sigma_n;
  double z_minus = (photonEnergy - parameters.En) / sigma_n;

  double z_plus_s = z_plus * z_plus;
  double z_minus_s = z_minus * z_minus;

  /*  The real part of the dielectric function is approximated with 
      KK-consistent line shape produced by convergence series (Dawson integral)
  */
  double eps1 = dawson(z_minus) + dawson(z_plus);

  // Imaginary part of the dielectric function
  double eps2 = exp(-z_minus_s) - exp(-z_plus_s);

  // Complex dielectric function: note, we inverse e1 to mimick the CompleteEASE
  return parameters.Amp * (-eps1 + eps2 * Constants::ImU);
};
