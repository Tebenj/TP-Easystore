#include <string>
#include "produit.h"
#include <vector>
#pragma once

namespace Consom{

    class Client {
        public:
        Client(std::string prenom, std::string nom, double id, std::vector<Prod::Produit> panier);
        std::string getPrenom();
        std::string getNom();
        double getId();
        std::vector<Prod::Produit> getPanier();
        void addPanier(Prod::Produit panier);
        void videPanier();
        void modifQtitePanier(double quantite, Prod::Produit produit);
        void supprProduitPanier(Prod::Produit produit);
        friend std::ostream& operator<<(std::ostream& os, const Client& client);
        private:
        std::string _prenom;
        std::string _nom;
        double _id;
        std::vector<Prod::Produit> _panier;

};
}