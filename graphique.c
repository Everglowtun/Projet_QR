/*
Le module Graphique contient les focntions nécessaires à l'affichage
du code QR par la SDL.
*/

#include <SDL/SDL.h>
#include <stdbool.h>

void attendre(){
    /* attendre de la SDL
    Nécessite stdbool.h ET sdl.h*/
    bool continuer = true;
    SDL_Event event;

    while(continuer){
        SDL_WaitEvent(&event);
        switch (event.type){
            case SDL_QUIT:
                continuer = false;
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT) continuer = false;
                break;
        }
    }
}


int graph(char *texte, int tailletexte, int **qr){
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        fprintf(stderr, "Criqrtique : erreur d'initialisation de la SDL : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    atexit(SDL_Quit); //Ceci arrivera dans tous les cas à la sortie du programme (sauf return au-dessus).

    //Ecran
    SDL_Surface *ecran = NULL;
    ecran = SDL_SetVideoMode(500, 500, 8, SDL_HWSURFACE | SDL_NOFRAME);
    if  (ecran == NULL){
        fprintf(stderr, "Critique : erreur lors du chargement du mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    
    //Titre de la fenêtre
    if (strlen(texte) != 0){
        char *str=NULL; //adapter au texte avec malloc
        str = malloc(tailletexte + 28);
        strcpy(str, "Un code QR qui signifie \"");
        strcat(str, texte);
        strcat(str, "\"");
        SDL_WM_SetCaption(str, NULL); //mettre une image à la place de NULL
    }
    else SDL_WM_SetCaption("Code", NULL);

    //Couleur de l'écran
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255)); //Couleur de fond : blanc
   
    //On créé un carré noir
    SDL_Surface *carre=NULL;
    carre = SDL_CreateRGBSurface(SDL_HWSURFACE, 20, 20, 8, 0, 0, 0, 0);
    SDL_FillRect(carre, NULL, SDL_MapRGB(carre->format, 0, 0, 0)); //carré de couleur noire

    SDL_Rect position;
    //Blittage du QR sur l'écran
    int x, y ; for (x=0 ; x<21 ; x++){
        for(y=0 ; y<21 ; y++){
            if (qr[x][y] == 1 || qr[x][y] == 4){
                position.x = (x+2)*20;
                position.y = (y+2)*20;
                SDL_BlitSurface(carre, NULL, ecran, &position);
            }
        }
    }

    SDL_Flip(ecran); //FLIP. Actualiser l'écran. A METTRE APRES
    SDL_FreeSurface(carre); //Libération à faire à la fin car contrairement à ecran, carre ne se libère pas tout seul avec SDL_Quit
    attendre();

    return EXIT_SUCCESS;
}





/*InterfaceQR et FinderPatterns sont pour le futur

void InterfaceQR(int **pattern, int tx, int ty, int **qr, int x, int y){
    /*Une interface de copie de tableau dans le QR. Attention : InterfaceQR suppose que vous savez ce que vous faîtes.
    pattern est à copier, qr est le code. x et y les coordonnées exactes (incluant 0;0) où
    copier le pattern dans le code et tx et ty la taille exacte (incluant 0;0) du tableau de pattern.*/
/*    int i, j;
    for (i=0 ; i<=x+tx ; i++){
        for (j=0 ; j<=y+ty ; j++){
            qr[y+j][x+i] = pattern[i][j];
        }
    }
}

void FinderPatterns(int **qr, int tx, int ty){
    /*Place les Finder Patterns dans le QR.
    Prend en argument le QR et sa taille*/
    //int **finder = MAlloTableau(7, 7);
/*    int pattern[7][7] =    {1, 1, 1, 1, 1, 1, 1,
                            1, 0, 0, 0, 0, 0, 1,
                            1, 0, 1, 1, 1, 0, 1,
                            1, 0, 1, 1, 1, 0, 1,
                            1, 0, 1, 1, 1, 0, 1,
                            1, 0, 0, 0, 0, 0, 1,
                            1, 1, 1, 1, 1, 1, 1}
    free(finder);
}
*/