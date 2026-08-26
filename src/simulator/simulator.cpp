#include "../../inc/simulator/simulator.hpp"

Vec3 compute_dipole_field(const Vec3& r_obs, const Vec3& r_dipole, const Vec3& m)
{
    Vec3 r_vec, r_hat, third_term;
    double r_mag, first_term, second_term;

    r_vec = r_obs - r_dipole;

    r_mag = r_vec.magnitude();
    if (r_mag < 1e-12) {
        return zero_vec;
    }

    r_hat = r_vec / r_mag;

    // μ₀/4π
    first_term = M0_OVER_4PI;
    
    // 1/r³
    second_term = 1 / std::pow(r_mag, 3);
    
    // 3(m·r̂)r̂ - m
    third_term = 3 * (m.dot(r_hat)) * r_hat - m;

    return (first_term * second_term) * third_term;

}
