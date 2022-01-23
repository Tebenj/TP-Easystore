#include "magasin.h"
#include "produit.h"
#include "commande.h"
#include <iostream>
#include <fstream>


int main (){

    Store::Magasin EasyStore; // Création de l'objet magasin
    //Création des produits
    Prod::Produit play("PS5","Playstation 5", 15,500); 
    Prod::Produit led("LED","Ruban LED", 200,20);
    Prod::Produit ssd("SSD","Disque SDD 1TO", 80, 150);
    //Ajout des produits au magasin
    EasyStore.addProduct(play);
    EasyStore.addProduct(led);
    EasyStore.addProduct(ssd);
    std::vector<Prod::Produit> _panierclient; // Création du panier du client
    Consom::Client c1("Mathilde ","Chevallier",21,_panierclient); // Création du client
    EasyStore.addClient(&c1); // Ajout du client au magasin
    EasyStore.addProductPanier(play, &c1); // Ajout du produit au panier du client
    Achat::Commande commande(c1, "pas livré"); // Création de la commande du client 
    int menu =0 ,menu1=0,menu2=0,menu3 = 0,id = 0;
    std::string nomprod,desprod,modifstock,prenom,nom,nomclient;
    double stock,prix,quantite;

    do{
        std::cout << "Bienvenue dans votre magasin EasyStore. Que voulez-vous faire ?" << std::endl; // Menu du magasin
        std::cout << "1.Gestion du magasin" << std::endl;
        std::cout << "2.Gestion des clients" << std::endl;
        std::cout << "3.Gestion des commandes" << std::endl;
        std::cout << "4.Quitter" << std::endl;
        std::cin >> menu;
        switch (menu){

        case 1:{
            std::cout << "Que voulez-vous faire dans le magasin?" << std::endl; // Gestion des produits
            std::cout << "1.Ajouter un produit" << std::endl;
            std::cout << "2.Mettre à jour le stock" << std::endl;
            std::cout << "3.Afficher les produits disponible" << std::endl;
            std::cout << "4.Quitter" << std::endl;
            std::cin >> menu1;
        do{
            switch(menu1){
                case 1:
                {
                    std::cout << "Quel est le nom du produit, sa description, son stock et son prix ?" << std::endl; 
	                std::cin >> nomprod;
	                std::cout << std::endl;
	                std::cin >> desprod;
	                std::cout << std::endl;
	                std::cin >> stock;
                    std::cin >> prix;
                    Prod::Produit addProd(nomprod,desprod,stock,prix);
                    std::cout << "La liste des produits est maintenant :" << std::endl;
                    EasyStore.addProduct(addProd);
                    EasyStore.afficheProduits();
                    break;
                }

                case 2:
                    std::cout << "Quel est le produit dont vous voulez modifier le stock ?" << std::endl; 
	                std::cin >> modifstock;
                    std::cout << "Quel est le nouveau stock ?" << std::endl; 
                    std::cin >> quantite;
                    EasyStore.selectProduct(modifstock);
	                EasyStore.modifQtite(quantite, modifstock);
                    std::cout << "Le stock du produit a été modifié :" << std::endl;
                    break;
                case 3:

                    std::cout << "Voici la liste des produits présent dans le magasin :" << std::endl;
                    EasyStore.afficheProduits();
                    break;

                case 4:
                break;
            }
            
        }while(menu1 != 1 && menu1 != 2 && menu1 != 3 && menu1 != 4);
    break;
    }
        case 2:{
            std::cout << "Que voulez-vous faire avec les clients?" << std::endl; // Gestion des clients
            std::cout << "1.Ajouter un client" << std::endl;
            std::cout << "2.Afficher tous les clients" << std::endl;
            std::cout << "3.Ajouter un article au panier" << std::endl;
            std::cout << "4.Supprimer un article au panier" << std::endl;
            std::cout << "5.Modifier la quantité d'un article du panier" << std::endl;
            std::cout << "6.Quitter" << std::endl;
            std::cin >> menu2;
  
            do{
                switch(menu2){

                    case 1:{
                        std::cout << "Quel est votre prenom, votre nom et votre identifiant(numérique) ?" << std::endl; 
                        std::cin >> prenom;
                        std::cout << std::endl;
                        std::cin >> nom;
                        std::cout << std::endl;
                        std::cin >> id;
                        std::vector <Prod::Produit> _newpanier;
                        Consom::Client c2(prenom,nom,id,_newpanier);
                        EasyStore.addClient(&c2);
                        EasyStore.afficheClients();
                        break;
                    }

                    case 2:{
                        std::cout << "Voici la liste des clients :" << std::endl;
                        EasyStore.afficheClients();
                        break;
                    }

                    case 3:{
                       std::cout << "Ajout des produits led et ssd au panier du client " << std::endl;
                       EasyStore.addProductPanier(led,&c1);
                       EasyStore.addProductPanier(ssd,&c1);
                       break;
                    }

                    case 4:{
                       std::cout << "Suppression du ssd au panier du client " << std::endl;
                       EasyStore.delProductPanier(ssd,&c1);
                       break;
                    }

                    case 5:{
                       std::cout << "Quel quantité voulez-vous de leds ?" << std::endl;
                       double qtite;
                       std::cin >> qtite;
                       EasyStore.modifQtitePanier(qtite,led,&c1);
                       break;
                    }

                    case 6:{
                        break;
                    }
                
                }
            }while(menu2 != 1 && menu2 != 2 && menu2 != 3 && menu2 != 4 && menu2 != 5 && menu2 != 6);
        break;
        }  
        
        case 3:{
            std::cout << "Que voulez-vous faire avec les commandes?" << std::endl; // Gestion des commandes 
            std::cout << "1.Afficher les commandes" << std::endl;
            std::cout << "2.Afficher les commandes d'un client" << std::endl;
            std::cout << "3.Valider une commande" << std::endl;
            std::cout << "4.Modifier le statut d'une commande" << std::endl;
            std::cout << "5.Quitter" << std::endl;
            std::cin >> menu3;
            
            do{
                switch (menu3){
                
                    case 1:{
                        EasyStore.afficheCommandes();
                        break;
                    }

                    case 2:{
                        EasyStore.afficheCommandesClient(&c1);
                        break;
                    }
                    
                    case 3:{
                        EasyStore.validCommande(&c1);
                        break;
                    }
                    
                    case 4:{
                        EasyStore.statusCommande(&commande, c1);
                        break;
                    }

                    case 5:{
                        break;
                    }
                }

            }while(menu3 != 1 && menu3 != 2 && menu3 != 3 && menu3 != 4 && menu3 != 5);
        break;
        }

        case 4:{
            std::ofstream write_EasyStore("EasyStore.txt"); //Enregistrement dans un fichier
			if (write_EasyStore)
			{
				write_EasyStore << EasyStore << std::endl;
				write_EasyStore.close();
			}
			else 
				std::cout << "Erreur d'ouverture du fichier" << std::endl;

			std::ifstream read_EasyStore("EasyStore.txt"); //Lecture d'un fichier
			if(read_EasyStore)
			{
				std::string ligne;
				while (getline(read_EasyStore, ligne))
				{
					std::cout << ligne << std::endl;
				}
			}
			else 
				std::cout << "Erreur de lecture du fichier" << std::endl;
        break;
		}
    break;
    }

    }while(menu != 4);

}