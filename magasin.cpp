#include "magasin.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>


namespace Store {

    Magasin::Magasin(){} // Constructeur par défaut 


    void Magasin::addProduct(Prod::Produit produit){ //Ajout d'un produit au magasin
        _magasin.push_back(produit);
    }


    Prod::Produit Magasin::selectProduct(std::string selecproduit){ // Sélection d'un produit par son titre
        Prod::Produit tempProduit("","",0,0);
        for (auto produit: _magasin){
            if( produit.getTitre() == selecproduit){ 
                tempProduit = produit;
                
            }
        }
        return tempProduit;
    }

    void Magasin::modifQtite(double quantite, std::string search){ // Modification du stock d'un produit du magasin en fonction de son titre
        Prod::Produit produit = selectProduct(search);
        produit.modifStock(quantite);
        std::cout << produit << std::endl;
        

    }

    void Magasin::afficheProduits(){ // Affichage des produits du magasin
        for(int i = 0; i < _magasin.size(); i++)
            std::cout <<"Produit numéro " << i + 1 << " : " <<_magasin[i];
    }

    void Magasin::addClient(Consom::Client* client){ // Ajout d'un client au magasin
        _clients.push_back(client);
    }

    void Magasin::afficheClients(){ // Affichage des clients du magasin 
        for(int i = 0; i < _clients.size(); i++)
            std::cout <<"Client numéro " << i + 1 << " : " <<*_clients[i];
    }

    void Magasin::selectClient(std::string seleclient){ // Sélection d'un client par son nom
        std::vector<Consom::Client*>::iterator it;
        for(it = _clients.begin(); it != _clients.end(); it++)
        {
            if((*it)->getNom() == seleclient)
                std::cout << **it;
        }
    }

    void Magasin::addProductPanier(Prod::Produit produit, Consom::Client* client){ // Ajout d'un produit au panier du client
        client->addPanier(produit);
    }
    
    void Magasin::delProductPanier(Prod::Produit produit, Consom::Client* client){ // Suppression d'un produit au panier du client
        client->supprProduitPanier(produit);
    }

    void Magasin::modifQtitePanier(double quantite, Prod::Produit produit, Consom::Client* client){ // Modification de la quantité d'un produit au panier du client
        if(produit.getStock() >= quantite){
        client->modifQtitePanier(quantite, produit);

        }
        else
            std::cout << "Le stock n'est pas suffisant" << std::endl;

    }

    bool Magasin::validCommande(Consom::Client* client){ // Validation de la commande 
        int validation = 0; 
        do{
        std::cout << "Voulez vous valider la commande ? 1.Oui 2.Non" << std::endl;
        std::cin >> validation;
        }while(validation != 1 && validation != 2);
        if (validation == 1){
            std::cout << "La commande est validé" << std::endl;
            return true;
        }
        else
            return false;
    }

    void Magasin::statusCommande(Achat::Commande* commande, Consom::Client client){ // Statut de la commande 
        int status = 0;
        do{
            std::cout << "Quel est le statut de la commande ? 1.Non livrée 2.Livrée" << std::endl;
            std::cin >> status;
        }while(status != 1 && status != 2);
        if (status == 1){
            std::string etat1 = "La commande n'est pas encore livrée";
            commande->modifStatus(etat1);
        }
        if (status == 2){
            std::string etat2 = "La commande est livrée";
            commande->modifStatus(etat2);
            _orders.push_back(*commande);
            client.videPanier();
        }  
    }

    void Magasin::afficheCommandes(){ // Affichage de toutes les commandes 
        for(int i = 0; i < _orders.size(); i++)
		std::cout <<"Commande numéro " << i + 1 << " : " << _orders[i];
    }

    void Magasin::afficheCommandesClient(Consom::Client* client){ // Affichage de toutes les commandes du client choisis
        for(int i=0; i<_clients.size(); i++){
            if(client->getId() == _clients.at(i)->getId()){
                for(int i = 0; i < _orders.size(); i++)
		        std::cout <<"Commande numéro " << i + 1 << " : " << _orders[i];
            }

        }
    }

    std::ostream& operator<<(std::ostream& os, const Magasin& magasin){ // Surcharge de l'operateur afin de pouvoir l'afficher dans un fichier

        os << "Produits :" << std::endl;
        for(int i = 0; i < magasin._magasin.size(); i++){
            os << magasin._magasin.at(i).getTitre() << std::endl; //Affiche les produits en magasin
        }

        os << std::endl << "Clients :" << std::endl;
        for(int i = 0; i < magasin._clients.size(); i++){ //Affiche les clients du magasin
            os << magasin._clients[i]->getPrenom() << " " << magasin._clients[i]->getNom() << std::endl << "ID : " << magasin._clients[i]->getId() << std::endl << std::endl;
        }

        os << std::endl << "Commandes :" << std::endl;
        for(int i = 0; i < magasin._orders.size(); i++){
            os << magasin._orders[i] << std::endl << std::endl; //Affiche les commandes des clients du magasin
        }
        return os;
    }
}

