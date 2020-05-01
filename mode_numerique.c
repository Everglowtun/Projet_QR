#include <stdio.h>
#include <stdlib.h>


void grouper(int i1,int *groupe,int *reste){//pour obtenir nombre de groupe et reste
	*groupe=i1/3;
	*reste=i1%3;
}
int entier(int a,int b,int c){//pour transforme 3 chiffres aux un chiffre
	int ret;
	ret=a*100+b*10+c;
	return ret;
}
int entier1(int a,int b){//pour transforme 2 chiffres aux un chiffre(lorsque le reste est 2)
	int ret;
	ret=a*10+b;
	return ret;
}
int binaire(int x){//pour transformer les chiffres aux nombres binaires
     int y=0;
     int p=1;
     int o=0;
    while(1)
    {
        o=x%2;
        x/=2;
        y+=o*p;
        p*=10;
        if(x<2)
        {
            y+=x*p;
            break;
        }
    }
    return y;
}
int *fenjie2(int a){//pour dissocier un nombre binaire aux 7 chiffres(seulement 1 et 0 pour le cas que le reste est 2)
    int i,p,l=1,t,c,k=0,s=1000000;
    t=a;
    int r[7];
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
int *fenjie1(int a){//pour dissocier un nombre binaire aux 4 chiffres(seulement 1 et 0 pour le cas que le reste est 1)
    int i,p,l=1,t,c,k=0,s=1000;
    t=a;
    int r[4];
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
int *fenjie(int a){//pour dissocier un nombre binaire aux 10 chiffres(seulement 1 et 0 pour le nombre groupé)
    int i,p,l=1,t,c,k=0,s=1000000000;
    t=a;
    int r[10];
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
int *fenjie3(int a){//pour dissocier un nombre binaire aux 8 chiffres(seulement 1 et 0 pour le codewords)
    int i,p,l=1,t,c,k=0,s=10000000;
    t=a;
    int r[8];
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
int ret(char c){//pour transformer le type char à le type int
	int k;
	if(c=='0'){
	  k=0;
	}
	if(c=='1'){
	  k=1;
	}
	if(c=='2'){
	  k=2;
	}
	if(c=='3'){
	  k=3;
	}if(c=='4'){
	  k=4;
	}if(c=='5'){
	  k=5;
	}if(c=='6'){
	  k=6;
	}if(c=='7'){
	  k=7;
	}if(c=='8'){
	  k=8;
	}if(c=='9'){
	  k=9;
	}
	return k;
}
void division1(const int *a,int* total,int *cnt1,int i1){//pour conserver tous codewords viennent des nombres groupé
//total et cnt1 sont les valeurs rentrés
    int i,k;
    int cnt=0;
	int groupe,reste;
	int tab1[30];
	grouper(i1,&groupe,&reste);
	for(i=0,k=0;i<i1-reste;k++,i=i+3){
        tab1[k]=entier(a[i],a[i+1],a[i+2]);
	}
	int tab2[300];
	for(i=0;i<groupe;i++){
		tab2[i]=binaire(tab1[i]);
		for(k=0;k<10;k++){
			total[cnt]=fenjie(tab2[i])[k];
			cnt++;
		}
		free(fenjie(tab2[i]));
	}

	int *w=NULL;
	if(reste==2){
	w=fenjie2(binaire(entier1(a[i1-2],a[i1-1])));
			 for(k=0;k<7;k++){
			total[cnt]=*(w+k);
			cnt++;
		}
		free(fenjie2(binaire(entier1(a[i1-2],a[i1-1]))));
	}
    int *e=NULL;
	if(reste==1){
		  e=fenjie1(binaire(a[i1-1]));
		 for(k=0;k<4;k++){
			total[cnt]=*(e+k);

			cnt++;
		}
		free(fenjie1(binaire(a[i1-1])));
	}

*cnt1=cnt;
}
int *division2(const int *total,int num1,int cnt1,int i1){//pour conserver tous les nombres de codewords
    int i;
    int numeric[4]={0,0,0,1};
    int *final=NULL;
    final=(int*)malloc(num1*sizeof(int));
    for(i=0;i<num1;i++){
		if(i<4){
			final[i]=numeric[i];//les 4 nombres qui viens de la Mode indicators
		}
		if(i>=4&&i<14){
			final[i]=fenjie(binaire(i1))[i-4];//les 10 nombres qui viens des nombres de la nombre de chiffres que vous avez entré
		}
		if(i>=14&&i<14+cnt1){
			final[i]=total[i-14];

		}
		if(i>=14+cnt1){
			final[i]=0;//ajouter 0 pour les cases reste
		}
	}
	free(fenjie(binaire(i1)));
	return final;
}
int **division3(const int *final,int num2,int num3){//pour les code words qui sont très court, ajouter les pad bytes
	int i,k;
	int tabterminale1[8]={1,1,1,0,1,1,0,0};//Pad Bytes 1
	int tabterminale2[8]={0,0,0,1,0,0,0,1};//Pad Bytes 2
	int l=0,cnt2=1;
	int **a1;
	a1=(int**)malloc(sizeof(int*)*num3);//confirmer le nombres de code words
	for(i=0;i<num3;i++){
		*(a1+i)=(int*)malloc(sizeof(int)*8);
	}
	for(i=0;i<num3;i++){
		if(i<num2){
		for(k=0;k<8;k++,l++){
			a1[i][k]=final[l];//ajouter les code words
		}
	}
	    if(i>=num2){
	    	if(cnt2==1||cnt2%2==1){

	    	for(k=0;k<8;k++){
			a1[i][k]=tabterminale1[k];//ajouter Pad Bytes 1
		}
	}
	        if(cnt2>1&&cnt2%2==0){
	    	for(k=0;k<8;k++){
			a1[i][k]=tabterminale2[k];//ajouter Pad Bytes 2
		}
		}
		}
		if(i>=num2){
			cnt2++;
		}
	}

   return a1;
}
void transform_chiffres(int **a1,int *a2,int num3){//transformer les nombres binaire de 8 unités aux chiffres
    int l=0;
	int n,m,i,k;

	for(i=0;i<num3;i++)
	{
		for(k=7;k>=0;k--){
			for(n=0;n<=7-k;n++){
				if(n==0){
					m=1;
				}
				else{
				m=m*2;
			}
			}
			l=l+a1[i][k]*m;
		}
		a2[i]=l;
		l=0;
	}
}
void transform_finale(int **a1,int **a3,int *q,int num3,int taillepg1){//créer une nouvelle matrice et mettre les code words et les code words corrigés
    int i,k;
    int **b1;
	b1=(int**)malloc(sizeof(int*)*taillepg1);
	for (i = 0; i < taillepg1; i++) {
		*(b1 + i) = (int*)malloc(sizeof(int) * 8);
	}
	for(i=0;i<taillepg1;i++){
			for(k=0;k<8;k++){
				b1[i][k]=fenjie3(binaire(*(q+i)))[k];
			}
			free(fenjie3(binaire(*(q+i))));
		}
	free(q);


	for(i=0;i<num3+taillepg1;i++){
		if(i<num3){
			for(k=0;k<8;k++){
				a3[i][k]=a1[i][k];
			}
			}
		if(i>=num3){
			for(k=0;k<8;k++){
				a3[i][k]=b1[i-num3][k];
			}
		}
		}
	for (k = 0; k < taillepg1; k++) {
		free(*(b1 + k));

}
}
int tab(int a){//vérifier les nombres de code words sont multiplié par 8
	int k;
	if(a%8==0){
		k=a;
	}
	else{
		k=a+(8-(a%8));
	}
	return k;
}
int niveau(int a){//confirmer le longueur des code words, pour le niveau 1-M est 16
	int ret;
	a=16;
	ret=a;
	return ret;
}
int log1(int a){//pour faire le transformation dans un corps fini de 2 puissance 8
	int tab[256]={0,1,25,2,50,26,198,3,223,51,
	           238  ,27  ,104  ,199  ,75  ,4  ,100  ,224  ,14  ,52  ,
			   141  ,239  ,129  ,28  ,193  ,105  ,248  ,200  ,8  ,76  ,
			   113  ,5  ,138  ,101  ,47  ,225  ,36  ,15  ,33  ,53  ,
			   147  ,142  ,218  ,240  ,18  ,130  ,69  ,29  ,181  ,194  ,
			   125  ,106  ,39  ,249  ,185  ,201  ,154  ,9  ,120  ,77  ,
			   228  ,114  ,166  ,6  ,191  ,139  ,98  ,102  ,221  ,48  ,
			   253  ,226  ,152  ,37  ,179  ,16  ,145  ,34  ,136  ,54  ,
			   208  ,148  ,206  ,143  ,150  ,219  ,189  ,241  ,210  ,
			   19  ,92  ,131  ,56  ,70  ,64  ,30  ,66  ,182  ,163  ,
			   195  ,72  ,126  ,110  ,107  ,58  ,40  ,84  ,250  ,133  ,
			   186  ,61  ,202  ,94  ,155  ,159  ,10  ,21  ,121  ,43  ,
			   78  ,212  ,229  ,172  ,115  ,243  ,167  ,87  ,7  ,112  ,192  ,
			   247  ,140  ,128  ,99  ,13  ,103  ,74  ,222  ,237  ,49  ,197  ,254  ,
			   24  ,227  ,165  ,153  ,119  ,38  ,184  ,180  ,124  ,17  ,68  ,146  ,
			   217  ,35  ,32  ,137  ,46  ,55  ,63  ,209  ,91  ,149  ,188  ,207  ,205  ,
			   144  ,135  ,151  ,178  ,220  ,252  ,190  ,97  ,242  ,86  ,211  ,171  ,20  ,
			   42  ,93  ,158  ,132  ,60  ,57  ,83  ,71  ,109  ,65  ,162  ,31  ,45  ,67  ,
			   216  ,183  ,123  ,164  ,118  ,196  ,23  ,73  ,236  ,127  ,12  ,111  ,
			   246  ,108  ,161  ,59  ,82  ,41  ,157  ,85  ,170  ,251  ,96  ,134  ,
			   177  ,187  ,204  ,62  ,90  ,203  ,89  ,95  ,176  ,156  ,169  ,160  ,
			   81  ,11  ,245  ,22  ,235  ,122  ,117  ,44  ,215  ,79  ,174  ,213  ,
			   233  ,230  ,231  ,173  ,232  ,116  ,214  ,244  ,234  ,168  ,
			   80  ,88,175};
	return tab[a-1];
}
int relog1(int a){//pour faire le transformation dans un corps fini de 2 puissance 8
	int tab[]={   1	  ,2	  ,4	  ,8	  ,16	  ,32	  ,64	  ,128	  ,
	29	  ,58	  ,116	  ,232	  ,205	  ,135	  ,19	  ,38	  ,76	  ,
	152	  ,45	  ,90	  ,180	  ,117	  ,234	  ,201	  ,143	  ,3	  ,
	6	  ,12	  ,24	  ,48	  ,96	  ,192	  ,157	  ,39	  ,78	  ,
	156	  ,37	  ,74	  ,148	  ,53	  ,106	  ,212	  ,181	  ,119	  ,
	238	  ,193	  ,159	  ,35	  ,70	  ,140	  ,5	  ,10	  ,20	  ,
	40	  ,80	  ,160	  ,93	  ,186	  ,105	  ,210	  ,185	  ,111	  ,
	222	  ,161	  ,95	  ,190	  ,97	  ,194	  ,153	  ,47	  ,94	  ,
	188	  ,101	  ,202	  ,137	  ,15	  ,30	  ,60	  ,120	  ,240	  ,
	253	  ,231	  ,211	  ,187	  ,107	  ,214	  ,177	  ,127	  ,254	  ,
	225	  ,223	  ,163	  ,91	  ,182	  ,113	  ,226	  ,217	  ,175	  ,
	67	  ,134	  ,17	  ,34	  ,68	  ,136	  ,13	  ,26	  ,52	  ,
	104	  ,208	  ,189	  ,103	  ,206	  ,129	  ,31	  ,62	  ,124	  ,
	248	  ,237	  ,199	  ,147	  ,59	  ,118	  ,236	  ,197	  ,151	  ,
	51	  ,102	  ,204	  ,133	  ,23	  ,46	  ,92	  ,184	  ,109	  ,
	218	  ,169	  ,79	  ,158	  ,33	  ,66	  ,132	  ,21	  ,42	  ,
	84	  ,168	  ,77	  ,154	  ,41	  ,82	  ,164	  ,85	  ,170	  ,
	73	  ,146	  ,57	  ,114	  ,228	  ,213	  ,183	  ,115	  ,230	  ,
	209	  ,191	  ,99	  ,198	  ,145	  ,63	  ,126	  ,252	  ,229	  ,
	215	  ,179	  ,123	  ,246	  ,241	  ,255	  ,227	  ,219	  ,171	  ,
	75	  ,150	  ,49	  ,98	  ,196	  ,149	  ,55	  ,110	  ,220	  ,
	165	  ,87	  ,174	  ,65	  ,130	  ,25	  ,50	  ,100	  ,200	  ,
	141	  ,7	  ,14	  ,28	  ,56	  ,112	  ,224	  ,221	  ,167	  ,
	83	  ,166	  ,81	  ,162	  ,89	  ,178	  ,121	  ,242	  ,249	  ,
	239	  ,195	  ,155	  ,43	  ,86	  ,172	  ,69	  ,138	  ,9	  ,
	18	  ,36	  ,72	  ,144	  ,61	  ,122	  ,244	  ,245	  ,247	  ,
	243	  ,251	  ,235	  ,203	  ,139	  ,11	  ,22	  ,44	  ,88	  ,
	176	  ,125	  ,250	  ,233	  ,207	  ,131	  ,27	  ,54	  ,108	  ,
	216	  ,173	  ,71	  ,142	  ,1};
	return tab[a];
}
int *corriger(int *pm,int *pg,int taillepm,int taillepg){// pour créer les code words corrigé
	 	int i,k,p;
        int *b=NULL;//pour conserver la valeur de PG
		b = (int*)malloc(taillepg * sizeof(int));
        for(i=0;i<taillepg;i++){
        	b[i]=pg[i];
		}
for(i=0;i<taillepm;i++){
	p=log1(pm[0]);//l'exposant de la première terme de PM
    for(k=0;k<taillepg;k++){//l'exposant de la première terme de PM multiplie la PG
		pg[k]=pg[k]+p;

		if(pg[k]>=256){//si il y a un exposant d'un terme 'X' supérieur que 255, fait X%255
			pg[k]=pg[k]%255;
		  }

	   }
	for(k=0;k<taillepg;k++){//faire la transforme des exposant de PG aux chiffres
		pg[k]=relog1(pg[k]);

	}
	for(k=0;k<taillepg;k++){//faire le calcul exotic
		pm[k]=pm[k]^pg[k];

	}

	for(k=0;k<taillepm;k++){//supprimer la première terme de PM
		if(k==taillepm-1){
			pm[k]=0;
			break;
		}
		pm[k]=pm[k+1];

	}


	for(k=0;k<taillepg;k++){//initialiser la PG
	    pg[k]=b[k];
	}
    }
free(b);

	int *outab=NULL;
	outab = (int *)malloc((taillepg-1)*sizeof(int));
    for(i=0;i<taillepg-1;i++){
    	outab[i]=pm[i];
	}

	return outab;
}
int* numerique(char *b,int length){
 int c,k,i=0;
 int i1=length;
   
	//i1 est le nombre des chiffres
	if (i1>34){
			exit(0);
		}
	int *a=NULL;
	a=(int*)malloc(i1*sizeof(int));
	for(k=0;k<i1;k++){
		a[k]=ret(b[k]);//pour changer le type char au type int
	}
    int total[200];//tableau qui conserve le les nombres binaire qui vient des
    int cnt1=0;
    division1(a,total,&cnt1,i1);
    free(a);
    int num1;//conserver les nombres binaire de code words(avant ajouter les pad byte)
    num1=14+cnt1;
    num1=tab(num1);//confirmer les nombre de binaire de code words sont multiplié par 8
    int *final=NULL;
    final=(int*)malloc(num1*sizeof(int));
    final=division2(total,num1,cnt1,i1);
    free(division2(total,num1,cnt1,i1));
	int num2=num1/8;
	int num3;
	num3=niveau(num2);//nombres de code words(*8) en niveau 1-M
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
