#pragma once

#include "../main.hpp"

#include <chrono>
#include <thread>
#include <cmath>

#define PI 3.14159265358979323846
#define M0_OVER_4PI 1e-7

struct Vec3 {
    double x;
    double y;
    double z;

    Vec3 operator-(const Vec3& vec) const {
        return Vec3{x - vec.x, y - vec.y, z - vec.z};
    }

    Vec3 operator/(double scalar) const {
        return Vec3{x / scalar, y / scalar, z / scalar}; 
    }

    double magnitude() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    Vec3 operator*(double k) const {
        return Vec3{x * k, y * k, z * k};
    }

    double dot(const Vec3& vec) const {
        return double{x * vec.x +
                      y * vec.y +
                      z * vec.z
        };
    }
};

Vec3 compute_dipole_field(const Vec3& r_obs, const Vec3& r_dipole, const Vec3& m);

inline constexpr Vec3 zero_vec{0.0, 0.0, 0.0};

// allows for x * vec, since other func supports only vec * x
inline Vec3 operator*(double scalar, const Vec3& vec) {
    return vec * scalar;
}
