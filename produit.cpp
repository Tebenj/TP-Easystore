#include "produit.h"
#include <iostream>


namespace Prod {

    Produit::Produit(std::string titre, std::string description, double stock, double prix) // Constructeur d'un produit
    : _titre(titre), _description(description), _stock(stock), _prix(prix)
    {
    }
    
    std::string Produit::getTitre() const{ //Nom du produit
        return _titre; 
    }

    std::string Produit::getDescription(){ //Description du produit
        return _description;
    }

    double Produit::getStock(){ //Stock du produit
        return _stock;
    }

    double Produit::getPrix(){ //Prix du produit
        return _prix;
    }

    void Produit::modifStock(double stock){ //Modification du stock du produit 
            _stock = stock;
    }
    
    std::ostream& operator<<(std::ostream& os, const Produit& produit){ // Affichage d'un produit grâce à la surcharge d'opérateur
        std::string to_display = produit._titre + "," + produit._description + "," + std::to_string(produit._stock) + "," + std::to_string(produit._prix)+"€"; 
        os << to_display << std::endl;
        return os;
    }

      Produit& Produit::operator=(Produit produit){
         _titre = produit.getTitre();
         _description = produit.getDescription();
         _stock = produit.getStock();
         _prix = produit.getPrix();
         return *this;
    }

}