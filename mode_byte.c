#include <stdio.h>
#include <stdlib.h>



int *MAlloTableau_1(int tx){//pour créer une espace dynamique
    int *qr = (int*)malloc(tx * sizeof(int));
    return qr;
}

int *nomme_byte(char *a,int i1,int *ck){//pour conserver tous les nombres de codewords
 int i;
 int mode_bit[4]={0,1,0,0};
 int num1=0;
 num1=12+i1*8;
 num1=tab(num1);
 int *fini=NULL;
 fini=(int*)malloc(num1*sizeof(int));
 for(i=0;i<num1;i++){
    if(i<4){
			fini[i]=mode_bit[i];//les 4 nombres qui viens de la Mode Byte
		}
    if(i>=4&&i<12){
		    fini[i]=fenjie3(binaire(i1))[i-4];//les 8 nombres qui viens des nombres de la nombre de chiffres que vous avez entré
		}
    if(i>=12&&i<12+i1*8){
			fini[i]=ck[i-12];
		}
    if(i>=12+i1*8){
			fini[i]=0;
		}
	}
	free(fenjie3(binaire(i1)));
	return fini;
}


int* byte(char *mots, int length){
if(length>14){
    exit(0);
 }
 int k,i=0,ck[100];
 char c,b[200];
 int i1=length;

 for (int compte=0 ; compte < length ; compte++){
     b[compte] = mots[compte];
 }

 int *tab_initiative=NULL;
 tab_initiative=MAlloTableau_1(i1);
 for(i=0;i<i1;i++){
     tab_initiative[i]=(int)b[i];
 }
  for(i=0;i<i1;i++){
     ck[i]=tab_initiative[i];
 }
 free(tab_initiative);
 int l=0,i2=8*i1;
 int *tab2=NULL;
 tab2=MAlloTableau_1(i2);
 for(i=0;i<i1;i++){
    for(k=0;k<8;k++){
        tab2[l]=fenjie3(binaire(ck[i]))[k];
        l++;
    }
 free(fenjie3(binaire(ck[i])));
 }
 int num1=12+i1*8;
 num1=tab(num1);
 int *fini=NULL;
 fini=nomme_byte(b,i1,tab2);
 free(nomme_byte(b,i1,tab2));
 int num2=num1/8;
 int num3;
 num3=niveau(num2);
 int **a1;
 a1=(int**)malloc(sizeof(int*)*num3);
 for(i=0;i<num3;i++){
    *(a1+i)=(int*)malloc(sizeof(int)*8);
	}
 a1=division3(fini,num2,num3);
 free(division3(fini,num2,num3));
 free(fini);
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