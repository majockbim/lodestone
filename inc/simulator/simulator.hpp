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

    Vec3 operator-(const Vec3& dipole) const {
        return Vec3{x - dipole.x, y - dipole.y, z - dipole.z};
    }
};
