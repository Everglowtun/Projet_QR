/*
Le module Masking contient les fonctions nécessaires à l'application
des masques sur le code.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "manipulation.c"

/********** Fonctions préliminaires **********/


int inverse(int bin){
    if (bin == 0) return 1;
    if (bin == 1) return 0;
    return bin;
}


void infotext(int **qr, int masque){
    /* La fonction infotext applique les informations de la version 
    de masque en argument sur le code passé en argument.
    infotext suppose que le QR est de la plus petite taille.*/

    int text[][15] =   {{1,0,1,0,1,0,0,0,0,0,1,0,0,1,0},  //masque 1
                        {1,0,1,0,0,0,1,0,0,1,0,0,1,0,1},  //masque 2
                        {1,0,1,1,1,1,0,0,1,1,1,1,1,0,0},  //masque 3
                        {1,0,1,1,0,1,1,0,1,0,0,1,0,1,1},  //masque 4
                        {1,0,0,0,1,0,1,1,1,1,1,1,0,0,1},  //masque 5
                        {1,0,0,0,0,0,0,1,1,0,0,1,1,1,0},  //masque 6
                        {1,0,0,1,1,1,1,1,0,0,1,0,1,1,1},  //masque 7
                        {1,0,0,1,0,1,0,1,0,1,0,0,0,0,0}}; //masque 8
    int i;
    for (i=0 ; i<6 ; i++){
        qr[i][8] = text[masque][i];
        qr[8][20-i] = text[masque][i];
    }
    //i=6
    qr[i+1][8] = text[masque][i];
    qr[8][20-i] = text[masque][i];
    i++; //i=7
    qr[i+1][8] = text[masque][i];
    qr[13][8] = text[masque][i];
    i++; //i=8
    qr[8][7] = text[masque][i];
    qr[14][8] = text[masque][i];
    i++;
    for (i=9 ; i<15 ; i++){
        qr[8][14-i] = text[masque][i];
        qr[6+i][8] = text[masque][i];
    }

}


int meilleure_somme(int *tab){
    int s=0, i;
    for (i=0 ; i<8 ; i++){
        if (tab[i] < tab[s]) s = i;
    }
    return s;
}


/********** Application des masques **********/


int ApplicationMasqueZero(int **qr, int i, int j){
    int l, c;
    for (l=0 ; l<j ; l++){
        for (c=0 ; c<i ; c++){
            if (qr[c][l] == 0 || qr[c][l] == 1){
                if (((l+c) % 2) == 0){ //(row + column) mod 2 == 0
                    qr[c][l] = inverse(qr[c][l]);
                }
            }
        }
    }
    return 0;
}

int ApplicationMasqueUn(int **qr, int i, int j){
    int l, c;
    for (l=0 ; l<j ; l++){
        for (c=0 ; c<i ; c++){
            if (qr[c][l] == 0 || qr[c][l] == 1){
                if (l%2 == 0){ //(row) mod 2 == 0
                    qr[c][l] = inverse(qr[c][l]);
                }
            }
        }
    }
    return 0;
}

int ApplicationMasqueDeux(int **qr, int i, int j){
    int l, c;
    for (l=0 ; l<j ; l++){
        for (c=0 ; c<i ; c++){
            if (qr[c][l] == 0 || qr[c][l] == 1){
                if ((c)%3 == 0){ //(column) mod 3 == 0
                    qr[c][l] = inverse(qr[c][l]);
                }
            }
        }
    }
    return 0;
}

int ApplicationMasqueTrois(int **qr, int i, int j){
    int l, c;
    for (l=0 ; l<j ; l++){
        for (c=0 ; c<i ; c++){
            if (qr[c][l] == 0 || qr[c][l] == 1){
                if ((c+l)%3 == 0){ //(row + column) mod 3 == 0
                    qr[c][l] = inverse(qr[c][l]);
                }
            }
        }
    }
    return 0;
}

