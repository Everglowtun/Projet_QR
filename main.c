/*Est-il nécessaire de précisé l'utilité d'un fichier dont on
ne fait plus la réputation du nom ?
main.c - Projet QR de Jia Lei et Guilhem.*/


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "mode_numerique.c"
#include "mode_byte.c"
#include "mode_alpha.c"

#include "masking.c"
#include "manipulation.h"
#include "graphique.c"



int main(int ac, char **av){
    printf("Bienvenue ! Chargement en cours...\n");
    int **qr = MAlloTableau(21,21); //Mallocation du tableau principal
    TableauCopier(qr); //Récupération des valeurs qui ne changeront pas
    int *bin = malloc(208*sizeof(int)), i;

    if (ac == 3){
        if (strcmp(av[2],"N") == 0){
            printf("Utilisation du mode numérique. Attention, ce mode n'est pas reconnu par tous les scanneurs.\n");
            bin = numerique(av[1], strlen(av[1]));
        } 
        else if (strcmp(av[2],"A") == 0){
            printf("Utilisation du mode alphanumérique. Attention, ce mode n'est pas reconnu par tous les scanneurs.\n");
            bin = alpha(av[1], strlen(av[1]));
        } 
    }
    else if (ac == 2){
        printf("Utilisation par défaut du mode 8-bits. Pour utiliser les modes numérique ou alphanumérique, mettez 'N' ou 'A' en argument avec votre texte. A vos risques et périls.\n");
        bin = byte(av[1], strlen(av[1]));
    }
    else{
        printf("Utilisation par défaut du mode 8-bits. Pour utiliser les modes numérique ou alphanumérique, mettez 'N' ou 'A' en argument avec votre texte. A vos risques et périls.\n");
        printf("Spécifiez maintenant le texte à encoder...\n");
        char *mot_doux = malloc(256*sizeof(char)); int size=0, c;
        while ((c = getchar()) != '\n'){
            mot_doux[size] = c;
            size++;
        }
        for (int i=0 ; i<size ; i++){
            printf("%c", mot_doux[i]);
        }
        bin = byte(mot_doux, size);
    }

    data(qr, 20, 20, bin); //Ajout des données sur le QR principal
    masque(qr, 21, 21); //Application du masquage

    if (ac >= 2) graph(av[1], strlen(av[1]), qr);
    else graph("[Secret]", 8, qr);
}