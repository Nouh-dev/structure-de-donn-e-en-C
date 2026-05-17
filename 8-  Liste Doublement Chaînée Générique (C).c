#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Element_liste{
    char *info ;
    struct Element_liste *precedent ;
    struct Element_liste *suivant ;
}Element ;

typedef struct {
    Element *Debut ;
    Element *Fin ;
    int Taille ;
}Liste;

void initialiser(Liste *L){
    L->Debut =NULL;
    L->Fin =NULL;
    L->Taille =0;
}

int insertion_vide(Liste *L ,char *info ){
    Element *nouveau;
    nouveau = (Element * ) malloc(sizeof(Element));
    if(nouveau == NULL ) return -1;
    nouveau->info= (char *) malloc(strlen(info)+1);
    strcpy(nouveau->info,info);
    nouveau->precedent = NULL; 
    nouveau->suivant = NULL ; 
    L->Debut = nouveau ;
    L->Fin = nouveau ;
    L->Taille++;
    return 0; 
}

int insertion_debut(Liste *L ,char *info ){
    Element *nouveau;
    nouveau = (Element * ) malloc(sizeof(Element));
    if(nouveau == NULL ) return -1;
    nouveau->info= (char *) malloc(strlen(info)+1);
    strcpy(nouveau->info,info);
    nouveau->precedent = NULL; 
    nouveau->suivant =L->Debut ; 
    L-> Debut -> precedent = nouveau ; 
    L->Debut = nouveau ;
    L->Taille++;
    return 0; 
}

int insertion_Fin(Liste *L ,char *info ){
    Element *nouveau;
    nouveau = (Element * ) malloc(sizeof(Element));
    if(nouveau == NULL ) return -1;
    nouveau->info= (char *) malloc(strlen(info)+1);
    strcpy(nouveau->info,info);
    nouveau->precedent =L->Fin; 
    nouveau->suivant = NULL ; 
    L->Fin ->suivant = nouveau ;
    L->Fin = nouveau;
    L->Taille++;
    return 0; 
}

int insertion_apres(Liste *L ,char *info , int pos ){
    Element *nouveau;
    Element *courant;
    nouveau = (Element * ) malloc(sizeof(Element));
    if(nouveau == NULL ) return -1;
    nouveau->info= (char *) malloc(strlen(info)+1);
    courant = L->Debut ;
    for(int i = 1 ; i < pos ; i++){
        courant = courant -> suivant ;
    }
    nouveau ->suivant = courant->suivant ;
    nouveau ->precedent = courant ;
    if(courant -> suivant == NULL ) L->Fin = nouveau ;
    courant->precedent->suivant = nouveau;
    courant ->precedent = nouveau ;
    L->Taille++;
    return 0; 
}

int insertion_avant (Liste *L ,char *info , int pos ){
    Element *nouveau;
    Element *courant;
    nouveau = (Element * ) malloc(sizeof(Element));
    if(nouveau == NULL ) return -1;
    nouveau->info= (char *) malloc(strlen(info)+1);
    courant = L->debut ;
    for(int i = 1 ; i < pos ; i++){
        courant = courant -> suivant;
    }
    nouveau ->suivant = courant ;
    nouveau ->precedent = courant->precedent ;
    if(courant -> precedent == NULL ) L->Debut = nouveau ; 
    courant->suivant ->precedent = nouveau;
    courant ->suivant = nouveau ;
    L->Taille++;
    return 0; 
}

int Supprimer(int pos) {
int i; Element *supp_element,*courant;
if(Taille == 0) return -1;
if(pos == 1) { /* suppression de 1er élément */
supp_element = Debut;
Debut = Debut->suivant;
if(Debut == NULL) Fin = NULL;
else Debut->precedent = NULL;
}
else if(pos == Taille) { /* suppression du dernier élément */
supp_element = Fin;
Fin->precedent->suivant = NULL;
Fin = Fin->precedent;
} 
else { /* suppression ailleurs */
courant = Debut;
for(i=1;i<pos;++i) courant = courant->suivant;
supp_element = courant;
courant->precedent->suivant = courant->suivant;
courant->suivant->precedent = courant->precedent;
}
free(supp_element->info);
free(supp_element);
Taille--;
return 0;
}

Afficher_Liste() { /* affichage en avançant */
Element *courant;
courant = Debut; /* point du départ le 1er élément */
printf("[");
while(courant != NULL) {
printf("%s ", courant->info);
courant = courant->suivant;
}
printf("]\n");
}

Detruire () {
while (Taille > 0) Supprimer(1) ;
}

