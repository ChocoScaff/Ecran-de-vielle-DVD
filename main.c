#include <stdio.h>
#include "sdl2.h"

#define droite 10
#define gauche -10
#define haut -10
#define bas 10

int main ( int argc, char** argv )
{
    char vitesseX=droite,vitesseY=haut;
    int xDVD,yDVD;
    char continuer=0;

    Ecran ecran = creationEcran();

    Image dvd = creationImage("dvd.bmp");

    xDVD = (X_SCREEN/2-(largImage(dvd)/2));
    yDVD = (Y_SCREEN/2-(hautImage(dvd)/2));

    while(!continuer)
    {
        evenements();

        continuer = etatClavier[SDL_SCANCODE_ESCAPE];

        if (xDVD <= 0)
        {
            vitesseX=droite;
        }
        else if (xDVD >= X_SCREEN-largImage(dvd))
        {
            vitesseX=gauche;
        }
        else if (yDVD <= 0)
        {
            vitesseY=bas;
        }
        else if (yDVD >= Y_SCREEN-hautImage(dvd))
        {
            vitesseY=haut;
        }
        xDVD=xDVD+vitesseX;
        yDVD=yDVD+vitesseY;
        effaceEcran(ecran);
        dessineImage(ecran,xDVD,yDVD,dvd);
        miseAJourEcran(ecran);
    }
    destructionImage(dvd);
    destructionEcran(ecran);
}
