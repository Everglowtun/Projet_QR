#ifndef MODE_BYTE_H_INCLUDED
#define MODE_BYTE_H_INCLUDED
int* byte();
//la fonction principal de la mode_Byte il peut sortir un table de taille 208
//la structure est comme la fonction numérique
/*dans la fonction Alphanumeric il utilise aussi des fonctions de mode_numetique
int binaire(int a);int *fenjie(int a);void transform_chiffres(int **a1,int *a2,int num3);
int **division3(const int *final,int num2,int num3);void transform_chiffres(int **a1,int *a2,int num3);
void transform_finale(int **a1,int **a3,int *q,int num3,int taillepg1);int niveau(int a);int tab(int a);
int log1(int a);int relog1(int a);int *corriger(int *pm,int *pg,int taillepm,int taillepg);*/
int *MAlloTableau_1(int tx);//pour créer une espace dynamique
int *nomme_byte(char *a,int i1,int *ck);//pour conserver tous les nombres de codewords
#endif // MODE_BYTE_H_INCLUDED