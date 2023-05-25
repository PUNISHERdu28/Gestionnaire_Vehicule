#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vehicule.h"
#include "fichier.h"

void afficherMenu() {
    printf("\n------ MENU ------\n");
    printf("1. Ajouter un véhicule\n");
    printf("2. Supprimer un véhicule\n");
    printf("3. Modifier un véhicule\n");
    printf("4. Afficher la liste des véhicules\n");
    printf("5. Rechercher un véhicule\n");
    printf("6. Sauvegarder la liste des véhicules\n");
    printf("7. Quitter\n");
    printf("Choix : ");
}

int main() {
    ListeVehicules *liste = creerListeVehicules(100);

    int choix = 0;

    while (choix != 7) {
        afficherMenu();
        scanf("%d", &choix);

        switch (choix) {
            case 1: {
                Vehicule vehicule;
                printf("\n--- Ajouter un véhicule ---\n");
                printf("Marque : ");
                scanf("%s", vehicule.marque);
                printf("Modèle : ");
                scanf("%s", vehicule.modele);
                printf("Année : ");
                scanf("%d", &vehicule.annee);
                printf("Couleur : ");
                scanf("%s", vehicule.couleur);
                printf("Type de véhicule (bus, moto, voiture, etc.) : ");
                scanf("%s", vehicule.type_vehicule);

                ajouterVehicule(liste, vehicule);
                break;
            }
            case 2: {
                int indiceSuppression;
                printf("\n--- Supprimer un véhicule ---\n");
                printf("Indice du véhicule à supprimer : ");
                scanf("%d", &indiceSuppression);
                supprimerVehicule(liste, indiceSuppression - 1);
                break;
            }
            case 3: {
                int indiceModification;
                printf("\n--- Modifier un véhicule ---\n");
                printf("Indice du véhicule à modifier : ");
                scanf("%d", &indiceModification);
                Vehicule vehiculeModifie;
                printf("Marque : ");
                scanf("%s", vehiculeModifie.marque);
                printf("Modèle : ");
                scanf("%s", vehiculeModifie.modele);
                printf("Année : ");
                scanf("%d", &vehiculeModifie.annee);
                printf("Couleur : ");
                scanf("%s", vehiculeModifie.couleur);
                printf("Type de véhicule (bus, moto, voiture, etc.) : ");
                scanf("%s", vehiculeModifie.type_vehicule);

                modifierVehicule(liste, indiceModification - 1, vehiculeModifie);
                break;
            }
            case 4:
                printf("\n--- Afficher la liste des véhicules ---\n");
                afficherListeVehicules(liste);
                break;
            case 5: {
                char critere[50];
                printf("\n--- Rechercher un véhicule ---\n");
                printf("Critère de recherche (marque, modèle, couleur) : ");
                scanf("%s", critere);
                rechercherVehicule(liste, critere);
                break;
            }
            case 6: {
                char nomFichier[50];
                printf("\n--- Sauvegarder la liste des véhicules ---\n");
                printf("Nom du fichier de sauvegarde : ");
                scanf("%s", nomFichier);
                sauvegarderListeVehicules(liste, nomFichier);
                break;
            }
            case 7:
                printf("Quitter l'application.\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }
    }

    free(liste->vehicules);
    free(liste);

    return 0;
}
