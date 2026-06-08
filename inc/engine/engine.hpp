#pragma once

#include "../main.hpp"

#include <chrono>
#include <thread>
#include <cmath>

#define PI 3.14159265358979323846

class Vec3 {
public:
    Vec3(const Vec3&) = delete;
    Vec3& operator=(const Vec3&) = delete;

    Vec3(Vec3&&) = delete;
    Vec3& operator=(Vec3&&) = delete;

    static Vec3& get();

private:
    Vec3() {}
    ~Vec3();
};
