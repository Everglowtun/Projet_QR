#ifndef MODE_NUMERIQUE_H_INCLUDED
#define MODE_NUMERIQUE_H_INCLUDED
void grouper(int cnt,int *groupe,int *reste);
//pour obtenir nombre de groupe et reste
int entier(int a,int b,int c);
//pour transforme 3 chiffres aux un chiffre
int entier1(int a,int b);
//pour transforme 2 chiffres aux un chiffre(lorsque le reste est 2)
int binaire(int a);
//pour transformer les chiffres aux nombres binaires
int *fenjie(int a);
//pour dissocier un nombre binaire aux 10 chiffres(seulement 1 et 0 pour le nombre groupé)
int *fenjie1(int a);
//pour dissocier un nombre binaire aux 4 chiffres(seulement 1 et 0 pour le cas que le reste est 1)
int *fenjie2(int a);
//pour dissocier un nombre binaire aux 7 chiffres(seulement 1 et 0 pour le cas que le reste est 2)
int *fenjie3(int a);
//pour dissocier un nombre binaire aux 8 chiffres(seulement 1 et 0 pour le codewords)
void division1(const int *a, int *total,int *cnt1,int i1);
//pour conserver tous codewords viennent des nombres groupé
//total et cnt1 sont les valeurs rentrés
int *division2(const int *total,int num1,int cnt1,int i1);
//pour conserver tous les nombres de codewords
int **division3(const int *final,int num2,int num3);
//pour les code words qui sont très court, ajouter les pad bytes
void transform_chiffres(int **a1,int *a2,int num3);
//transformer les nombres binaire de 8 unités aux chiffres
void transform_finale(int **a1,int **a3,int *q,int num3,int taillepg1);
//créer une nouvelle matrice et mettre les code words et les code words corrigés
int *AlphaConvert(char *texte, int taille);
int ret(char c);
//pour transformer le type char à le type int
int niveau(int a);
//confirmer le longueur des code words, pour le niveau 1-M est 16
int tab(int a);
//vérifier les nombres de code words sont multiplié par 8
int log1(int a);
//changer les exposants aux chiffres
int relog1(int a);
//changer chiffres aux exposants
int *corriger(int *pm,int *pg,int taillepm,int taillepg);
//La fonction qui permet de créer les code words d'erreurs
int* numerique(char *b,int length);
//la fonction principal de la mode_numérique il peut sortir un table de taille 208


#endif // MODE_NUMERIQUE_H_INCLUDED
