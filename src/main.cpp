#include <iostream>
#include "../inc/main.hpp"

int main() {
    GeneralEngine& engine  = GeneralEngine::get();;

    engine.moving_charge();

    return 0;
}
