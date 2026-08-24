#include "../../inc/simulator/simulator.hpp"

Vec3 compute_dipole_field(const Vec3& r_obs, const Vec3& r_dipole)
{
    Vec3 r_vec, r_mag, r_hat;

    r_vec = r_obs - r_dipole;

    r_mag = r_vec.magnitude();
    if (r_mag < 1e-12) {
        return zero_vec;
    }

}
