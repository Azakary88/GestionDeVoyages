#include "Client.h"
#include <iostream>

Client::Client(const std::string& nom, const std::string& telephone)
    : nom(nom), telephone(telephone) {}

void Client::afficher() const {
    std::cout << "Client: " << nom << ", Telephone: " << telephone << std::endl;
}

