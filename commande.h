#include <string>
#include "client.h"
#include "produit.h"
#include <vector>
#pragma once


namespace Achat{

    class Commande {
    public:
    Commande(Consom::Client client, std::string status);
    std::string getStatus();
    void modifStatus(std::string status);
    friend std::ostream& operator<<(std::ostream& os, const Commande& commande);
    private:
    Consom::Client _client;
    std::vector<Prod::Produit> _produitachete;
    std::string _status;
   
   
   
   
   
   
    };
}