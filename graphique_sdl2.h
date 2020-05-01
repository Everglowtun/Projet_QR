#ifndef GRAPHIQUE_H_INCLUDED
#define GRAPHIQUE_H_INCLUDED
int **MAlloTableau_sdl2(int tx, int ty);
/*Malloue dynamiquement un tableau ¨¤ double entr¨¦e.
    La taille est en valeur num¨¦rale (la premi¨¨re case est 1;1).*/
void mode_initiative_sdl2(int **tab);
int data_sdl2(int **qr, int tx, int ty, int *bin);
//il permet d'ajouter les 208 de code words à QR-code
void mode_mask1_sdl2(int **tab);
//la matrice de la première masque
void mode_mask2_sdl2(int **tab);
void mode_mask3_sdl2(int **tab);
void mode_mask4_sdl2(int **tab);
void mode_mask5_sdl2(int **tab);
void mode_mask6_sdl2(int **tab);
void mode_mask7_sdl2(int **tab);
void mode_mask8_sdl2(int **tab);
void infotext_sdl2(int **qr,int masque);
//pour ajouter le Format String dans le QR-code
void application_masque_sdl2(int **qr,int masque);
//pour ajouter le meilleur masque dans le QR-code
int evaluation_sdl2(int **qr, int c, int l);
//il compter le somme de 4 parties de points
//le point de masque permet de choisir le masque meilleur, le masque qui a le point plus petit est le meilleur.
int eval4_sdl2(int **qr, int c, int l);
//il compter le quatrième partie de point de la masque
int eval3_sdl2(int **qr, int c, int l);
//il compter le troisième partie de point de la masque
int eval2_sdl2(int **qr, int c, int l);
//il compter le deuxième partie de point de la masque
int eval2_compteur_sdl2(int **qr, int i, int j);
//il compter le deuxième partie de point de la masque
int eval1_sdl2(int **qr, int c, int l);
//il compter le première partie de point de la masque
#endif // GRAPHIQUE_H_INCLUDED