int ApplicationMasqueQuatre(int **qr, int i, int j){
    int l, c;
    for (l=0 ; l<j ; l++){
        for (c=0 ; c<i ; c++){
            if (qr[c][l] == 0 || qr[c][l] == 1){
                if ((int)(floor((double)(l/2)) + floor((double)(c/3)))%2 == 0){ //( floor(row / 2) + floor(column / 3) ) mod 2 == 0
                    qr[c][l] = inverse(qr[c][l]);
                }
            }
        }
    }
    return 0;
}

int ApplicationMasqueCinq(int **qr, int i, int j){
    int l, c;
    for (l=0 ; l<j ; l++){
        for (c=0 ; c<i ; c++){
            if (qr[c][l] == 0 || qr[c][l] == 1){
                if (((l*c) % 2) + ((l*c) % 3) == 0){ //((row * column) mod 2) + ((row * column) mod 3) == 0
                    qr[c][l] = inverse(qr[c][l]);
                }
            }
        }
    }
    return 0;
}

int ApplicationMasqueSix(int **qr, int i, int j){
    int l, c;
    for (l=0 ; l<j ; l++){
        for (c=0 ; c<i ; c++){
            if (qr[c][l] == 0 || qr[c][l] == 1){
                if ((((l*c) % 2) + ((l*c) % 3)) % 2 == 0){ //( ((row * column) mod 2) + ((row * column) mod 3) ) mod 2 == 0
                    qr[c][l] = inverse(qr[c][l]);
                }
            }
        }
    }
    return 0;
}

int ApplicationMasqueSept(int **qr, int i, int j){
    int l, c;
    for (l=0 ; l<j ; l++){
        for (c=0 ; c<i ; c++){
            if (qr[c][l] == 0 || qr[c][l] == 1){
                if ((((l+c) % 2) + ((l*c) % 3)) % 2 == 0){ //( ((row + column) mod 2) + ((row * column) mod 3) ) mod 2 == 0
                    qr[c][l] = inverse(qr[c][l]);
                }
            }
        }
    }
    return 0;
}


int application_masque(int **qr, int i, int j, int masque){
    /* application_masque applique le masque à appliquer.
    Attention : aucune vérification n'est faite.
    Les masques ne sont appliqués que sur les cases valant 0 ou 1.
        Pour cela, on devra utiliser la fonction reinitialisation
        pour appliquer des valeurs ignorées aux cases à préserver.*/
    
    if (masque == 0) ApplicationMasqueZero(qr, i, j);
    if (masque == 1) ApplicationMasqueUn(qr, i, j);
    if (masque == 2) ApplicationMasqueDeux(qr, i, j);
    if (masque == 3) ApplicationMasqueTrois(qr, i, j);
    if (masque == 4) ApplicationMasqueQuatre(qr, i, j);
    if (masque == 5) ApplicationMasqueCinq(qr, i, j);
    if (masque == 6) ApplicationMasqueSix(qr, i, j);
    if (masque == 7) ApplicationMasqueSept(qr, i, j);
    else return -1;

    return 0;
}


/********** Evaluations **********/


int eval1(int **qr, int c, int l){
    if (c<6) return -1;
    if (l<6) return -1;
    if (qr == NULL) return -1;
    int i=0, j=0, somme=0, continuer=0;

    for (i=0 ; i<c ; i++){
        while (j<l-4){
            if (qr[i][j] == qr[i][j+1] && qr[i][j+1] == qr[i][j+2] && qr[i][j+2] == qr[i][j+3] && qr[i][j+3] == qr[i][j+4]){
                somme += 3;
                j += 5;
                continuer = 1;
                while (continuer){
                    if (j<l){
                        if (qr[i][j] == qr[i][j-1]){
                            somme++;
                            j++;
                        }
                        else continuer--;
                    }
                    else continuer--;
                }
            }
            else j++;
        }
        j=0;
    }

    i=0;
    for (j=0 ; j<l ; j++){
        while (i<c-4){
            if (qr[i][j] == qr[i+1][j] && qr[i+1][j] == qr[i+2][j] && qr[i+2][j] == qr[i+3][j] && qr[i+3][j] == qr[i+4][j]){
                somme += 3;
                i += 5;
                continuer = 1;
                while (continuer){
                    if (i<c){
                        if (qr[i][j] == qr[i-1][j]){
                            somme++;
                            i++;
                        }
                        else continuer--;
                    }
                    else continuer--;
                }
            }
            else i++;
        }
        i=0;
    }
    return somme;
}

