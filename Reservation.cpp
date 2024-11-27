#include "Reservation.h"
#include <iostream>

Reservation::Reservation(int id, const std::string& nomClient, const std::string& telephone, const std::string& destination)
    : id(id), nomClient(nomClient), telephone(telephone), destination(destination) {}

void Reservation::afficher() const {
    std::cout << "ID: " << id
              << ", Client: " << nomClient
              << ", Telephone: " << telephone
              << ", Destination: " << destination << std::endl;
}

