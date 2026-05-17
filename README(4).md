#  Gestion des Étudiants avec Liste Doublement Chaînée (C)

##  Description
Ce projet implémente une **liste doublement chaînée** en langage C pour gérer les étudiants des filières **SIR** et **GI**.

Chaque étudiant contient :
- Apogée
- Nom
- Prénom
- Filière

Le programme permet d’insérer, supprimer, trier et analyser les étudiants.

---

##  Fonctionnalités

-  Création de la liste
-  Insertion au début / à la fin
-  Affichage de la liste
-  Suppression par position
-  Destruction complète de la liste
-  Statistiques (SIR / GI)
-  Tri par nom (ordre alphabétique)
-  Suppression des étudiants SIR

---

##  Structure de données

```c
typedef struct etudiant {
    int apogee;
    char nom[20];
    char prenom[20];
    char filiere[20];
    struct etudiant *precedent;
    struct etudiant *suivant;
} Etudiant;
