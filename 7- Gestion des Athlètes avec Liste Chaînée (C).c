#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int temps;
    char distance[10];
    char termine[5];
} score;

typedef struct athlete
{
    int Code;
    char *Nomcomplet;
    char *Datenaissance;
    score comp;
    struct athlete *suivant;
} Noeud;

typedef struct
{
    Noeud *debut;
    int taille;
} liste;

void initialisation(liste *L)
{
    L->debut = NULL;
    L->taille = 0;
}

Noeud *cree_noeud(int code, char nom[50], char dNaiss[20], int time, char dist[10], char term[5])
{
    Noeud *nouveau = (Noeud *)malloc(sizeof(Noeud));
    if (nouveau == NULL)
        return NULL;

    nouveau->Nomcomplet = (char *)malloc(strlen(nom) + 1);
    nouveau->Datenaissance = (char *)malloc(strlen(dNaiss) + 1);

    strcpy(nouveau->Nomcomplet, nom);
    strcpy(nouveau->Datenaissance, dNaiss);

    nouveau->Code = code;
    nouveau->comp.temps = time;
    strcpy(nouveau->comp.distance, dist);
    strcpy(nouveau->comp.termine, term);

    nouveau->suivant = NULL;
    return nouveau;
}

int inserer_fin(liste *L, Noeud *A)
{
    if (A == NULL)
        return -1;

    if (L->debut == NULL)
    {
        L->debut = A;
    }
    else
    {
        Noeud *courant = L->debut;
        while (courant->suivant != NULL)
            courant = courant->suivant;

        courant->suivant = A;
    }

    L->taille++;
    return 0;
}

void affichier(liste L)
{
    Noeud *courant = L.debut;

    printf("Code | Nom | Date | Termine | Distance | Temps\n");

    while (courant != NULL)
    {
        printf("%d | %s | %s | %s | %s | %d\n",
               courant->Code,
               courant->Nomcomplet,
               courant->Datenaissance,
               courant->comp.termine,
               courant->comp.distance,
               courant->comp.temps);

        courant = courant->suivant;
    }
}

int supp_non_termine(liste *L)
{
    Noeud *courant = L->debut;
    Noeud *precedent = NULL;

    while (courant != NULL)
    {
        if (strcmp(courant->comp.termine, "non") == 0 ||
            strcmp(courant->comp.termine, "NON") == 0)
        {
            Noeud *supp = courant;

            if (precedent == NULL)
            {
                L->debut = courant->suivant;
                courant = L->debut;
            }
            else
            {
                precedent->suivant = courant->suivant;
                courant = courant->suivant;
            }

            free(supp->Nomcomplet);
            free(supp->Datenaissance);
            free(supp);

            L->taille--;
        }
        else
        {
            precedent = courant;
            courant = courant->suivant;
        }
    }

    return 0;
}

int diviser_deux_liste(liste L, liste *L400, liste *L3000)
{
    Noeud *courant = L.debut;

    while (courant != NULL)
    {
        Noeud *s = cree_noeud(courant->Code,
                              courant->Nomcomplet,
                              courant->Datenaissance,
                              courant->comp.temps,
                              courant->comp.distance,
                              courant->comp.termine);

        if (strcmp(courant->comp.distance, "400") == 0)
            inserer_fin(L400, s);
        else
            inserer_fin(L3000, s);

        courant = courant->suivant;
    }

    return 0;
}

int main()
{
    liste L, L400, L3000;
    initialisation(&L);
    initialisation(&L400);
    initialisation(&L3000);

    int n;
    printf("Combien des athletes ??\n");
    scanf("%d", &n);

    int code, time;
    char nom[50], dnaisss[20], dist[10], term[5];

    for (int i = 0; i < n; i++)
    {
        printf("Code : ");
        scanf("%d", &code);

        printf("Nom et Prenom : ");
        scanf("%s", nom);

        printf("Date naissance : ");
        scanf("%s", dnaisss);

        printf("Temps : ");
        scanf("%d", &time);

        printf("Distance : ");
        scanf("%s", dist);

        printf("Termine (oui/non) : ");
        scanf("%s", term);

        Noeud *s = cree_noeud(code, nom, dnaisss, time, dist, term);
        inserer_fin(&L, s);
    }

    printf("\n--- Tous les athletes ---\n");
    affichier(L);

    diviser_deux_liste(L, &L400, &L3000);

    printf("\n--- 400 m ---\n");
    affichier(L400);

    printf("\n--- 3000 m ---\n");
    affichier(L3000);

    supp_non_termine(&L);

    printf("\n--- Athletes termines ---\n");
    affichier(L);

    return 0;
}
