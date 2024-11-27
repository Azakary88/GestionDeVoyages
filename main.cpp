#include <iostream>
#include "GestionVoyages.h"

int main() {
    GestionVoyages gestion;
    int choix;

    while (true) {
        std::cout << "\nMenu Principal\n";
        std::cout << "1. Ajouter une destination\n";
        std::cout << "2. Enregistrer un client\n";
        std::cout << "3. Afficher toutes les destinations\n";
        std::cout << "4. Afficher tous les clients\n";
        std::cout << "5. Enregistrer une reservation\n";
        std::cout << "6. Afficher toutes les reservations\n";
        std::cout << "7. Modifier une reservation\n";
        std::cout << "8. Annuler une reservation\n";
        std::cout << "9. Exporter les reservations\n";
        std::cout << "10. Quitter\n";
        std::cout << "Votre choix : ";
        std::cin >> choix;

        if (choix == 1) {
            std::string nom, pays, attraction;
            std::vector<std::string> attractions;
            std::cout << "Nom de la destination : ";
            std::cin >> nom;
            std::cout << "Pays : ";
            std::cin >> pays;

            std::cout << "Attraction : " <<"(tapez 'fin' pour arreter)";
            while (std::cin >> attraction && attraction != "fin") {
                attractions.push_back(attraction);
            }
            gestion.ajouterDestination(nom, pays, attractions);
        } else if (choix == 2) {
            std::string nom, telephone;
            std::cout << "Nom du client : ";
            std::cin >> nom;
            std::cout << "Telephone : ";
            std::cin >> telephone;
            gestion.enregistrerClient(nom, telephone);
        } else if (choix == 3) {
            gestion.afficherDestinations();
        } else if (choix == 4) {
            gestion.afficherClients();
        }  else if (choix == 5) {
            std::string nomClient, telephone, destination;
            std::cout << "Nom du client : ";
            std::cin >> nomClient;
            std::cout << "Telephone : ";
            std::cin >> telephone;
            std::cout << "Destination : ";
            std::cin >> destination;
            gestion.enregistrerReservation(nomClient, telephone, destination);

        } else if (choix == 6) {
            gestion.afficherReservations();

        } else if (choix == 7) {
            int id;
            std::cout << "ID de la reservation a modifier : ";
            std::cin >> id;
            gestion.modifierReservation(id);

        } else if (choix == 8) {
            int id;
            std::cout << "ID de la reservation a annuler : ";
            std::cin >> id;
            gestion.annulerReservation(id);

        } else if (choix == 9) {
            std::string nomFichier;
            std::cout << "Nom du fichier (avec extension .csv) : ";
            std::cin >> nomFichier;
            gestion.exporterReservations(nomFichier);

        } else if (choix == 10) {
            break;

        } else {
            std::cout << "Choix invalide !" << std::endl;
        }
    }

    return 0;
}
