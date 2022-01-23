#include <string>
#pragma once

namespace Prod{

    class Produit{
        public:
        Produit(std::string titre, std::string description, double stock, double prix);
        std::string getTitre() const;
        std::string getDescription();
        double getStock();
        double getPrix();
        void modifStock(double stock);
        Produit& operator=(Produit produit);
        friend std::ostream& operator<<(std::ostream& os, const Produit& produit);
        private:
        std::string _titre;
        std::string _description;
        double _stock;
        double _prix;

    };
}