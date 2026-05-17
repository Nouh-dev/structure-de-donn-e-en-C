# 📚 Gestion des Files (Queue) en C + Tri

##  Description
Ce projet implémente une structure de données **File (Queue)** en langage C.

Il permet de :
- Créer une file
- Ajouter des éléments (Enfiler)
- Supprimer des éléments (Defiler)
- Afficher la file
- Trier les éléments en utilisant une logique avec plusieurs files

---

##  Fonctionnalités

-  Initialisation de la file
-  Enfiler (ajouter un élément)
-  Defiler (retirer un élément)
-  Affichage de la file
-  Recherche et retrait du maximum
-  Tri des éléments avec 3 files (F1, F2, F3)

---

##  Structure de données

```c
#define Max 100

typedef struct {
    int tab[Max];
    int ar;
} File;
