#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// Pour compilation avec GCC
#include "mode_numerique.c"
#include "mode_alpha.c"
#include "graphique_sdl2.c"
#include "mode_byte.c"


/* Pour compilation avec CPP (ou gcc -I)
#include "mode_numerique.h"
#include "mode_alpha.h"
#include "graphique_sdl2.h"
#include "mode_byte.h"
*/


void masque_meilleur_sdl2(int *bin,int **qr,int **qr1,int x3);
//la fonction permet de choisir le masque meilleur pour le QR-code
void graphique_sdl2();

int main(int agrc,char* agrv[]){
    printf("Vous pouvez cliquer les bouton à gauche pour choisir les modes différents");
    graphique_sdl2();
    return 0;
}
void graphique_sdl2(){
    SDL_Rect rect4;
    SDL_Rect rect5;
    SDL_Rect rect_alpha;
    rect4.x=0;
    rect4.y=0;
    rect4.w=300;
    rect4.h=100;
    rect5.x=0;
    rect5.y=100;
    rect5.w=300;
    rect5.h=100;
    rect_alpha.x=0;
    rect_alpha.y=200;
    rect_alpha.w=300;
    rect_alpha.h=100;
    int *bin =NULL;//le variable conserve tous les code words
    bin=(int*)malloc(208*sizeof(int));
    //bin=byte();
    //bin=numerique();
    //bin=Alphanumeric();
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* Window = SDL_CreateWindow("text",
                                          SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,
                                          800,500,
                                         SDL_WINDOW_SHOWN);//cr谷er le fen那tre
   SDL_Renderer* rend= SDL_CreateRenderer(Window,-1,SDL_RENDERER_ACCELERATED);//mettre le fen那tre dans le rendu photor谷aliste
   SDL_RenderClear(rend);//initialiser le fen那tre
   SDL_Surface* face77=IMG_Load("nianina.jpg");
   SDL_Texture* face7=SDL_CreateTextureFromSurface(rend,face77);//mettre le photo dans le rendu photor谷aliste
   SDL_Surface* ecarn=IMG_Load("white.jpg");
   SDL_Texture* face1=SDL_CreateTextureFromSurface(rend,ecarn);
   SDL_Surface* carre=IMG_Load("black.jpg");
   SDL_Texture* face2=SDL_CreateTextureFromSurface(rend,carre);
   SDL_Surface* face1surface=IMG_Load("num.jpg");
   SDL_Texture* face4=SDL_CreateTextureFromSurface(rend,face1surface);
   SDL_Surface* face3surface=IMG_Load("alpha.jpg");
   SDL_Texture* face_alpha=SDL_CreateTextureFromSurface(rend,face3surface);
   SDL_Surface* face2surface=IMG_Load("byte.jpg");
   SDL_Texture* face5=SDL_CreateTextureFromSurface(rend,face2surface);
   SDL_RenderCopy(rend,face4,NULL,&rect4);
   SDL_RenderCopy(rend,face5,NULL,&rect5);
   SDL_RenderCopy(rend,face_alpha,NULL,&rect_alpha);
    SDL_Rect rect;//le cordonn谷 et la surface du fond
    rect.x=300;
    rect.y=0;
    rect.w=500;
    rect.h=500;
    SDL_Rect position;//le cordonn谷 et la surface des carr谷s
    position.x=40;
    position.y=40;
    position.w=20;
    position.h=20;
    SDL_RenderCopy(rend,face1,NULL,&rect);//mettre le fond dans le fen那tre
    SDL_Rect rect6;//le cordonn谷 et la surface de la photo qui v谷rifie le code words corrig谷
    rect6.w=100;
    rect6.h=100;
    rect6.x=525;
    rect6.y=225;
    int **qr = MAlloTableau_sdl2(21,21);//cr谷er un matrice de 21*21
    int **qr1 = MAlloTableau_sdl2(21,21);
    int x,y,x3=0;
    SDL_Event event;
    bool quit1= false;
    while(quit1==false){
            while(SDL_PollEvent(&event))
            {
              if(event.type==SDL_QUIT){
                quit1 = true;//quand on tape le bouton de fermer, fermer le fen那tre
              }
              if( event.type == SDL_MOUSEBUTTONDOWN){
                x = event.motion.x;
                y = event.motion.y;
                  if( ( x > rect4.x ) && ( x < rect4.w ) && ( y > rect4.y ) && ( y < rect4.h ) )
                  {
             SDL_RenderCopy(rend,face1,NULL,&rect);
             fflush(stdin);
             printf("Vous pouvez utiliser le mode_numerique pour créer le QR_code\n");
                char *mot_doux = malloc(256*sizeof(char)); int size=0, c;
        while ((c = getchar()) != '\n'){
            mot_doux[size] = c;
            size++;
        }

             printf("vous pouvez entrer maximum 34 nombres\n");
             bin=numerique(mot_doux, size);
             free(mot_doux);
                  }
                  if((x>rect5.x)&&(x<rect.w)&&(y>rect5.y)&&(y<(rect5.h+100)))
                   {
             SDL_RenderCopy(rend,face1,NULL,&rect);
             fflush(stdin);
             printf("Vous pouvez utiliser le mode_byte pour créer le QR_code\n");
             printf("vous pouvez entrer maximum 14 caractères\n");
                             char *mot_doux2 = malloc(256*sizeof(char)); int size2=0, c2;
        while ((c2 = getchar()) != '\n'){
            mot_doux2[size2] = c2;
            size2++;
        }
             bin=byte(mot_doux2, size2);
             free(mot_doux2);
                  }
                  if((x>rect_alpha.x)&&(x<rect_alpha.w)&&(y>rect_alpha.y)&&(y<(rect_alpha.h+200)))
                    {
             SDL_RenderCopy(rend,face1,NULL,&rect);
             fflush(stdin);
             printf("Vous pouvez utiliser le mode_alpha pour créer le QR_code\n");
             printf("vous pouvez entrer maximum 20 caractères\n");
          char *mot_doux3 = malloc(256*sizeof(char)); int size3=0, c3;
        while ((c3 = getchar()) != '\n'){
            mot_doux3[size3] = c3;
            size3++;
        }
             bin=alpha(mot_doux3, size3);
             free(mot_doux3);
                  }
                  masque_meilleur_sdl2(bin,qr,qr1,x3);
                  // printf("%d\n",x3);
                  mode_initiative_sdl2(qr);
                  application_masque_sdl2(qr1,x3);
                  data_sdl2(qr, 20, 20, bin);
                  infotext_sdl2(qr,x3);
                  for (x=0 ; x<21 ; x++){
                    for(y=0 ; y<21 ; y++){
                      if (qr[x][y]==1&&qr1[x][y]==1){
                          qr[x][y]=0;
                          qr1[x][y]=0;
                          }
                      if (qr[x][y]==0&&qr1[x][y]==1){
                          qr[x][y]=1;
                          }
                         }
                        }
                  for (x=0 ; x<21 ; x++){
                     for(y=0 ; y<21 ; y++){
                        if (qr[x][y] == 1){
                            position.x = 340+x*20;
                            position.y = 40+y*20;
                            SDL_RenderCopy(rend,face2,NULL,&position);//afficher les carr谷 noire
            }
        }
    }
       SDL_RenderCopy(rend,face7,NULL,&rect6);//afficher le photo pour v谷rifier le code words corrig谷
              }
             }
             SDL_Delay(50);
            SDL_RenderPresent(rend);
            }
    SDL_DestroyWindow(Window);
    SDL_Quit();


}
void masque_meilleur_sdl2(int *bin,int **qr,int **qr1,int x3){
 int x=0,y=0;
    int x1=0;
    int somme[8];
    for(x1=0;x1<8;x1++){
    mode_initiative_sdl2(qr);
    application_masque_sdl2(qr1,x1);
    data_sdl2(qr, 20, 20, bin);
    infotext_sdl2(qr,x1);
      for (x=0 ; x<21 ; x++){
            for(y=0 ; y<21 ; y++){
                if (qr[x][y]==1&&qr1[x][y]==1){
                    qr[x][y]=0;
                    qr1[x][y]=0;
                    }
                if (qr[x][y]==0&&qr1[x][y]==1){
                    qr[x][y]=1;
                }
            }
        }
            somme[x1]=evaluation_sdl2(qr,21,21);
            //printf("%d %d\n",x1,somme[x1]);
    }
     int x2=somme[0];
      for(x1=0;x1<8;x1++){
          if(somme[x1]<x2){
            x2=somme[x1];
            x3=x1;
          }
      }
}




