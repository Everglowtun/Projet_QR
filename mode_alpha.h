#ifndef MODE_ALPHA_H_INCLUDED
#define MODE_ALPHA_H_INCLUDED
void grouper_alpha(int i1,int *groupe,int *reste);
//pour obtenir nombre de groupe et reste
void division1_alpha(const int *a,int *total,int *cnt1,int i1);
//pour conserver tous codewords viennent des nombres group¨¦
//total et cnt1 sont les valeurs rentr¨¦s
int *fenjie_alpha(int a);
//pour dissocier un nombre binaire aux 10 chiffres(seulement 1 et 0 pour le nombre group¨¦)
int *fenjie1_alpha(int a);
//pour dissocier un nombre binaire aux 4 chiffres(seulement 1 et 0 pour le cas que le reste est 1)
int *fenjie2_alpha(int a);
//pour dissocier un nombre binaire aux 4 chiffres(seulement 1 et 0 pour le cas que le reste est 1)
int fois45(int a,int b);
int *division2_alpha(const int *total,int num1,int cnt1,int i1);
//pour conserver tous les nombres de codewords
int *alpha();
//la fonction principal de la mode_alpha il peut sortir un table de taille 208
//la structure est comme la fonction numérique
/*dans la fonction Alphanumeric il utilise aussi des fonctions de mode_numetique
int binaire(int a);int *fenjie(int a);void transform_chiffres(int **a1,int *a2,int num3);
int **division3(const int *final,int num2,int num3);void transform_chiffres(int **a1,int *a2,int num3);
void transform_finale(int **a1,int **a3,int *q,int num3,int taillepg1);int niveau(int a);int tab(int a);
int log1(int a);int relog1(int a);int *corriger(int *pm,int *pg,int taillepm,int taillepg);*/
int *AlphaConvert(char *texte, int taille);
#endif // MODE_ALPHA_H_INCLUDED
