// Dans ce TP, nous avons étudié la structure de données Liste simplement chainée.L’objectif estreprésenter les informations des étudiants d’une classe
//  En déclare les bibliotique
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure de donnée pour déclarer les informations d'etudiant
typedef struct etudiant
{
    char *Nom;
    char *Prenom;
    float Note;
    struct etudiant *suivant;
} Etudiant;

// structure pou déclarer les variables globale et on fait comme structure car cette exercice aider plusieur (LSC)
typedef struct
{
    Etudiant *Debut;
    int nbr_etudiant;
} Liste;

// cette fonction pour initialiser dans une liste, le debut = NULL et la taille = 0.
void initialisation(Liste *L)
{
    L->Debut = NULL;
    L->nbr_etudiant = 0;
}

// cette fonction pour cree un etudiant dans un liste. On déclare une nouveau de type element après on fait mallocation de cette nouveau et les informations et on stocké cette informations dans cette noeud.
Etudiant *cree_noeud(char *Last, char *First, float Nt)
{
    Etudiant *Nouveau;

    Nouveau = (Etudiant *)malloc(sizeof(Etudiant));
    if (Nouveau == NULL)
        return NULL;

    Nouveau->Nom = (char *)malloc(50 * sizeof(char));
    Nouveau->Prenom = (char *)malloc(50 * sizeof(char));

    strcpy(Nouveau->Nom, Last);
    strcpy(Nouveau->Prenom, First);

    Nouveau->Note = Nt;
    Nouveau->suivant = NULL;

    return Nouveau;
}

// cette fonction pour insérer cette etudiant dans le debut de la liste et on va pointer E par le debut et en deplacer le debut par nouveau element et finallement incrémenter la liste .
int inserer_Debut(Liste *L, Etudiant *E)
{
    if (E == NULL)
        return 0;

    E->suivant = L->Debut;
    L->Debut = E;

    L->nbr_etudiant++;

    return 1;
}

// cette fonction pour insérer à la fin , on fait une teste pour le noeud si NULL et après en test si le debut est NULL utuliser la fonction insérer dans le debut sinon en declare une pointure courant et o fait une boucle pour deplacer cette courant a la fin et insérer cette noeud apres pointe element dans le courant à nouveau noeud et incrémenter la liste.
int inserer_fin(Liste *L, Etudiant *E)
{
    if (E == NULL)
        return 0;
    if (L->Debut == NULL)
    {
        return inserer_Debut(L, E);
    }
    else
    {
        Etudiant *courant;
        courant = L->Debut;
        while (courant->suivant != NULL)
        {
            courant = courant->suivant;
        }
        courant->suivant = E;
        L->nbr_etudiant++;
        return 1;
    }
}

// cette fonction pour affichier une liste, en declare une pointure courant et en tester si le debut est NULL donc ecrire "Liste vide" sinon on mets courant dans le debut et affichier le contenut d'un element et déplacer par suivant element, (%-10s) en fait cas pour donne une bonne affichage .
void afficher_liste(Liste L)
{
    Etudiant *courant;

    if (L.Debut == NULL)
        printf("Liste vide\n");
    else
    {
        courant = L.Debut;
        printf("\t=======Liste des etudiants =======\n");
        printf("\t    Nom:      |   Prenom:        |  Note: \n");
        while (courant != NULL)
        {
            printf("\t  %-10s  |    %-10s    |  %-5.2f \n  ",
                   courant->Nom,
                   courant->Prenom,
                   courant->Note);

            courant = courant->suivant;
        }
    }
    printf("\n");
}

// cette fonctions pour supprimer le debut d'un liste, on déclare une variable sup_element et on mets à debut après en change debut à l'element suivant et supprimer la premier element dans une liste.
int supprimer_debut(Liste *L)
{
    Etudiant *sup_element;
    if (L->nbr_etudiant == 0)
        return -1;
    sup_element = L->Debut;
    L->Debut = L->Debut->suivant;
    if (L->nbr_etudiant == 1)
        L->Debut = NULL;
    free(sup_element);
    return 0;
}

// cette fonction pour vider une liste , on fait une boucle et déclarer dans le boucle la fonction supprimer_debut jusqu'a debut = NULL .
void suprimer_liste(Liste *L)
{
    while (L->Debut != NULL)
        supprimer_debut(L);
}

// cette fonction pour diviser la liste principale à 2 liste si liste principale est vide ecrire "la liste est vide" sino en fait une pointure courant sur debut et crée un noveau element et tester si note < 10 insérer dans liste 1 sinon insérer dans la 2ème liste et aprés on deplace le courant dans l'element suivant.
void Diviser_Liste(Liste L, Liste *L1, Liste *L2)
{
    Etudiant *s, *p;
    p = L.Debut;
    if (p == NULL)
        printf("la liste est vide ! \n");
    else
    {
        while (p != NULL)
        {
            s = cree_noeud(p->Nom, p->Prenom, p->Note);
            if (p->Note >= 10)
                inserer_Debut(L1, s);
            else
                inserer_Debut(L2, s);
            p = p->suivant;
        }
    }
}

// cette fonction et echange les information d'un etudiant avec autre
void echange_etudiant(Etudiant *E1, Etudiant *E2)
{
    char temp_nom[20], temp_prenom[20];
    float temp_note;
    // echange nom
    strcpy(temp_nom, E1->Nom);
    strcpy(E1->Nom, E2->Nom);
    strcpy(E2->Nom, temp_nom);
    // echange prenom
    strcpy(temp_prenom, E1->Prenom);
    strcpy(E1->Prenom, E2->Prenom);
    strcpy(E2->Prenom, temp_prenom);
    // echange note
    temp_note = E1->Note;
    E1->Note = E2->Note;
    E2->Note = temp_note;
}

// cette fonction est trier une liste par ordre decroissante de note, on fait 2 boucle, la premier boucle est commancer par le debut et la deuxieme  par le suivant de element 1 .
void trier_etudiant(Liste *L)
{
    Etudiant *E1, *E2;
    for (E1 = L->Debut; E1 != NULL; E1 = E1->suivant)
    {
        for (E2 = E1->suivant; E2 != NULL; E2 = E2->suivant)
        {
            if (E1->Note < E2->Note)
            {
                echange_etudiant(E1, E2);
            }
        }
    }
}
// on declarer les fonctions dans la fonction int main
int main()
{

    Liste classe;
    initialisation(&classe);
    Liste Valide;
    initialisation(&Valide);
    Liste NValide;
    initialisation(&NValide);

    Etudiant *e1, *e2, *e3, *e4, *e5;

    e1 = cree_noeud("Marzak", "Nouh", 20);
    e2 = cree_noeud("zaki", "Zaki", 1);
    e3 = cree_noeud("Agnaoui", "Ali", 2);
    e4 = cree_noeud("youssef", "youseef", 3);
    e5 = cree_noeud("amine", "jemaoui", 10);

    inserer_Debut(&classe, e1);
    inserer_Debut(&classe, e2);
    inserer_Debut(&classe, e3);
    inserer_fin(&classe, e5);
    inserer_fin(&classe, e4);

    afficher_liste(classe);
    trier_etudiant(&classe);
    trier_etudiant(&NValide);
    afficher_liste(classe);
    Diviser_Liste(classe, &Valide, &NValide);
    afficher_liste(Valide);
    supprimer_debut(&Valide);
    afficher_liste(NValide);
    afficher_liste(Valide);
    suprimer_liste(&NValide);
    afficher_liste(NValide);

    return 0;
}