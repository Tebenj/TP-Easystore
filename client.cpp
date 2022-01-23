#include "client.h"
#include "produit.h"
#include <iostream>

namespace Consom{

    Client::Client(std::string prenom, std::string nom, double id, std::vector<Prod::Produit> panier) // Constructeur d'un client
    : _prenom(prenom), _nom(nom), _id(id), _panier(panier) 
    {    
    }

    std::string Client::getPrenom(){ //Prénom du client
        return _prenom;
    }

    std::string Client::getNom(){ //Nom du client
        return _nom;
    }

    double Client::getId(){ //identifiant du client
        return _id;
    }

    std::vector<Prod::Produit> Client::getPanier(){ //Panier du client
        return _panier;
    }

    void Client::addPanier(Prod::Produit produit){ // Ajouter un produit au panier
        _panier.push_back(produit);

    }
    
    void Client::videPanier(){ // Vider le panier
        _panier.clear();

    }

    void Client::modifQtitePanier(double quantite, Prod::Produit produit){ // Modifier la quantité d'un produit dans le panier
        for(int i=0; i<_panier.size(); i++){
            if(_panier.at(i).getTitre() == produit.getTitre()){
            _panier.at(i).modifStock(quantite);
            }
        }
    }

    void Client::supprProduitPanier(Prod::Produit produit){ // Supprimer la quantité d'un produit dans le panier 
        for(int i=0; i<_panier.size(); i++){
            if(_panier[i].getTitre() == produit.getTitre())
                _panier.erase(_panier.begin()+i);
        }    
    }

    std::ostream& operator<<(std::ostream& os, const Client& client){ // Affichage d'un client grâce à la surcharge d'opérateur
        std::string to_display = client._prenom + "," + client._nom + "," + std::to_string(client._id); 
        os << to_display << std::endl;
        for(auto produit: client._panier)
            os << produit << std::endl;
        return os;
    }







}
