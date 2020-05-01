#include <stdio.h>
#include <stdlib.h>
#include "mode_alpha.h"

void grouper_alpha(int i1,int *groupe,int *reste){//pour obtenir nombre de groupe et reste
	*groupe=i1/2;
	*reste=i1%2;
}
void division1_alpha(const int *a,int *total,int *cnt1,int i1){//pour conserver tous codewords viennent des nombres group¨¦
//total et cnt1 sont les valeurs rentr¨¦s
    int i,k;
    int *c;
    c=(int*)malloc(sizeof(int)*11);
    int cnt=0;
	int groupe,reste;
	int tab1[30];
	grouper_alpha(i1,&groupe,&reste);
	for(i=0,k=0;i<i1-reste;k++,i=i+2){
        tab1[k]=fois45(a[i],a[i+1]);
	}

	for(i=0;i<groupe;i++){
        c=fenjie_alpha(tab1[i]);
		for(k=0;k<11;k++){
			total[cnt]=fenjie_alpha(tab1[i])[k];
			cnt++;
		}
		free(fenjie(tab1[i]));
	}
	free(c);
    int *e=NULL;
	if(reste==1){
		  e=fenjie1_alpha(binaire(a[i1-1]));
		 for(k=0;k<6;k++){
			total[cnt]=*(e+k);
			cnt++;
		}
		free(fenjie1_alpha(binaire(a[i1-1])));
	}
*cnt1=cnt;
}
int *division2_alpha(const int *total,int num1,int cnt1,int i1){//pour conserver tous les nombres de codewords
    int i;
    int alpha[4]={0,0,1,0};
    int *final=NULL;
    final=(int*)malloc(num1*sizeof(int));
    for(i=0;i<num1;i++){
		if(i<4){
			final[i]=alpha[i];//les 4 nombres qui viens de la Mode indicators
		}
		if(i>=4&&i<13){
			final[i]=fenjie2_alpha(binaire(i1))[i-4];//les 9 nombres qui viens des nombres de la nombre de chiffres que vous avez entré
		}
		if(i>=14&&i<14+cnt1){
			final[i]=total[i-13];
		}
		if(i>=13+cnt1){
			final[i]=0;//ajouter 0 pour les cases reste
		}
	}
	free(fenjie(binaire(i1)));
	return final;
}

int *fenjie_alpha(int nb){//pour dissocier un nombre binaire aux 10 chiffres(seulement 1 et 0 pour le nombre group¨¦)
    int i=0;
    int taille=11;
    int *tab=NULL;
    tab=(int*)malloc(taille*sizeof(int));

    for(i=0;i<taille;i++)
    {
     tab[i]=nb%2;
     nb=nb/2;
        }
    int *p = &tab[0], *q = &tab[10], temp;
    while (p < q)
    {
    temp = *p;
    *(p++) = *q;
    *(q--) = temp;
    }
   return tab;
}
int *fenjie1_alpha(int a){//pour dissocier un nombre binaire aux 4 chiffres(seulement 1 et 0 pour le cas que le reste est 1)
    int i,p,l=1,t,c,k=0,s=100000;
    t=a;
    int r[6];
    int *q;
    while(t>9){
    	t/=10;
        l*=10;
	}
	p=l;
  do{
 if(p<s){
 c=a/s;
 r[k]=c;

 s/=10;
  k++;
}
if(p>=s){
	c=a/l;
 r[k]=c;

 a %= l;
 l/=10;
  k++;
}
 } while (l>0);
 q=(int *)malloc(k*sizeof(int));
  for(i=0;i<k;i++){
  	*(q+i)=r[i];
  }
 return q;
}
int *fenjie2_alpha(int a){//pour dissocier un nombre binaire aux 4 chiffres(seulement 1 et 0 pour le cas que le reste est 1)
    int i,p,l=1,t,c,k=0,s=100000000;
    t=a;
    int r[9];
    int *q;
    while(t>9){
    	t/=10;
        l*=10;
	}
	p=l;
  do{
 if(p<s){
 c=a/s;
 r[k]=c;

 s/=10;
  k++;
}
if(p>=s){
	c=a/l;
 r[k]=c;

 a %= l;
 l/=10;
  k++;
}
 } while (l>0);
 q=(int *)malloc(k*sizeof(int));
  for(i=0;i<k;i++){
  	*(q+i)=r[i];
  }
 return q;
}
int fois45(int a,int b){
    int k=0;
    k=45*a+b;
    return k;
}


