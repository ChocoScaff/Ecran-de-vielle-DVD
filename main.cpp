#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

void nomDeLaFenetre();

int main(int argc, char *argv[])
{
    int largeurDeLecran=1280,hauteurDeLecran=720,nombredecouleur=16;
    int hauteurLogo=178,largeurLogo=343;
    int vitesseX=1,vitesseY=1;
    char rouge = 0,vert = 255,bleu = 0;
    int continuer=1;
    SDL_Surface *ecran = NULL;
    SDL_Surface *imageDeFond = NULL;
    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO); // Initialisation de la SDL

    ecran=SDL_SetVideoMode(largeurDeLecran, hauteurDeLecran, nombredecouleur, SDL_HWSURFACE); // Ouverture de la fenêtre
    if (ecran == NULL) // Si l'ouverture a échoué, on le note et on arrête
    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    nomDeLaFenetre(); //nom Afficher au dessus la fenêtre

    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, rouge, vert, bleu)); // Coloration de la surface ecran

    //image au fond
    SDL_Rect logoDVD;
    //SDL_SetAlpha(logoDVD, SDL_SRCALPHA, 128);

    logoDVD.x = largeurDeLecran/2-largeurLogo/2; //On met le logo au milieu de l'écran
    logoDVD.y = hauteurDeLecran/2-hauteurLogo/2;

    /* Chargement d'une image Bitmap dans une surface */
    imageDeFond = SDL_LoadBMP("dvd.bmp");


    while(continuer)
    {
        logoDVD.x=logoDVD.x+vitesseX;
        logoDVD.y=logoDVD.y+vitesseY;
        SDL_BlitSurface(imageDeFond, NULL, ecran, &logoDVD);
        SDL_Flip(ecran); // Mise à jour de l'écran avec sa nouvelle couleur
        SDL_PollEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                //break;
        }
        if (logoDVD.y == hauteurDeLecran-hauteurLogo)
        {
            vitesseY=-1;
        }
        else if (logoDVD.y == 0)
        {
            vitesseY=1;
        }
        else if (logoDVD.x == 0)
        {
            vitesseX=1;
        }
        else if (logoDVD.x == largeurDeLecran-largeurLogo)
        {
            vitesseX=-1;
        }
    }

    SDL_Quit(); // Arrêt de la SDL

    return EXIT_SUCCESS; // Fermeture du programme
}

void nomDeLaFenetre()
{
    SDL_WM_SetCaption("DVD", NULL);
}
