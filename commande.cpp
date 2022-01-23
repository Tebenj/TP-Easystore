#include "commande.h"
#include <iostream>


namespace Achat {

    Commande::Commande(Consom::Client client, std::string status) // Constructeur d'une commande
    : _client(client), _status(status)
    {
        _produitachete = _client.getPanier();
    }


    std::string Commande::getStatus(){ // Obtenir le statut d'une commande 
	    return _status;
    }

    void Commande::modifStatus(std::string status){ // Modifier le status de la commande 
        _status = status;
    }
    
    
    std::ostream& operator<<(std::ostream& os, const Commande& commande){ // Affichage d'une commande grâce à la surcharge d'opérateur
        os << commande._client << std::endl;
        for (int i=0; i!= commande._produitachete.size(); i++){
            os << commande._produitachete[i].getTitre() << std::endl;
        }
        os << commande._status << std::endl;
        return os;
    }
}