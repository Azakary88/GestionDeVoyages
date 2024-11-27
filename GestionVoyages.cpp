#include "GestionVoyages.h"
#include "GestionVoyages.h"
#include "Destination.h"
#include "Reservation.h"
#include <iostream>
#include <fstream>

GestionVoyages::GestionVoyages() : prochainIdReservation(1) {}

void GestionVoyages::ajouterDestination(const std::string& nom, const std::string& pays, const std::vector<std::string>& attractions) {
    destinations.push_back(Destination(nom, pays, attractions));
    std::cout << "Destination ajoutee : " << nom << " (" << pays << ")" << std::endl;
}

void GestionVoyages::enregistrerClient(const std::string& nom, const std::string& telephone) {
    clients.push_back(Client(nom, telephone));
    std::cout << "Client ajoute : " << nom << " (" << telephone << ")" << std::endl;
}

void GestionVoyages::afficherDestinations() const {
    for (const auto& destination : destinations) {
        destination.afficher();
    }
}

void GestionVoyages::afficherClients() const {
    for (const auto& client : clients) {
        client.afficher();
    }
}

void GestionVoyages::enregistrerReservation(const std::string& nomClient, const std::string& telephone, const std::string& destination) {
    reservations.push_back(Reservation(prochainIdReservation++, nomClient, telephone, destination));
    std::cout << "R�servation ajout�e pour " << nomClient << " vers " << destination << "." << std::endl;
}

void GestionVoyages::afficherReservations() const {
    for (const auto& reservation : reservations) {
        reservation.afficher();
    }
}

void GestionVoyages::modifierReservation(int id) {
    for (auto& reservation : reservations) {
        if (reservation.id == id) {
            std::cout << "Modification de la r�servation ID: " << id << std::endl;
            std::cout << "Nouveau nom du client: ";
            std::cin >> reservation.nomClient;
            std::cout << "Nouveau t�l�phone: ";
            std::cin >> reservation.telephone;
            std::cout << "Nouvelle destination: ";
            std::cin >> reservation.destination;
            std::cout << "R�servation modifi�e avec succ�s !" << std::endl;
            return;
        }
    }
    std::cout << "R�servation non trouv�e !" << std::endl;
}

void GestionVoyages::annulerReservation(int id) {
    for (auto it = reservations.begin(); it != reservations.end(); ++it) {
        if (it->id == id) {
            reservations.erase(it);
            std::cout << "R�servation ID " << id << " annul�e avec succ�s !" << std::endl;
            return;
        }
    }
    std::cout << "R�servation non trouv�e !" << std::endl;
}

void GestionVoyages::exporterReservations(const std::string& nomFichier) const {
    std::ofstream fichier(nomFichier);
    if (!fichier.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier !" << std::endl;
        return;
    }

    fichier << "ID,Client,T�l�phone,Destination\n";
    for (const auto& reservation : reservations) {
        fichier << reservation.id << ","
                << reservation.nomClient << ","
                << reservation.telephone << ","
                << reservation.destination << "\n";
    }
    fichier.close();
    std::cout << "Donn�es export�es dans le fichier : " << nomFichier << std::endl;
}
