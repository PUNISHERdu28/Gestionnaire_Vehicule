#ifndef VEHICULE_H
#define VEHICULE_H

typedef struct {
    char marque[50];
    char modele[50];
    int annee;
    char couleur[20];
    char type_vehicule[20];
} Vehicule;

typedef struct {
    Vehicule *vehicules;
    int capacite;
    int taille;
} ListeVehicules;

ListeVehicules* creerListeVehicules(int capacite);
void ajouterVehicule(ListeVehicules *liste, Vehicule vehicule);
void supprimerVehicule(ListeVehicules *liste, int index);
void modifierVehicule(ListeVehicules *liste, int index, Vehicule vehiculeModifie);
void afficherListeVehicules(ListeVehicules *liste);
void rechercherVehicule(ListeVehicules *liste, char critere[50]);

#endif
