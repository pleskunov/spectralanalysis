#include "Dawson.hpp"
#include "Faddeeva.hpp"

#include <array>
#include <cstdlib>
#include <cmath>

static double dwsn(const double x) {
  static const int MAX_TERMS = 12;
  static bool      is_initialized = true;

  static constexpr double STEP_SIZE = 0.4;
  static constexpr double TAYLOR_COEF_1 = 2.0 / 3.0;
  static constexpr double TAYLOR_COEF_2 = 0.4;
  static constexpr double TAYLOR_COEF_3 = 2.0 / 7.0;
  static constexpr double TAYLOR_COEF_4 = 2.0 / 9.0;
  static constexpr double C0 = 0.5641895835;

  // Initialize the precomputed exponentials
  static std::array<double, MAX_TERMS> precomputed_exp = {};
  if (is_initialized) {
    is_initialized = false;
    for (int i = 0; i < MAX_TERMS; i++) {
      double temp = (2.0 * i + 1.0) * STEP_SIZE;
      precomputed_exp[i] = exp(-temp * temp);
    }
  }

  double result;

  if (std::abs(x) < 0.2) {
    double x_squared = x * x;
    result = x * (1.0 - TAYLOR_COEF_1 * x_squared * (1.0 - TAYLOR_COEF_2 * x_squared * (1.0 - TAYLOR_COEF_3 * x_squared * (1.0 - TAYLOR_COEF_4 * x_squared))));
  } else {
    double abs_x          = std::abs(x);
    int nearest_grid_idx  = 2 * static_cast<int>(0.5 * abs_x / STEP_SIZE + 0.5);
    double x_offset       = abs_x - nearest_grid_idx * STEP_SIZE;

    double exp_factor     = exp(2.0 * x_offset * STEP_SIZE);
    double exp_factor_sq  = exp_factor * exp_factor;

    double denom_forward  = nearest_grid_idx + 1;
    double denom_backward = denom_forward - 2.0;

    double sum = 0.0;
    for (int i = 0; i < MAX_TERMS; i++, denom_forward += 2.0, denom_backward -= 2.0, exp_factor *= exp_factor_sq) {
      sum += precomputed_exp[i] * (exp_factor / denom_forward + 1.0 / (denom_backward * exp_factor));
    }

    result = C0 * std::copysign(exp(-x_offset * x_offset) * sum, x);
  }

  return result;
}

static double dwsn2(const double x) {
  return Faddeeva::Dawson(x);
};

double dawson(const double x) {
  return dwsn2(x);
}
