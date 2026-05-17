#  Liste Doublement Chaînée Générique (C)

##  Description
Ce projet implémente une **liste doublement chaînée** en langage C permettant de stocker et manipuler des chaînes de caractères dynamiquement.

Il permet d’effectuer des opérations classiques sur une structure de données dynamique.

---

##  Fonctionnalités

-  Initialisation de la liste
-  Insertion dans une liste vide
-  Insertion au début
-  Insertion à la fin
-  Insertion après une position
-  Insertion avant une position
-  Suppression d’un élément par position
-  Affichage de la liste
-  Destruction complète de la liste

---

##  Structure de données

### Élément

```c
typedef struct Element_liste {
    char *info;
    struct Element_liste *precedent;
    struct Element_liste *suivant;
} Element;
