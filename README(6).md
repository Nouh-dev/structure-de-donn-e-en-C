#  Gestion de Bibliothèque avec Liste Doublement Chaînée (C)

##  Description
Ce projet implémente une **liste doublement chaînée** en langage C pour gérer une bibliothèque.

Chaque livre contient des informations comme :
- Code (cote)
- Titre
- Auteur
- Discipline
- Éditeur
- Nombre d’exemplaires

---

##  Fonctionnalités

-  Création de la liste
-  Allocation dynamique d’un livre
-  Ajout d’un livre dans la liste
-  Gestion des doublons (augmentation des exemplaires)
-  Structure doublement chaînée
-  Gestion dynamique de la mémoire

---

##  Structure de données

### Livre

```c
typedef struct livre {
    int cote;
    char *titre;
    char *auteur;
    char *discipline;
    char *editeur;
    int nbrexemplaires;
} Livre;
