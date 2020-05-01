/*
Le module Manipulation contient les fonctions nécessaires à la manipulation
brute des données stockées dans la mémoire.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



int **CAlloTableau(int tx, int ty){
    /*Calloue dynamiquement un tableau à double entrée.
    La taille est en valeur numérale relative (la première case est 1;1).*/
    int **qr = calloc(tx, tx * sizeof(int*)), i=-1;
    while (++i < tx){
        qr[i] = calloc(ty, ty * sizeof(int)); }
    return qr;
}
int **MAlloTableau(int tx, int ty){
    /*Malloue dynamiquement un tableau à double entrée.
    La taille est en valeur numérale (la première case est 1;1).*/
    int **qr = malloc(tx * sizeof(int*)), i=-1;
    while (++i < tx){
        qr[i] = malloc(ty * sizeof(int)); }
    return qr;
}


int ***TripleMallo(){
    int ***trio = malloc(8 * sizeof(int**)), i=-1;
    while (++i < 8){
        trio[i] = MAlloTableau(21, 21);
    }
    return trio;
}




void TableauCopier(int **tab){
    int old_tab[21][21] = { {1, 1, 1, 1, 1, 1, 1, 3, 2, 0, 0, 0, 0, 3, 1, 1, 1, 1, 1, 1, 1},
                            {1, 3, 3, 3, 3, 3, 1, 3, 2, 0, 0, 0, 0, 3, 1, 3, 3, 3, 3, 3, 1},
                            {1, 3, 1, 1, 1, 3, 1, 3, 2, 0, 0, 0, 0, 3, 1, 3, 1, 1, 1, 3, 1},
                            {1, 3, 1, 1, 1, 3, 1, 3, 2, 0, 0, 0, 0, 3, 1, 3, 1, 1, 1, 3, 1},
                            {1, 3, 1, 1, 1, 3, 1, 3, 2, 0, 0, 0, 0, 3, 1, 3, 1, 1, 1, 3, 1},
                            {1, 3, 3, 3, 3, 3, 1, 3, 2, 0, 0, 0, 0, 3, 1, 3, 3, 3, 3, 3, 1},
                            {1, 1, 1, 1, 1, 1, 1, 3, 1, 3, 1, 3, 1, 3, 1, 1, 1, 1, 1, 1, 1},
                            {3, 3, 3, 3, 3, 3, 3, 3, 2, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3},
                            {2, 2, 2, 2, 2, 2, 1, 2, 2, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2},
                            {0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {3, 3, 3, 3, 3, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // dark module coord ([(1 * V) + 9], 8)
                            {1, 1, 1, 1, 1, 1, 1, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {1, 3, 3, 3, 3, 3, 1, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {1, 3, 1, 1, 1, 3, 1, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {1, 3, 1, 1, 1, 3, 1, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {1, 3, 1, 1, 1, 3, 1, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {1, 3, 3, 3, 3, 3, 1, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {1, 1, 1, 1, 1, 1, 1, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    int l,c;
    for (l=0 ; l<21 ; l++){
        for (c=0 ; c<21 ; c++){
            tab[c][l] = old_tab[l][c];
        }
    }
}


void reinitialisation(int **tab, int protection){
    /* initialisation change le numéro des cases pour l'application des masques*/
    int old_tab[21][21] = { {1, 1, 1, 1, 1, 1, 1, 3, 2, 0, 0, 0, 0, 3, 1, 1, 1, 1, 1, 1, 1},
                            {1, 3, 3, 3, 3, 3, 1, 3, 2, 0, 0, 0, 0, 3, 1, 3, 3, 3, 3, 3, 1},
                            {1, 3, 1, 1, 1, 3, 1, 3, 2, 0, 0, 0, 0, 3, 1, 3, 1, 1, 1, 3, 1},
                            {1, 3, 1, 1, 1, 3, 1, 3, 2, 0, 0, 0, 0, 3, 1, 3, 1, 1, 1, 3, 1},
                            {1, 3, 1, 1, 1, 3, 1, 3, 2, 0, 0, 0, 0, 3, 1, 3, 1, 1, 1, 3, 1},
                            {1, 3, 3, 3, 3, 3, 1, 3, 2, 0, 0, 0, 0, 3, 1, 3, 3, 3, 3, 3, 1},
                            {1, 1, 1, 1, 1, 1, 1, 3, 1, 3, 1, 3, 1, 3, 1, 1, 1, 1, 1, 1, 1},
                            {3, 3, 3, 3, 3, 3, 3, 3, 2, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3},
                            {2, 2, 2, 2, 2, 2, 1, 2, 2, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2},
                            {0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {3, 3, 3, 3, 3, 3, 3, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // dark module coord ([(1 * V) + 9], 8)
                            {1, 1, 1, 1, 1, 1, 1, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {1, 3, 3, 3, 3, 3, 1, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {1, 3, 1, 1, 1, 3, 1, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {1, 3, 1, 1, 1, 3, 1, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {1, 3, 1, 1, 1, 3, 1, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {1, 3, 3, 3, 3, 3, 1, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {1, 1, 1, 1, 1, 1, 1, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    int l,c;
    if (protection == 0){ //On applique les valeurs normales
        for (l=0 ; l<21 ; l++){
            for (c=0 ; c<21 ; c++){
                if (old_tab[c][l] == 3) tab[c][l] = 0; //zone blanche
                if (old_tab[c][l] == 1) tab[c][l] = 1; //les carrés de placement
                if (old_tab[c][l] == 4) tab[c][l] = 1; //dark module
            }
        }
    }
    if (protection == 1){ //On protège les cases
        for (l=0 ; l<21 ; l++){
            for (c=0 ; c<21 ; c++){
                if (old_tab[c][l] == 3) tab[c][l] = 3; //zone blanche
                if (old_tab[c][l] == 1) tab[c][l] = 5; //les modules de placement
                if (old_tab[c][l] == 4) tab[c][l] = 4; //le module sombre
            }
        }
    }
}


int data(int **qr, int tx, int ty, int *bin){
    /*Append les datas.
    tx : nombre de lignes en valeur réelle (C) et ty : nombre de colones en valeur réelle (C)
    OSQ les 0 et 1 sont dans un tableau d'entiers qui est de la bonne taille.
    Suppose que les tailles sont respectées.*/
    int descendre=0, i=0, largeur = tx, hauteur = ty;
    
    while (largeur>0){
        while (!descendre){
            qr[largeur][hauteur] = bin[i]; i++;
            largeur--;
            qr[largeur][hauteur] = bin[i]; i++;
            if (hauteur == 0) { //test de hauteur hors-limite
                descendre++; largeur--; }
            else { //autres tests
                if (qr[largeur][hauteur-1] == 2 && qr[largeur+1][hauteur-1] == 2) { //test de la zone 2 en montée
                    largeur--;
                    descendre++; }
                else {
                    if (qr[largeur][hauteur-1] == 3 && qr[largeur+1][hauteur-1] == 1) { //test de la zone 31 en montée
                        largeur++ ; hauteur-=2; }
                    else { largeur++; hauteur--; } //tout va bien
                }
            }
        }

        if (qr[largeur][hauteur] == 3 && qr[largeur][hauteur-1] == 1) largeur--; //test de la zone 31 verticale après la montée
        
        while (descendre){
            qr[largeur][hauteur] = bin[i]; i++;
            largeur--;
            qr[largeur][hauteur] = bin[i]; i++;
            
            if (hauteur == tx){ //test de hauteur hors-limite
                descendre--; largeur--; }
            else { //autres tests
                if (qr[largeur][hauteur+1] == 3 && qr[largeur+1][hauteur+1] == 3){ //test de la zone 3 en descente
                    if (!largeur) return 0;
                    largeur--;
                    descendre--; }
                else {
                    if (qr[largeur][hauteur+1] == 3 && qr[largeur+1][hauteur+1] == 1){ //test de la zone 31 en descente
                        largeur++; hauteur+=2;
                    }
                    else { largeur++; hauteur++; } //tout va bien
                }
            }
        }

        if (qr[largeur][hauteur] == 2 && qr[largeur][hauteur-1] == 2) hauteur-=8; //test de la zone 31 verticale après la montée
    }
    return 0;
}


int **copieqr(int **qr, int c, int l){
    int **qr2 = MAlloTableau(21,21), i, j;
    for (i=0 ; i<l ; i++){
        for (j=0 ; j<c ; j++){
            qr2[i][j] = qr[i][j];
        }
    }
    return qr2;
}


int ***triple_copie(int ***trio, int **qr){
    int i;
    for (i=0 ; i<8 ; i++){
        trio[i] = copieqr(qr, 21, 21);
    }
    return trio;
}

