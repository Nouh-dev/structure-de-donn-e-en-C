#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
typedef struct{
    int tab[max];
    int sommet;
}Pile;

void initialiserPile(Pile *P){
    P->sommet=-1;
}

int PileVide(Pile P){
    return(P.sommet < 0 );
}

int PilePleine(Pile P){
    return(P.sommet >= max -1);
}

void PilePush(Pile *P, int e){
    if(!PilePleine(*P))
        P->tab[++P->sommet]= e ;
    else 
    printf("cette pile est pleine !!\n");
}

int PilePop(Pile *P){
    if(!PileVide(*P)){
        return(P->tab[P->sommet--]);
    }
 return -1;
}

int PileSommet(Pile P) {
    if (!PileVide(P)) {
        return (P.tab[P.sommet]);
    }
    return-1;
}
Pile P1,P2,P3;
 void PileAfficher(Pile P){
    if(PileVide(P)){
        printf("cette pile est vide ");
    return;
    }
    else{
    for(int i=P.sommet;i>=0;i--){
        printf("%d\n",P.tab[i]);
    }}
    printf("\n");
 }

void deplacer(){
    int x ;
    while(!PileVide(P1)){
            x=PilePop(&P1);
        if(x % 2 != 0 ){
            PilePush(&P2,x);
        }
        else
            PilePush(&P3,x);
     }
     while(!PileVide(P3)){
        PilePush(&P2,PilePop(&P3));
     }
}

int main (){
//initialisation 

initialiserPile(&P1);
initialiserPile(&P2);
initialiserPile(&P3);

// Remplissage de P1 : on insere {4, 1, 3, 6, 5}
// L’ordre de sortie sera : 5, 6, 3, 1, 4

PilePush(&P1,4);
PilePush(&P1,1);
PilePush(&P1,3);
PilePush(&P1,6);
PilePush(&P1,5);

//afichage

 printf("Affichage de P1 (Sommet vers Base) :\n");
 PileAfficher(P1);

 //deplacer

  printf("Deplacement des elements...\n");
  deplacer();

  //affichier P2

   printf("Contenu de P2 (Sommet vers Base) :\n");
   PileAfficher(P2);

return 0;

}