#ifndef GESTIONVOYAGES_H
#define GESTIONVOYAGES_H

#include <vector>
#include <string>
#include "Destination.h"
#include "Client.h"
#include "Reservation.h"


class GestionVoyages {
private:
    std::vector<Destination> destinations;
    std::vector<Reservation> reservations;
    std::vector<Client> clients;
    int prochainIdReservation;

public:
    GestionVoyages();
    void ajouterDestination(const std::string& nom, const std::string& pays, const std::vector<std::string>& attractions);
    void enregistrerClient(const std::string& nom, const std::string& telephone);
    void afficherDestinations() const;
    void afficherClients() const;
    void enregistrerReservation(const std::string& nomClient, const std::string& telephone, const std::string& destination);
    void afficherReservations() const;
    void modifierReservation(int id);
    void annulerReservation(int id);
    void exporterReservations(const std::string& nomFichier) const;
};

#endif

