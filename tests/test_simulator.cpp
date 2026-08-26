#include <gtest/gtest.h>
#include "simulator/simulator.hpp"

// TEST 1: Field direction matches dipole axis for on-axis point
TEST(SimulatorTest, OnAxisDirection) {
    Vec3 dipole_pos = {0.0, 0.0, 0.0};
    Vec3 m = {0.0, 0.0, 1.0}; // Magnet pointing UP (+Z)
    Vec3 obs_pos = {0.0, 0.0, 2.0}; // Observation point directly above it

    Vec3 B = compute_dipole_field(obs_pos, dipole_pos, m);

    // X and Y should be 0
    EXPECT_NEAR(B.x, 0.0, 1e-15);
    EXPECT_NEAR(B.y, 0.0, 1e-15);
    
    // Z should be a positive number
    EXPECT_GT(B.z, 0.0); 
}

// TEST 2: B magnitude falls off as 1/r³
TEST(SimulatorTest, MagnitudeFalloff) {
    Vec3 dipole_pos = {0.0, 0.0, 0.0};
    Vec3 m = {0.0, 0.0, 1.0};
    
    // Measure at distance = 2
    Vec3 B_close = compute_dipole_field({0.0, 2.0, 0.0}, dipole_pos, m);
    // Measure at distance = 4 (twice as far)
    Vec3 B_far = compute_dipole_field({0.0, 4.0, 0.0}, dipole_pos, m);
    
    double mag_close = B_close.magnitude();
    double mag_far = B_far.magnitude();
    
    // The far magnitude should be exactly 1/8th of the close magnitude
    EXPECT_NEAR(mag_far, mag_close / 8.0, 1e-15);
}

// TEST 3: Superposition holds for two dipoles
TEST(SimulatorTest, Superposition) {
    Vec3 obs_pos = {2.0, 3.0, 4.0}; // Arbitrary observation point
    Vec3 dipole_pos = {0.0, 0.0, 0.0};
    
    Vec3 m1 = {1.0, 0.0, 0.0}; // Dipole 1
    Vec3 m2 = {0.0, 1.0, 0.0}; // Dipole 2
    Vec3 m_combined = {1.0, 1.0, 0.0}; // Combining them: m1 + m2
    
    // Calculate fields individually
    Vec3 B1 = compute_dipole_field(obs_pos, dipole_pos, m1);
    Vec3 B2 = compute_dipole_field(obs_pos, dipole_pos, m2);
    
    // Calculate field together
    Vec3 B_combined = compute_dipole_field(obs_pos, dipole_pos, m_combined);
    
    // Verify that B(m1+m2) == B(m1) + B(m2)
    EXPECT_NEAR(B_combined.x, B1.x + B2.x, 1e-15);
    EXPECT_NEAR(B_combined.y, B1.y + B2.y, 1e-15);
    EXPECT_NEAR(B_combined.z, B1.z + B2.z, 1e-15);
}
