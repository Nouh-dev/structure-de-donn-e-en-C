// Dans ce TP, nous avons étudié la structure de données Liste doublement chainée.L’objectif est représenter les informations des étudiants de SIR et GI
//  En déclare les bibliotique
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// structure de donnée pour déclarer les informations d'etudiant et deux pointure (suivant,precedent)
typedef struct etudiant
{
    int apogee;
    char nom[20];
    char prenom[20];
    char filiere[20];
    struct etudiant *precedent;
    struct etudiant *suivant;
} Etudiant;

// déclaration les variables globale,on ne fait pas structure car on utilise un seul liste
Etudiant *Debut;
Etudiant *Fin;
int Taille;

// cette fonction pour initialiser dans une liste , le debut = NULL, Fin = NULL et la taille = 0
void initialiser()
{
    Debut = NULL;
    Fin = NULL;
    Taille = 0;
}

// cette fonction pour cree un etudiant dans un liste. On déclare une nouveau de type element après on fait mallocation de cette nouveau et les informations puis on stocké cette informations dans cette noeud aprés pointer le precedent et suivant de noeud par NULL et finallement return cette noeud
Etudiant *creer_noeud(int apo, char *nm, char *pr, char *fil)
{
    Etudiant *nouveau;
    nouveau = (Etudiant *)malloc(sizeof(Etudiant));
    if (nouveau == NULL)
        return NULL;

    strcpy(nouveau->nom, nm);
    strcpy(nouveau->prenom, pr);
    strcpy(nouveau->filiere, fil);

    nouveau->apogee = apo;
    nouveau->suivant = NULL;
    nouveau->precedent = NULL;
    return nouveau;
}

// cette fonction pour insérer cette etudiant dans le vide de la liste, on fait un conition pour savoi est ce que le noeud et NULL et on met le debutet la fin das cette noeud puis incrémenter la liste
void inserer_liste_vide(Etudiant *E)
{
    if (E == NULL)
        return;
    Debut = E;
    Fin = E;
    Taille++;
}

// cette fonction pour insérer cette etudiant dans le debut de la liste et on va pointer E->suivant par le debut et E->precedent par NULL puis pointer debut precedent par E aprés en deplacer le debut par nouveau element et finallement incrémenter la liste
void inserer_debut(Etudiant *E)
{
    if (E == NULL)
        return;

    if (Debut == NULL)
        inserer_liste_vide(E);
    else
    {
        E->precedent = NULL;
        E->suivant = Debut;
        Debut->precedent = E;
        Debut = E;
        Taille++;
    }
}

// cette fonction pour insérer à la fin , on fait une teste pour le noeud si NULL return, après en test si la fin est NULL utuliser la fonction insérer dans le vide sinon en pointer E->suivant par NULL et precedent par la fin et la fin par nouveau noeud (E) et mettre fin dans (E) puis incrémenter la liste
void inserer_fin(Etudiant *E)
{
    if (E == NULL)
        return;

    if (Fin == NULL)
        inserer_liste_vide(E);
    else
    {
        E->suivant = NULL;
        E->precedent = Fin;
        Fin->suivant = E;
        Fin = E;
        Taille++;
    }
}

int supprimer_noeud(int pos)
{
    Etudiant *courant, *sup_element;
    if (Taille == 0)
        return -1;
    if (pos < 1 || pos > Taille)
        return -1;

    // suppression de 1er élément : en mettre sup_element dans le debut et deplacer le debut à l'element suivant aprés faire une condition si debut = NULL donc fin = NULL sinon pointer le debut precedent par NULL
    if (pos == 1)
    {
        sup_element = Debut;
        Debut = Debut->suivant;
        if (Debut == NULL)
            Fin = NULL;
        else
            Debut->precedent = NULL;
    }

    // suppression du dernier élément : en mettre sup_element dans la fin et deplacer la fin à l'element precedent aprés faire une condition si fin = NULL donc debut = NULL sinon , fin suivant = NULL
    else if (pos == Taille)
    {
        sup_element = Fin;
        Fin = Fin->precedent;
        if (Fin == NULL)
            Debut = NULL;
        else
            Fin->suivant = NULL;
    }

    // suppression ailleurs : en declarer une courant et on met dans le debut puis faire une boucle  que deplace courant jusqu'à position aprés pointer les elements entre eux et finallement supprimer cette element par free
    else
    {
        courant = Debut;
        for (int i = 1; i < pos; i++)
            courant = courant->suivant;
        sup_element = courant;
        courant->precedent->suivant = courant->suivant;
        courant->suivant->precedent = courant->precedent;
    }

    free(sup_element);
    Taille--;
    return 0;
}
// cette fonction pour affichier une liste, en declare une pointure courant et on mets courant dans le debut et affichier le contenut d'un element et déplacer par suivant element, (%-10s) en fait ças pour donne une bonne affichage
void afficher_liste()
{
    Etudiant *courant;
    courant = Debut;
    printf("\n----------------------------------------------------\n");
    while (courant != NULL)
    {
        printf("%-15s %-15s %-10s %-5d\n", courant->nom, courant->prenom, courant->filiere, courant->apogee);
        courant = courant->suivant;
    }
}

