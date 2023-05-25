import json

class Vehicule:
    def __init__(self, marque, modele, annee, couleur, type_vehicule):
        self.marque = marque
        self.modele = modele
        self.annee = annee
        self.couleur = couleur
        self.type_vehicule = type_vehicule
        print(f"Génération de la {self.marque} {self.modele} Terminé")
        
    def afficher(self):
        print("Marque:", self.marque)
        print("Modèle:", self.modele)
        print("Année:", self.annee)
        print("Couleur:", self.couleur)
        print("Type de véhicule:", self.type_vehicule)
        print()

# Chemin vers le fichier JSON contenant les informations des véhicules
fichier_json = "./src_C/save.json"

# Lecture du fichier JSON
with open(fichier_json,"r") as f:
    data = json.load(f)

# Création des objets Vehicule à partir des données du fichier JSON
liste_vehicules = []
for vehicule_json in data:
    vehicule = Vehicule(vehicule_json["marque"], vehicule_json["modele"],
                        vehicule_json["annee"], vehicule_json["couleur"],
                        vehicule_json["type_vehicule"])
    liste_vehicules.append(vehicule)

# Affichage des véhicules
for vehicule in liste_vehicules:
    vehicule.afficher()
