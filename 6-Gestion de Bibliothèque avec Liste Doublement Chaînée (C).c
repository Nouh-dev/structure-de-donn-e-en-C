#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct livre
{
    int cote;
    char *titre;
    char *auteur;
    char *discipline;
    char *editeur;
    int nbrexemplaires;
} Livre;

typedef struct element
{
    Livre data;
    struct element *suivant;
    struct element *precedent;
} Element;

Element *debut;
Element *fin;
int taille;

void initialiser()
{
    debut = NULL;
    fin = NULL;
    taille = 0;
}

Element *allocation_noeud(int code, char titree[40], char auteure[20], char disciplinee[20], char editeure[20], int Nexemplaires)
{
    Element *nouveau;
    nouveau = (Element *)malloc(sizeof(Element));
    if (nouveau == NULL)
        return NULL;

    nouveau->data.titre = (char *)malloc(strlen(titree) + 1);
    nouveau->data.auteur = (char *)malloc(strlen(auteure) + 1);
    nouveau->data.discipline = (char *)malloc(strlen(disciplinee) + 1);
    nouveau->data.editeur = (char *)malloc(strlen(editeure) + 1);

    nouveau->data.cote = code;
    strcpy(nouveau->data.titre, titree);
    strcpy(nouveau->data.auteur, auteure);
    strcpy(nouveau->data.discipline, disciplinee);
    strcpy(nouveau->data.editeur, editeure);
    nouveau->data.nbrexemplaires = Nexemplaires;

    nouveau->suivant = NULL;
    nouveau->precedent = NULL;
    return nouveau;
}

int ajouter_livre(Element *L)
{
    if (L == NULL)
        return -1;
    if (debut == NULL)
    {
        debut = L;
        fin = L;
    }
    else
    {
        Element *courant;
        courant = debut;
        while (courant != NULL)
        {
            if (L->data.cote == courant->data.cote)
                L->data.nbrexemplaires++;
            courant = courant->suivant;
        }
        L->suivant = debut;
        debut = L;
        taille++;
        return 0;
    }
}
