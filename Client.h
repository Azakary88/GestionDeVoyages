#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
public:
    std::string nom;
    std::string telephone;

    Client(const std::string& nom, const std::string& telephone);
    void afficher() const;
};

#endif



