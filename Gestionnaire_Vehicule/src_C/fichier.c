#include <stdio.h>
#include <string.h>
#include "fichier.h"

void sauvegarderListeVehicules(ListeVehicules *liste, const char *nomFichier) {
    
    printf("Destination: %s",nomFichier);
    FILE *fichier = fopen(nomFichier, "w");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    fprintf(fichier, "[\n");
    for (int i = 0; i < liste->taille; i++) {
        Vehicule vehicule = liste->vehicules[i];
        fprintf(fichier, "  {\n");
        fprintf(fichier, "    \"marque\": \"%s\",\n", vehicule.marque);
        fprintf(fichier, "    \"modele\": \"%s\",\n", vehicule.modele);
        fprintf(fichier, "    \"annee\": %d,\n", vehicule.annee);
        fprintf(fichier, "    \"couleur\": \"%s\",\n", vehicule.couleur);
        fprintf(fichier, "    \"type_vehicule\": \"%s\"\n", vehicule.type_vehicule);
        if (i < liste->taille - 1) {
            fprintf(fichier, "  },\n");
        } else {
            fprintf(fichier, "  }\n");
        }
    }
    fprintf(fichier, "]\n");

    fclose(fichier);
}
