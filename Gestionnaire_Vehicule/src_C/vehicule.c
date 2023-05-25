#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure de données pour représenter un véhicule
typedef struct {
    char type_vehicule[20];
    char marque[50];
    char modele[50];
    int annee;
    char couleur[20];
} Vehicule;

// Structure de données pour représenter la liste de véhicules
typedef struct {
    Vehicule *vehicules;
    int capacite;
    int taille;
} ListeVehicules;

// Fonction pour créer une nouvelle liste de véhicules
ListeVehicules* creerListeVehicules(int capacite) {
    ListeVehicules *liste = (ListeVehicules*) malloc(sizeof(ListeVehicules));
    liste->vehicules = (Vehicule*) malloc(capacite * sizeof(Vehicule));
    liste->capacite = capacite;
    liste->taille = 0;
    return liste;
}

// Fonction pour ajouter un véhicule à la liste
void ajouterVehicule(ListeVehicules *liste, Vehicule vehicule) {
    if (liste->taille < liste->capacite) {
        liste->vehicules[liste->taille] = vehicule;
        liste->taille++;
        printf("Le véhicule a été ajouté avec succès.\n");
    } else {
        printf("La liste de véhicules est pleine. Impossible d'ajouter le véhicule.\n");
    }
}

// Fonction pour supprimer un véhicule de la liste
void supprimerVehicule(ListeVehicules *liste, int index) {
    if (index >= 0 && index < liste->taille) {
        for (int i = index; i < liste->taille - 1; i++) {
            liste->vehicules[i] = liste->vehicules[i + 1];
        }
        liste->taille--;
        printf("Le véhicule a été supprimé avec succès.\n");
    } else {
        printf("Indice de véhicule invalide. Impossible de supprimer le véhicule.\n");
    }
}

// Fonction pour modifier un véhicule de la liste
void modifierVehicule(ListeVehicules *liste, int index, Vehicule vehiculeModifie) {
    if (index >= 0 && index < liste->taille) {
        liste->vehicules[index] = vehiculeModifie;
        printf("Le véhicule a été modifié avec succès.\n");
    } else {
        printf("Indice de véhicule invalide. Impossible de modifier le véhicule.\n");
    }
}

// Fonction pour afficher la liste complète des véhicules enregistrés
void afficherListeVehicules(ListeVehicules *liste) {
    if (liste->taille == 0) {
        printf("Aucun véhicule enregistré dans la liste.\n");
    } else {
        printf("Liste des véhicules enregistrés :\n");
        for (int i = 0; i < liste->taille; i++) {
            Vehicule vehicule = liste->vehicules[i];
            printf("Véhicule %d :\n", i + 1);
            printf("|-Marque : %s\n", vehicule.type_vehicule);
            printf("|-Marque : %s\n", vehicule.marque);
            printf("|-Modèle : %s\n", vehicule.modele);
            printf("|-Année : %d\n", vehicule.annee);
            printf("|-Couleur : %s\n", vehicule.couleur);
            printf("\n");
        }
    }
}

// Fonction pour rechercher un véhicule enregistré en utilisant des critères
void rechercherVehicule(ListeVehicules *liste, char critere[50]) {
    int vehiculeTrouve = 0;
    for (int i = 0; i < liste->taille; i++) {
        Vehicule vehicule = liste->vehicules[i];
        if (strcmp(vehicule.marque, critere) == 0 ||
            strcmp(vehicule.modele, critere) == 0 ||
            strcmp(vehicule.couleur, critere) == 0||
            strcmp(vehicule.type_vehicule,critere) == 0) {
            printf("Véhicule correspondant trouvé :\n");
            printf("Type : %s\n", vehicule.type_vehicule);
            printf("Marque : %s\n", vehicule.marque);
            printf("Modèle : %s\n", vehicule.modele);
            printf("Année : %d\n", vehicule.annee);
            printf("Couleur : %s\n", vehicule.couleur);
            printf("\n");
            vehiculeTrouve = 1;
        }
    }
    if (!vehiculeTrouve) {
        printf("Aucun véhicule correspondant trouvé.\n");
    }
}