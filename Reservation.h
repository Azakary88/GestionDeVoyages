#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>

class Reservation {
public:
    int id;
    std::string nomClient;
    std::string telephone;
    std::string destination;

    Reservation(int id, const std::string& nomClient, const std::string& telephone, const std::string& destination);

    void afficher() const;
};

#endif

