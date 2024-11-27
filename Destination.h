#ifndef DESTINATION_H
#define DESTINATION_H

#include <string>
#include <vector>

class Destination {
public:
    std::string nom;
    std::string pays;
    std::vector<std::string> attractions;

    Destination(const std::string& nom, const std::string& pays, const std::vector<std::string>& attractions);
    void afficher() const;
};

#endif

