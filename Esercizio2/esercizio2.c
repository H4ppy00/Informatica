/*Esercizio 2
Un file contiene una matrice di R × C numeri interi con R e C noti a priori (#define), separati da
spazi. Determinare il valore più piccolo tra tutte le celle e stampare a video le coordinate (r, c) delle
celle con valori maggiori o uguali al 110% di questo valore. */

#include <stdio.h>
#include <stdlib.h>
#define R 4
#define C 4

int main ()   {
FILE *fp;
int i,j, min, uguale;
float min_110;
char nomefile[50];
int matrice[R][C];
//printf("Inserisci il nome del file:");
//scanf("%s",nomefile);

fp = fopen("matrice3.txt","r");
if (fp == NULL) {
    printf("ERRORE: file non trovato.\n");
    return -1;
}
printf("File aperto correttamente.\n");

for(i=0;i<R;i++){
    for(j=0;j<C;j++){
        fscanf(fp,"%d",&matrice[i][j]);
        printf("%d ",matrice[i][j]);
    }
    printf("\n");
}
fclose(fp);
min= matrice[0][0];
for(i=0;i<R;i++){
    for(j=0;j<C;j++){
        if(matrice[i][j]< min){
            min = matrice[i][j];
        }
    }
}
min_110 = min * 1.10;
printf("valore minimo e' [%d].Il 110 del valore minimo e' %.2f\n", min, min_110);

for(i=0;i<R;i++){
    for(j=0;j<C;j++){
        if(matrice[i][j] >= min_110){
            printf("coord. val. maggiore/uguale. di %.2f : [%d] [%d]\n", min_110, i,j);
        }
    }
}

return 0;
}