// cette fonction pour vider une liste , on fait une boucle qui supprimer le debut
void detruire_liste()
{
    while (Taille > 0)
        supprimer_noeud(1);
}
// cette fonction pour construire une liste , en faire une boucle pour saisir les informations d'un étudiant puis crée cette element aprés faire une codition si filière SIR inséré à la fin si GI insérer debut
void construire_liste()
{
    int n, apo;
    char nom[20], prenom[20], filiere[20];

    printf("Combien d'etudiants ? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\n--- Etudiant %d ---\n", i + 1);

        printf("Apogee: ");
        scanf("%d", &apo);

        printf("Nom: ");
        scanf("%s", nom);

        printf("Prenom: ");
        scanf("%s", prenom);

        printf("Filiere (SIR/GI): ");
        scanf("%s", filiere);

        Etudiant *E = creer_noeud(apo, nom, prenom, filiere);

        if (Taille == 0)
            inserer_liste_vide(E);
        else
        {
            if (strcmp(filiere, "SIR") == 0 || strcmp(filiere, "sir") == 0)
                inserer_fin(E);
            else
                inserer_debut(E);
        }
    }
}

// en declarer 3 variable ,A pour le nombr d'etudiant SIR et B pour GI, et onfait une boucle pour tester et incrémenter soit A ou B et affichier A et B
void statistiques()
{
    int A, B;
    A = 0, B = 0;
    Etudiant *courant;
    courant = Debut;
    while (courant != NULL)
    {
        if (strcmp(courant->filiere, "SIR") == 0)
            A++;
        else if (strcmp(courant->filiere, "GI") == 0)
            B++;
        courant = courant->suivant;
    }
    printf("\n---------------les statistique----------------------\n");
    printf("\nle nombre des etudiants dans le filiere SIR : %d\n", A);
    printf("le nombre des etudiants dans le filiere GI : %d\n", B);
}

// cette fonction pour echanger le contenu de deux element par une 3ème variable et strcpy pour copy chaine de character
void echange_etudiant(Etudiant *E1, Etudiant *E2)
{
    char temp_nom[20], temp_prenom[20];
    char temp_filiere[5];
    // echange nom
    strcpy(temp_nom, E1->nom);
    strcpy(E1->nom, E2->nom);
    strcpy(E2->nom, temp_nom);
    // echange prenom
    strcpy(temp_prenom, E1->prenom);
    strcpy(E1->prenom, E2->prenom);
    strcpy(E2->prenom, temp_prenom);
    // echange filière
    strcpy(temp_filiere, E1->filiere);
    strcpy(E1->filiere, E2->filiere);
    strcpy(E2->filiere, temp_filiere);
}

// cette fonction est trier une liste par ordre decroissante de nom, on fait une boucle qui compare les nom et echanger les etudiants
void trier_liste()
{
    Etudiant *E1, *E2;
    for (E1 = Debut; E1 != NULL; E1 = E1->suivant)
    {
        for (E2 = E1->suivant; E2 != NULL; E2 = E2->suivant)
        {
            if (strcmp(E1->nom, E2->nom) > 0)
                echange_etudiant(E1, E2);
        }
    }
}

// en faire une boucle pour tester filiere puis on utilise fonction supprimer_noeud aprés deplacer courant
void supprimer_SIR()
{
    Etudiant *courant = Debut;
    int pos = 1;

    while (courant != NULL)
    {

        if (strcmp(courant->filiere, "SIR") == 0)
        {
            courant = courant->suivant;
            supprimer_noeud(pos);
        }

        else
        {
            courant = courant->suivant;
            pos++;
        }
    }
    printf("\n==============les etudiants de GI===================");
}

// on declarer les fonctions dans la fonction int main
int main()
{
    initialiser();
    construire_liste();
    afficher_liste();
    trier_liste();
    afficher_liste();
    statistiques();
    supprimer_SIR();
    afficher_liste();
    detruire_liste();
    return 0;
}
