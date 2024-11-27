#include "Destination.h"
#include <iostream>

Destination::Destination(const std::string& nom, const std::string& pays, const std::vector<std::string>& attractions)
    : nom(nom), pays(pays), attractions(attractions) {}

void Destination::afficher() const {
    std::cout << "Destination: " << nom << ", Pays: " << pays << "\nAttractions: ";
    for (const auto& attraction : attractions) {
        std::cout << attraction << " ";
    }
    std::cout << std::endl;
}

