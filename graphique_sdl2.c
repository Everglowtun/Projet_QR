#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

//#include "graphique_sdl2.h"

int **MAlloTableau_sdl2(int tx, int ty){
    /*Malloue dynamiquement un tableau ¨¤ double entr¨¦e.
    La taille est en valeur num¨¦rale (la premi¨¨re case est 1;1).*/
    int **qr = malloc(tx * sizeof(int*)), i=-1;
    while (++i < tx){
        qr[i] = malloc(ty * sizeof(int)); }
    return qr;
}
void mode_initiative_sdl2(int **tab){
    int old_tab[21][21] =  {{1, 1, 1, 1, 1, 1, 1, 3, 2, 0, 0, 0, 0, 3, 1, 1, 1, 1, 1, 1, 1},
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
                            {3, 3, 3, 3, 3, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, // dark module coord ([(4 * V) + 9], 8)
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
void mode_mask1_sdl2(int **tab){
    int i,j;
     for (i=0 ; i<21 ; i++){
        for (j=0 ; j<21 ; j++){
                tab[i][j]=0;
            }
        }

    for (i=0 ; i<21 ; i++){
        for (j=0 ; j<21 ; j++){
            if((i+j)%2==0){
                tab[i][j]=1;
            }
        }
    }
    for (i=0 ; i<9 ; i++){
        for (j=0 ; j<9 ; j++){
                tab[i][j]=0;
        }
    }
       for (i=0 ; i<9 ; i++){
        for (j=13 ; j<21 ; j++){
                tab[i][j]=0;
        }
    }
    for (i=13 ; i<21 ; i++){
        for (j=0 ; j<9 ; j++){
                tab[i][j]=0;
        }
    }
    for(i=0;i<21;i++){
        tab[6][i]=0;
    }
    for(i=0;i<21;i++){
        tab[i][6]=0;
    }
}
void mode_mask2_sdl2(int **tab){
    int i,j;
     for (i=0 ; i<21 ; i++){
        for (j=0 ; j<21 ; j++){
                tab[i][j]=0;
            }
        }

    for (i=0 ; i<21 ; i++){
        for (j=0 ; j<21 ; j++){
            if(j%2==0){
                tab[i][j]=1;
            }
        }
    }
    for (i=0 ; i<9 ; i++){
        for (j=0 ; j<9 ; j++){
                tab[i][j]=0;
        }
    }
       for (i=0 ; i<9 ; i++){
        for (j=13 ; j<21 ; j++){
                tab[i][j]=0;
        }
    }
    for (i=13 ; i<21 ; i++){
        for (j=0 ; j<9 ; j++){
                tab[i][j]=0;
        }
    }
    for(i=0;i<21;i++){
        tab[6][i]=0;
    }
    for(i=0;i<21;i++){
        tab[i][6]=0;
    }
}
void mode_mask3_sdl2(int **tab){
    int i,j;
     for (i=0 ; i<21 ; i++){
        for (j=0 ; j<21 ; j++){
                tab[i][j]=0;
            }
        }

    for (i=0 ; i<21 ; i++){
        for (j=0 ; j<21 ; j++){
            if(i%3==0){
                tab[i][j]=1;
            }
        }
    }
    for (i=0 ; i<9 ; i++){
        for (j=0 ; j<9 ; j++){
                tab[i][j]=0;
        }
    }
       for (i=0 ; i<9 ; i++){
        for (j=13 ; j<21 ; j++){
                tab[i][j]=0;
        }
    }
    for (i=13 ; i<21 ; i++){
        for (j=0 ; j<9 ; j++){
                tab[i][j]=0;
        }
    }
    for(i=0;i<21;i++){
        tab[6][i]=0;
    }
    for(i=0;i<21;i++){
        tab[i][6]=0;
    }
}
void mode_mask4_sdl2(int **tab){
    int i,j;
     for (i=0 ; i<21 ; i++){
        for (j=0 ; j<21 ; j++){
                tab[i][j]=0;
            }
        }

    for (i=0 ; i<21 ; i++){
        for (j=0 ; j<21 ; j++){
            if((i+j)%3==0){
                tab[i][j]=1;
            }
        }
    }
    for (i=0 ; i<9 ; i++){
        for (j=0 ; j<9 ; j++){
                tab[i][j]=0;
        }
    }
       for (i=0 ; i<9 ; i++){
        for (j=13 ; j<21 ; j++){
                tab[i][j]=0;
        }
    }
    for (i=13 ; i<21 ; i++){
        for (j=0 ; j<9 ; j++){
                tab[i][j]=0;
        }
    }
    for(i=0;i<21;i++){
        tab[6][i]=0;
    }
    for(i=0;i<21;i++){
        tab[i][6]=0;
    }
}
void mode_mask5_sdl2(int **tab){
    int i,j;
     for (i=0 ; i<21 ; i++){
        for (j=0 ; j<21 ; j++){
                tab[i][j]=0;
            }
        }

    for (i=0 ; i<21 ; i++){
        for (j=0 ; j<21 ; j++){
            if((j/2+i/3)%2==0){
                tab[i][j]=1;
            }
        }
    }
    for (i=0 ; i<9 ; i++){
        for (j=0 ; j<9 ; j++){
                tab[i][j]=0;
        }
    }
       for (i=0 ; i<9 ; i++){
        for (j=13 ; j<21 ; j++){
                tab[i][j]=0;
        }
    }
    for (i=13 ; i<21 ; i++){
        for (j=0 ; j<9 ; j++){
                tab[i][j]=0;
        }
    }
    for(i=0;i<21;i++){
        tab[6][i]=0;
    }
    for(i=0;i<21;i++){
        tab[i][6]=0;
    }
}
void mode_mask6_sdl2(int **tab){
    int i,j;
     for (i=0 ; i<21 ; i++){
        for (j=0 ; j<21 ; j++){
                tab[i][j]=0;
            }
        }

    for (i=0 ; i<21 ; i++){
        for (j=0 ; j<21 ; j++){
            if((i*j)%2+(i*j)%3==0){
                tab[i][j]=1;
            }
        }
    }
    for (i=0 ; i<9 ; i++){
        for (j=0 ; j<9 ; j++){
                tab[i][j]=0;
        }
    }
       for (i=0 ; i<9 ; i++){
        for (j=13 ; j<21 ; j++){
                tab[i][j]=0;
        }
    }
    for (i=13 ; i<21 ; i++){
        for (j=0 ; j<9 ; j++){
                tab[i][j]=0;
        }
    }
    for(i=0;i<21;i++){
        tab[6][i]=0;
    }
    for(i=0;i<21;i++){
        tab[i][6]=0;
    }
}
void mode_mask7_sdl2(int **tab){
    int i,j;
    for (i=0 ; i<21 ; i++){
        for (j=0 ; j<21 ; j++){
                tab[i][j]=0;
            }
        }

    for (i=0 ; i<21 ; i++){
        for (j=0 ; j<21 ; j++){
            if(((i*j)%2+(i*j)%3)%2==0){
                tab[i][j]=1;
            }
        }
    }
    for (i=0 ; i<9 ; i++){
        for (j=0 ; j<9 ; j++){
                tab[i][j]=0;
        }
    }
       for (i=0 ; i<9 ; i++){
        for (j=13 ; j<21 ; j++){
                tab[i][j]=0;
        }
    }
    for (i=13 ; i<21 ; i++){
        for (j=0 ; j<9 ; j++){
                tab[i][j]=0;
        }
    }
    for(i=0;i<21;i++){
        tab[6][i]=0;
    }
    for(i=0;i<21;i++){
        tab[i][6]=0;
    }
}
void mode_mask8_sdl2(int **tab){
    int i,j;
    for (i=0 ; i<21 ; i++){
        for (j=0 ; j<21 ; j++){
                tab[i][j]=0;
            }
        }

    for (i=0 ; i<21 ; i++){
        for (j=0 ; j<21 ; j++){
           if(((i+j)%2+(i*j)%3)%2==0){
                tab[i][j]=1;
            }
        }
    }
    for (i=0 ; i<9 ; i++){
        for (j=0 ; j<9 ; j++){
                tab[i][j]=0;
        }
    }
       for (i=0 ; i<9 ; i++){
        for (j=13 ; j<21 ; j++){
                tab[i][j]=0;
        }
    }
    for (i=13 ; i<21 ; i++){
        for (j=0 ; j<9 ; j++){
                tab[i][j]=0;
        }
    }
    for(i=0;i<21;i++){
        tab[6][i]=0;
    }
    for(i=0;i<21;i++){
        tab[i][6]=0;
    }
}
int data_sdl2(int **qr, int tx, int ty, int *bin){
    /*Append les datas.
    tx : nombre de lignes en valeur r¨¦elle (C) et ty : nombre de colones en valeur r¨¦elle (C)
    OSQ les 0 et 1 sont dans un tableau d'entiers qui est de la bonne taille.*/
    int descendre=0, i=0, largeur = tx, hauteur = ty;

    while (largeur>0){
        while (!descendre){
            qr[largeur][hauteur] = bin[i]; i++;
            largeur--;
            qr[largeur][hauteur] = bin[i]; i++;
            if (hauteur == 0) { //test de hauteur hors-limite
                descendre++; largeur--; }
            else { //autres tests
                if (qr[largeur][hauteur-1] == 2 && qr[largeur+1][hauteur-1] == 2) { //test de la zone 2 en mont¨¦e
                    largeur--;
                    descendre++; }
                else {
                    if (qr[largeur][hauteur-1] == 3 && qr[largeur+1][hauteur-1] == 1) { //test de la zone 31 en mont¨¦e
                        largeur++ ; hauteur-=2; }
                    else { largeur++; hauteur--; } //tout va bien
                }
            }
        }

        if (qr[largeur][hauteur] == 3 && qr[largeur][hauteur-1] == 1) largeur--; //test de la zone 31 verticale apr¨¨s la mont¨¦e

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

        if (qr[largeur][hauteur] == 2 && qr[largeur][hauteur-1] == 2) hauteur-=8; //test de la zone 31 verticale apr¨¨s la mont¨¦e
    }
    return 0;

}
void application_masque_sdl2(int **qr,int masque){
    /* application_masque applique le masque à appliquer.
    Attention : aucune vérification n'est faite.
    Les masques ne sont appliqués que sur les cases valant 0 ou 1.
        Pour cela, on devra utiliser la fonction reinitialisation
        pour appliquer des valeurs ignorées aux cases à préserver.*/

    if (masque == 0) mode_mask1_sdl2(qr);
    if (masque == 1) mode_mask2_sdl2(qr);
    if (masque == 2) mode_mask3_sdl2(qr);
    if (masque == 3) mode_mask4_sdl2(qr);
    if (masque == 4) mode_mask5_sdl2(qr);
    if (masque == 5) mode_mask6_sdl2(qr);
    if (masque == 6) mode_mask7_sdl2(qr);
    if (masque == 7) mode_mask8_sdl2(qr);
}
void infotext_sdl2(int **qr,int masque){
    int a1[][15] =    {{1,0,1,0,1,0,0,0,0,0,1,0,0,1,0},
                        {1,0,1,0,0,0,1,0,0,1,0,0,1,0,1},
                        {1,0,1,1,1,1,0,0,1,1,1,1,1,0,0},
                        {1,0,1,1,0,1,1,0,1,0,0,1,0,1,1},
                        {1,0,0,0,1,0,1,1,1,1,1,1,0,0,1},
                        {1,0,0,0,0,0,0,1,1,0,0,1,1,1,0},
                        {1,0,0,1,1,1,1,1,0,0,1,0,1,1,1},
                        {1,0,0,1,0,1,0,1,0,1,0,0,0,0,0}};

    int x,y;
    for(x=0;x<6;x++){
        qr[x][8]=a1[masque][x];
     }
     qr[7][8]=a1[masque][6];
     qr[8][8]=a1[masque][7];
     qr[8][7]=a1[masque][8];
     for(x=9,y=5;x<15;x++,y--){
        qr[8][y]=a1[masque][x];
     }
     for(x=0,y=20;x<7;x++,y--){
        qr[8][y]=a1[masque][x];
     }
      for(x=7,y=13;x<15;x++,y++){
        qr[y][8]=a1[masque][x];
     }
}
int eval1_sdl2(int **qr, int c, int l){
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


int eval2_compteur_sdl2(int **qr, int i, int j){
    if ((qr[i][j] == qr[i+1][j])&&(qr[i][j]==qr[i][j+1])&&(qr[i][j+1] == qr[i+1][j+1])) return 3;
    else return 0;
}
int eval2_sdl2(int **qr, int c, int l){
    int somme=0, i, j;
    for (i=0 ; i<c-1 ; i++){
        for (j=0 ; j<l-1 ; j++){
            somme += eval2_compteur_sdl2(qr, i, j);
        }
    }
    return somme;
}

int eval3_sdl2(int **qr, int c, int l){
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


int eval4_sdl2(int **qr, int c, int l){
        int x1=0;
        float w;
    for (l=0 ; l<21 ; l++){
        for(c=0 ; c<21 ; c++){
          if(qr[c][l]==1){
           w++;
            }
          }
        }

    w=100*(w/441);
    w=floor(w);

    int a=0,b=0;
    while(a<w){
        a+=5;
    }
    while(b<w+5){
        b+=5;
    }
    a=abs(a-50);
    b=abs(b-50);
    if(a<b){
        x1=x1+a*10;
    }
    else{
        x1=x1+b*10;
    }
    return x1;
}


int evaluation_sdl2(int **qr, int c, int l){
    /* evaluation calcule le score du QR passé en argument,
    le score est retourné.*/
    int somme = 0;
    somme += eval1_sdl2(qr, c, l);
    somme += eval2_sdl2(qr, c, l);
    somme += eval3_sdl2(qr, c, l);
    somme += eval4_sdl2(qr, c, l);
   // printf("%d\n",eval4(qr, c, l));
    return somme;
}

