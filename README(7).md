#  Gestion des Athlètes avec Liste Chaînée (C)

##  Description
Ce projet implémente une **liste simplement chaînée** en langage C pour gérer des athlètes et leurs performances sportives.

Chaque athlète contient :
- Code
- Nom complet
- Date de naissance
- Résultats de compétition (temps, distance, statut terminé)

---

##  Fonctionnalités

-  Ajouter des athlètes
-  Afficher la liste des athlètes
-  Diviser la liste selon la distance (400m / 3000m)
-  Supprimer les athlètes non terminés
-  Gestion dynamique de mémoire
-  Copie des éléments entre listes

---

##  Structure de données

### Score

```c
typedef struct {
    int temps;
    char distance[10];
    char termine[5];
} score;
