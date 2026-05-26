#pragma once

#include "../main.hpp"

#include <chrono>
#include <thread>
#include <cmath>

#define PI 3.14159265358979323846

class GeneralEngine {
public:
    GeneralEngine(const GeneralEngine&) = delete;
    GeneralEngine& operator=(const GeneralEngine&) = delete;

    GeneralEngine(GeneralEngine&&) = delete;
    GeneralEngine& operator=(GeneralEngine&&) = delete;

    static GeneralEngine& get();

    void moving_charge();
    
private:
    GeneralEngine() {}
    ~GeneralEngine();

    int q;
    int v;
    int B;
    uint16_t theta;

    double F;
};

// gemini --resume '8b8ea117-1932-4262-9abd-4ffe379d982d'
