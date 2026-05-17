#  Gestion des Piles (Stack) en C

##  Description
Ce projet est une implémentation simple de la structure de données **Pile (Stack)** en langage C.

Le programme permet de :
- Créer et initialiser des piles
- Ajouter (push) et supprimer (pop) des éléments
- Afficher une pile
- Déplacer les éléments entre piles selon une condition (pair / impair)

---

##  Fonctionnalités

-  Initialisation d’une pile
-  Ajout d’un élément (Push)
-  Suppression d’un élément (Pop)
-  Accès au sommet de la pile
-  Affichage de la pile
-  Déplacement des éléments :
  - Nombres **impairs → P2**
  - Nombres **pairs → P3**
  - Puis fusion de P3 dans P2

---

##  Structure de données

```c
#define max 100

typedef struct {
    int tab[max];
    int sommet;
} Pile;