int eval2_compteur(int **qr, int i, int j){
    if (qr[i][j] == qr[i+1][j] == qr[i][j+1] == qr[i+1][j+1]) return 3;
    else return 0;
}
int eval2(int **qr, int c, int l){
    int somme=0, i, j;
    for (i=0 ; i<c-1 ; i++){
        for (j=0 ; j<l-1 ; j++){
            somme += eval2_compteur(qr, i, j);
        }
    }
    return somme;
}


int eval3(int **qr, int c, int l){
    int tab1[11]={0,0,0,0,1,0,1,1,1,0,1};
    int tab2[11]={1,0,1,1,1,0,1,0,0,0,0};
    int k,m,n,x1=0;
    for (c=0 ; c<21 ; c++){
        for(l=0 ; l<10 ; l++){
           for(k=0,m=0,n=0;n<11;n++){
            if(qr[c][l+n]==tab1[n]){
                k++;
              }
              if(qr[c][l+n]==tab2[n]){
                m++;
              }
            if(k==11||m==11){
                x1=x1+40;
            }
           }
        }
        }
        for (l=0 ; l<21 ; l++){
        for(c=0 ; c<10 ; c++){
           for(k=0,m=0,n=0;n<11;n++){
            if(qr[c+n][l]==tab1[n]){
                k++;
              }
              if(qr[c+n][l]==tab2[n]){
                m++;
              }
            if(k==11||m==11){
                x1=x1+40;
            }
           }
        }
        }
    return x1;
}


int eval4(int **qr, int c, int l){
    int x1=0;
    float w;
    for (l=0 ; l<21 ; l++){
        for(c=0 ; c<21 ; c++){
            if(qr[c][l]==1){
                w++;
                }
            }
        }

    w = 100*(w/441);
    w = floor(w);

    int a=0,b=0;
    while(a<w){
        a+=5;
    }
    while(b<w+5){
        b+=5;
    }
    a=abs(a-50);
    b=abs(b-50);
    if (a<b) x1=x1+a*10;
    else x1=x1+b*10;
    return x1;
}


int evaluation(int **qr, int c, int l){
    /* evaluation calcule le score du QR passé en argument,
    le score est retourné.*/
    int somme = 0;
    somme += eval1(qr, c, l);
    somme += eval2(qr, c, l);
    somme += eval3(qr, c, l);
    somme += eval4(qr, c, l);
    return somme;
}


/********** Masquage **********/


int **masque(int **qr, int c, int l){
    int i;
    int ***trio = TripleMallo();
    triple_copie(trio, qr);
    int somme[8];

    for (i=0 ; i<8 ; i++){
        trio[i] = copieqr(qr, c, l);
        reinitialisation((int**)trio[i], 1);
        application_masque((int**)trio[i], c, l, i);
        reinitialisation((int**)trio[i], 0);
        infotext((int**)trio[i], i);
        somme[i] = evaluation((int**)trio[i], c, l);
    }
    i = meilleure_somme(somme);
    
    //Sucrage des anciennes valeurs
    int x, y;
    for (x=0 ; x<c ; x++){
        for (y=0 ; y<l ; y++){
            qr[x][y] = trio[i][x][y];
        }
    }

    return 0;
}

/* Schéma : 
- on créé un nouveau QR qui sera la copie du code avec les datas
- on applique reinitialisation pour protéger les cases à protéger
- on applique le masque
- on applique reinitialisation pour réinstaller des valeurs normales dans les cases protégées
- on ajoute les données d'infotext
- on calcule l'évaluation avec chaque fonction d'eval
- on fait ça pour les 8 masques et on ne garde que le meilleur.
*/