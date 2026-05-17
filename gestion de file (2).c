#include <stdio.h>
#include <stdlib.h>

#define Max 100

typedef struct{
    int tab[Max];
    int ar;
} File;

/* initialiser */
void initialiserFile(File *F){
    F->ar = -1;
}

/* verifier vide */
int FileVide(File F){
    return (F.ar < 0);
}

/* verifier pleine */
int FilePleine(File F){
    return (F.ar >= Max-1);
}

/* Enfiler */
void Enfiler(File *F , int e ){
    if(!FilePleine(*F)){
        F->ar++;
        F->tab[F->ar] = e;
    }
    else{
        printf("Erreur : file pleine\n");
    }
}

/* Defiler */
int Defiler(File *F){
    if(!FileVide(*F)){
        int x = F->tab[F->ar];
        F->ar--;
        return x;
    }
    printf("File vide\n");
    return -1;
}

/* afficher file */
void FileAfficher(File F){
    if(FileVide(F)){
        printf("Cette file est vide\n");
        return;
    }

    for(int i = 0 ; i <= F.ar ; i++){
        printf("%d\n",F.tab[i]);
    }

    printf("\n");
}

/* retirer max */
int Retire_Max(File *F1,File *F2){
    int max , x;
    int n = F1->ar + 1;

    if(FileVide(*F1))
        return -1;

    max = Defiler(F1);

    for(int i=1;i<n;i++){
        x = Defiler(F1);

        if(x > max){
            Enfiler(F2,max);
            max = x;
        }
        else{
            Enfiler(F2,x);
        }
    }

    /* retourner elements vers F1 */
    while(!FileVide(*F2)){
        Enfiler(F1,Defiler(F2));
    }

    return max;
}

/* tri */
void Trier(File *F1 ,File *F2 ,File *F3){

    while(!FileVide(*F1)){
        int x = Retire_Max(F1,F2);
        Enfiler(F3 , x);
    }
}

int main(){

File F1 , F2 , F3;

/* initialisation */
initialiserFile(&F1);
initialiserFile(&F2);
initialiserFile(&F3);

/* remplissage */
Enfiler(&F1,4);
Enfiler(&F1,1);
Enfiler(&F1,3);
Enfiler(&F1,6);
Enfiler(&F1,5);

/* affichage */
printf("Affichage de F1 :\n");
FileAfficher(F1);

/* tri */
printf("Tri des elements...\n");
Trier(&F1,&F2,&F3);

/* affichage resultat */
printf("Contenu de F3 :\n");
FileAfficher(F3);

return 0;
}
