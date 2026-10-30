#include <Eigen/Core>
#include <cmath>
#include <iostream>

int main() {
    const Eigen::Vector3d a(3.0, 4.0, 0.0);
    const Eigen::Vector3d b(1.0, 2.0, 3.0);

    // Store the result as a concrete vector rather than a lazy expression.
    const Eigen::Vector3d sum = a + b;
    const double dot = a.dot(b);
    const double length = a.norm();

    std::cout << "a + b: " << sum.transpose() << '\n'
              << "a dot b: " << dot << '\n'
              << "length of a: " << length << '\n';

    const double tolerance = 1e-12;
    if (!sum.isApprox(Eigen::Vector3d(4.0, 6.0, 3.0), tolerance)
        || std::abs(dot - 11.0) > tolerance
        || std::abs(length - 5.0) > tolerance) {
        std::cerr << "Eigen test failed\n";
        return 1;
    }

    std::cout << "Eigen test passed\n";
    return 0;
}
