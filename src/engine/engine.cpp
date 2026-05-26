#include "../../inc/engine/engine.hpp"


GeneralEngine::~GeneralEngine() {
    std::cout << "bai" << std::endl;
}

GeneralEngine& GeneralEngine::get() {
    static GeneralEngine instance;
    return instance;
}

void GeneralEngine::moving_charge() {
    std::cout << "Magnetic Force on Moving Charge" << std::endl;
    std::cout << "Formula: F = q * v * B * sin(theta)" << std::endl << "\n";

    std::cout << "Enter charge (q in Coulombs): " << "\n";
    std::cin >> q;

    std::cout << "Enter velocity (v in m/s): " << "\n";
    std::cin >> v;

    std::cout << "Enter magnetic field strength (B in Tesla): " << "\n";
    std::cin >> B;

    std::cout << "Enter angle (theta in degrees): " << "\n";
    std::cin >> theta;
    
    std::cout << "Thank you! Computing the magnetic force";

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";

    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << ".";
    
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "." << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));

    F = q * v * B * std::sin(theta * PI / 180.0);

    F = std::round(F * 100);
    F = F / 100;

    std::cout << "The magnetic force (F) on the moving charge is: " << F << "N" << std::endl;
}
