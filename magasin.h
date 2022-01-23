#include <vector>
#include <string>
#include "produit.h"
#include "client.h"
#include "commande.h"



namespace Store{

class Magasin {
    public:
    Magasin();
    void addProduct(Prod::Produit produit);
    Prod::Produit selectProduct(std::string selecproduit);
    void modifQtite(double quantite, std::string search);
    void afficheProduits();
    void addClient(Consom::Client* client);
    void afficheClients();
    void selectClient(std::string seleclient);
    void addProductPanier(Prod::Produit produit, Consom::Client* client);
    void delProductPanier(Prod::Produit produit, Consom::Client* client);
    void modifQtitePanier(double quantite, Prod::Produit produit, Consom::Client* client);
    bool validCommande(Consom::Client* client);
    void statusCommande(Achat::Commande* commande, Consom::Client client);
    void afficheCommandes();
    void afficheCommandesClient(Consom::Client* client);
    friend std::ostream& operator<<(std::ostream& os, const Magasin& magasin);
    private:
    std::vector<Prod::Produit> _magasin;
    std::vector<Consom::Client*> _clients;
    std::vector<Achat::Commande> _orders;


};
}