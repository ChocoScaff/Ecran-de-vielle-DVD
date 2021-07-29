#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

#define largeurDeLecran 1280
#define hauteurDeLecran 720
#define nombredecouleur 16
#define hauteurLogo 178
#define largeurLogo 343
#define couleurDeFondRouge 0
#define CouleurDeFondVert 0
#define CouleurDeFondBleu 0

void nomDeLaFenetre();

int main(int argc, char *argv[])
{
    int vitesseX=1,vitesseY=1;
    char continuer=1;

    SDL_Surface *ecran = NULL; //pointeur pour l'écran de la fenêtre
    SDL_Surface *logoDVD = NULL; //pointeur pour le logo du DVD
    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO); // Initialisation de la SDL

    ecran=SDL_SetVideoMode(largeurDeLecran, hauteurDeLecran, nombredecouleur, SDL_HWSURFACE); // Ouverture de la fenêtre
    if (ecran == NULL) // Si l'ouverture a échoué, on le note et on arrête
    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    nomDeLaFenetre(); //nom Afficher au dessus la fenêtre

    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, couleurDeFondRouge, CouleurDeFondVert, CouleurDeFondBleu)); // Coloration de la surface ecran RGB

    //image au fond
    SDL_Rect positionLogoDVD;

    positionLogoDVD.x = largeurDeLecran/2-largeurLogo/2; //On met le logo au milieu de l'écran
    positionLogoDVD.y = hauteurDeLecran/2-hauteurLogo/2;

    /* Chargement d'une image Bitmap dans une surface */
    logoDVD = SDL_LoadBMP("dvd.bmp");

    while(continuer)
    {
        positionLogoDVD.x=positionLogoDVD.x+vitesseX;
        positionLogoDVD.y=positionLogoDVD.y+vitesseY;
        SDL_BlitSurface(logoDVD, NULL, ecran, &positionLogoDVD); // On met le Logo ou la le pointeur du DVD est situer
        SDL_Flip(ecran); // Mise à jour de l'écran avec sa nouvelle couleur
        SDL_PollEvent(&event);  //On entre dans la boucle quand il y'a un évenement
        switch(event.type)
        {
            case SDL_QUIT: // Si l'évenment est de quitter le logiciel
                continuer = 0;
        }
        if (positionLogoDVD.y == (hauteurDeLecran-hauteurLogo))
        {
            vitesseY=-1; //Vers le bas
        }
        else if (positionLogoDVD.y == 0)
        {
            vitesseY=1; //Vers le haut
        }
        else if (positionLogoDVD.x == 0)
        {
            vitesseX=1;//Vers la droite
        }
        else if (positionLogoDVD.x == (largeurDeLecran-largeurLogo))
        {
            vitesseX=-1;//Vers la gauche
        }
    }

    SDL_Quit(); // Arrêt de la SDL

    return EXIT_SUCCESS; // Fermeture du programme
}

void nomDeLaFenetre()
{
    SDL_WM_SetCaption("DVD", NULL);
}