int *AlphaConvert(char *texte, int taille){ //void* nécessaire pour

/*     AlphaConvert transforme le texte en son encodage QR
alphanumérique.
         /!\ AVERTISSEMENT: alpha_convert suppose que les caractères dans
texte sont : "A-Z0-9 $%*+-./:" et d'AUCUN AUTRE TYPE /!\
         Prend en arguments le texte à convertir (tableau de caractères)
en encodage QR alphanumérique,
             ainsi que sa taille (entier).
         Retourne un pointeur vers le tableau d'entiers obtenu.
         Nécessite string. */

     int convert[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, //0-9
                     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, //10-19
                     -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, //20-29
                     -1, -1, 36, -1, -1, -1, 37, 38, -1, -1, //30-39
                     -1, -1, 39, 40, -1, 41, 42, 43, 0, 1,   //40-49
                     2, 3, 4, 5, 6, 7, 8, 9, 44, -1,         //50-59
                     -1, -1, -1, -1, -1, 10, 11, 12, 13, 14, //60-69
                     15, 16, 17, 18, 19, 20, 21, 22, 23, 24, //70-79
                     25, 26, 27, 28, 29, 30, 31, 32, 33, 34, //80-89
                     35};                                    //90
     int i=0, ascii, *outab=NULL;
     outab = (int *)malloc(taille*sizeof(int));

     while (texte[i] != '\0'){
         ascii = (int)texte[i];
         outab[i] = convert[ascii];
         i++;
     }

     return outab;
}






int* alpha(char *mots, int length){//la fonction principal de la mode_alpha il peut sortir un table de taille 208
//la structure est comme la fonction numérique
if(length>20){
    exit(0);
 }
 int c,k,i;
 char b[200];
 int i1=length;
 for (int compte=0 ; compte < length ; compte++){
     b[compte] = mots[compte];
 }
			int a[i1];
	for(k=0;k<i1;k++){
		a[k]=AlphaConvert(b,i1)[k];
	}
    int cnt1=0;
    int total[100];
    division1_alpha(a,total,&cnt1,i1);
    //free(a);
    int num1=0;
    num1=13+cnt1;
    num1=tab(num1);
    int *final=NULL;
    final=(int*)malloc(num1*sizeof(int));
    final=division2_alpha(total,num1,cnt1,i1);
    free(division2_alpha(total,num1,cnt1,i1));
	int num2=num1/8;
	int num3;
	num3=niveau(num2);

	 int **a1;
	a1=(int**)malloc(sizeof(int*)*num3);
	for(i=0;i<num3;i++){
		*(a1+i)=(int*)malloc(sizeof(int)*8);
	}
    a1=division3(final,num2,num3);
    free(division3(final,num2,num3));
	free(final);
	int *a2=NULL;
	a2=(int*)malloc(num3*sizeof(int));
	transform_chiffres(a1,a2,num3);
	int taillepg=11,taillepm=num3;
	int taillepg1 = taillepg - 1;
	int pg[11]={0,251,67,46,61,118,70,64,94,32,45};//la polyn?me de générale  de niveau 1-M
	int *q=NULL;//pour conserver la valeur des code words d'erreurs
	q = (int*)malloc(taillepg1 * sizeof(int));
	q = corriger(a2, pg, taillepm, taillepg);
	free(corriger(a2, pg, taillepm, taillepg));//libérer la mémoire
	free(a2);
	int **a3=NULL;
	a3 = (int**)malloc(sizeof(int*)*(taillepg1+num3));
	for (i = 0; i < taillepg1+num3; i++) {
		*(a3 + i) = (int*)malloc(sizeof(int) * 8);
	}
	transform_finale(a1,a3,q,num3,taillepg1);
	for (k = 0; k < num3; k++) {
		free(*(a1 + k));
	}
	int m=0;
    int *a4=NULL;
    a4=(int*)malloc(sizeof(int)*(num3+taillepg1)*8);
    for(i=0;i<num3+taillepg1;i++){
		for(k=0;k<8;k++,m++){
			a4[m]=a3[i][k];
		}
	}
    for (k = 0; k < num3+taillepg1; k++) {
		free(*(a3 + k));
	}
  return a4;
}