#  Gestion des Étudiants avec Liste Simply Chaînée (C)

##  Description
Ce projet implémente une **liste simplement chaînée (Linked List)** en langage C pour gérer les informations des étudiants d’une classe.

Chaque étudiant contient :
- Nom
- Prénom
- Note

Le programme permet d’insérer, afficher, trier, diviser et supprimer des étudiants.

---

##  Fonctionnalités

-  Création d’un étudiant (nœud)
-  Insertion au début
-  Insertion à la fin
-  Affichage de la liste
-  Suppression du début
-  Suppression complète de la liste
-  Tri des étudiants par note (ordre décroissant)
-  Division de la liste (admis / non admis)

---

##  Structure de données

### Étudiant (nœud)

```c
typedef struct etudiant {
    char *Nom;
    char *Prenom;
    float Note;
    struct etudiant *suivant;
} Etudiant;
