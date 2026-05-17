#  Manipulation des Grands Nombres avec Pile Dynamique (C)

##  Description
Ce projet implémente une **pile dynamique (stack)** en langage C pour représenter et manipuler des **grands nombres**.

Chaque nombre est découpé en blocs de 4 chiffres appelés **paquets**, stockés dans une pile.

---

##  Fonctionnalités

-  Création d’une pile dynamique
-  Empiler des paquets de chiffres
-  Dépiler des éléments
-  Vider une pile
-  Conversion d’une chaîne en pile (paquets de 4 chiffres)
-  Addition de deux grands nombres
-  Affichage d’un grand nombre correctement formaté

---

##  Structure de données

### Élément de pile

```c
typedef struct ElementPile {
    int Paquet;
    struct ElementPile *Precedent;
} Element;
