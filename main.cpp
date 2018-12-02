#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "SDL/SDL.h"
#include "structures.h"
#include "transformations.c"
#include <SDL/SDL_ttf.h>

SDL_Surface* affichage; // variable globale !! C'est plus cool même si c'est pas très très joli


  ///------------------------------------------------///
 ///-------------------- MAIN ----------------------///
///------------------------------------------------///

int main(int argc, char** argv)
{
  while(1){
    int choix = menu();
    SDL_Surface *image = NULL;
    if (choix == 1)image = SDL_LoadBMP("images/joconde.bmp"); if (choix == 2)image = SDL_LoadBMP("images/stromae.bmp"); if (choix == 3)image = SDL_LoadBMP("images/gusta.bmp");
    if (choix == 4)image = SDL_LoadBMP("images/eisti.bmp"); if (choix == 5)image = SDL_LoadBMP("images/imageCodee.bmp");if (choix == 6)image = SDL_LoadBMP("images/messageCode.bmp");

    int tailleImg = tailleImage(image);
    initSDL(tailleImg);
    transformer(tailleImg,image);

   }
   return EXIT_SUCCESS;
}

  ///------------------------------------------------///
 ///-------------------- MENU ----------------------///
///------------------------------------------------///

int menu()
{
    initSDL(500);
    SDL_Event event; //pour pouvoir gerer les events
    SDL_Surface*Joconde = NULL,*Stromae = NULL,*Eisti = NULL,*Gusta = NULL, *Menu = NULL, *Decode = NULL, *Decode2 = NULL;
    SDL_Rect positionJoconde, positionStromae,positionGusta,positionEisti,positionMenu,positionDecode,positionDecode2;

    positionJoconde.x = 50; positionJoconde.y = 50; positionStromae.x = 200; positionStromae.y = 50; positionMenu.x = 20; positionMenu.y = 510;
    positionGusta.x = 350; positionGusta.y = 50; positionEisti.x = 50; positionEisti.y = 200; positionDecode.x = 200; positionDecode.y = 200;
    positionDecode2.x = 350; positionDecode2.y = 200;// positions

    Joconde = SDL_LoadBMP("images/menu/jocondeMenu.bmp"); Stromae = SDL_LoadBMP("images/menu/stromaeMenu.bmp");
    Gusta= SDL_LoadBMP("images/menu/gustaMenu.bmp"); Eisti = SDL_LoadBMP("images/menu/eistiMenu.bmp");
    Decode = SDL_LoadBMP("images/menu/decodeMenu.bmp"); Menu = SDL_LoadBMP("images/menu/menu.bmp");
    Decode2 = SDL_LoadBMP("images/menu/decodeMenu2.bmp");


    int xmouse = 0, ymouse = 0;


    while(1){

        SDL_FillRect(affichage, NULL, SDL_MapRGB(affichage->format, 255,255, 255));//Ecran blanc

        SDL_BlitSurface(Joconde, NULL, affichage, &positionJoconde); SDL_BlitSurface(Stromae, NULL, affichage, &positionStromae);
        SDL_BlitSurface(Gusta, NULL, affichage, &positionGusta); SDL_BlitSurface(Eisti, NULL, affichage, &positionEisti);
        SDL_BlitSurface(Decode, NULL, affichage, &positionDecode);SDL_BlitSurface(Menu, NULL, affichage, &positionMenu);
        SDL_BlitSurface(Decode2, NULL, affichage, &positionDecode2);
        SDL_Flip(affichage);

        SDL_GetMouseState( &xmouse, &ymouse );

        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
            exit(EXIT_FAILURE);
            break;

            case SDL_MOUSEBUTTONDOWN:
            if (xmouse<175 && ymouse < 175) return 1;
            if (xmouse>175 && xmouse < 325 && ymouse < 175) return 2;
            if (xmouse>325 && ymouse < 175) return 3;
            if (xmouse<175 && ymouse > 175 && ymouse < 325) return 4;
            if (xmouse>175 && xmouse < 325 && ymouse > 175 && ymouse < 325) return 5;
            if (xmouse>325 && ymouse > 175 && ymouse < 325) return 6;
            break;

            case SDL_MOUSEMOTION :

            if (xmouse<175 && ymouse < 175) SDL_SetAlpha( Joconde, SDL_SRCALPHA | SDL_RLEACCEL, 150 ); //transparence
            else SDL_SetAlpha( Joconde, SDL_SRCALPHA | SDL_RLEACCEL, 255 );
            if (xmouse>175 && xmouse<325 && ymouse < 175) SDL_SetAlpha( Stromae, SDL_SRCALPHA | SDL_RLEACCEL, 150 ); //transparence
            else SDL_SetAlpha( Stromae, SDL_SRCALPHA | SDL_RLEACCEL, 255 );
            if (xmouse>325 && ymouse < 175) SDL_SetAlpha( Gusta, SDL_SRCALPHA | SDL_RLEACCEL, 150 ); //transparence
            else SDL_SetAlpha( Gusta, SDL_SRCALPHA | SDL_RLEACCEL, 255 );
            if (xmouse<175 && ymouse > 175 && ymouse < 325) SDL_SetAlpha( Eisti, SDL_SRCALPHA | SDL_RLEACCEL, 150 ); //transparence
            else SDL_SetAlpha( Eisti, SDL_SRCALPHA | SDL_RLEACCEL, 255 );
            if (xmouse>175 && xmouse < 325 && ymouse > 175 && ymouse < 325)  SDL_SetAlpha( Decode, SDL_SRCALPHA | SDL_RLEACCEL, 150 ); //transparence
            else SDL_SetAlpha( Decode, SDL_SRCALPHA | SDL_RLEACCEL, 255 );
            if (xmouse>325 && ymouse > 175 && ymouse < 325) SDL_SetAlpha( Decode2, SDL_SRCALPHA | SDL_RLEACCEL, 150 ); //transparence
            else SDL_SetAlpha( Decode2, SDL_SRCALPHA | SDL_RLEACCEL, 255 );
            break;

            case SDL_KEYDOWN :
            switch(event.key.keysym.sym)
            {
                case SDLK_ESCAPE:
                    exit(EXIT_FAILURE);
                break;

                default :
                break;
            }
            break;


        }
    }
}

  ///------------------------------------------------///
 ///--------------- TAILLE IMAGE -------------------///
///------------------------------------------------///

int tailleImage(SDL_Surface *image)
{

    int i = 0;
    while (getpixel(image,0, i)) i++;
    return i;

}

  ///------------------------------------------------///
 ///--------------INITIALISATION SDL ---------------///
///------------------------------------------------///

void initSDL(int tailleImg)
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    fprintf(stderr, "Erreur à l'initialisation de la SDL : %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }

  atexit(SDL_Quit);
  affichage = SDL_SetVideoMode(tailleImg, tailleImg+150, 32, SDL_SWSURFACE);

  if (affichage == NULL) {
    fprintf(stderr, "Impossible d'activer le mode graphique : %s\n", SDL_GetError());
    exit(EXIT_FAILURE);
  }
  SDL_WM_SetIcon(SDL_LoadBMP("images/icone.bmp"), NULL);//icone
  SDL_WM_SetCaption("Les Transformations Bijectives d'Images", NULL);
}

  ///------------------------------------------------///
 ///-------------- ATTENDRE TOUCHE -----------------///
///------------------------------------------------///

int attendreTouche(int *enfoncee, int tailleImg,int *choix)
{

  int xmouse = 0, ymouse = 0;

  SDL_Event event;
  do{

    SDL_GetMouseState( &xmouse, &ymouse );
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT) exit(EXIT_FAILURE);
    if (event.type == SDL_MOUSEBUTTONDOWN){
                if (event.button.button == SDL_BUTTON_LEFT && xmouse<tailleImg && ymouse<tailleImg) return 0;
                if (event.button.button == SDL_BUTTON_RIGHT && xmouse<tailleImg && ymouse<tailleImg) return 1;
    }
    if (event.type == SDL_KEYDOWN){
        switch(event.key.keysym.sym)
        {
            case SDLK_RIGHT: // Flèche droite
                *enfoncee = 0;
            break;
            case SDLK_LEFT: // Flèche gauche
                *enfoncee = 1;
            break;
            case SDLK_ESCAPE:
                *enfoncee = 2;
                return -1;
            break;
            default:
            break;
        }
    }
    if (event.type == SDL_KEYUP){
        switch(event.key.keysym.sym)
        {
            case SDLK_RIGHT: // Flèche droite
                *enfoncee = -1;
            break;
            case SDLK_LEFT: // Flèche gauche
                *enfoncee = -1;
            break;
            default:
            break;
        }
    }

     switch(event.type)
        {
            case SDL_MOUSEBUTTONDOWN:
            if (xmouse< tailleImg/2 && ymouse > tailleImg && ymouse < tailleImg+75){
                *choix = 1;
                return 5;
            }
            if (xmouse> tailleImg/2 && ymouse > tailleImg && ymouse < tailleImg+75){
                *choix = 2;
                return 5;
            }
            if (xmouse> tailleImg/2+100 && ymouse > tailleImg+75){
                *enfoncee = 0;
            }
            if (xmouse< tailleImg/2-100 && ymouse > tailleImg+75){
                *enfoncee = 1;
            }
            if (xmouse> tailleImg/2-100 && xmouse< tailleImg/2+100 && ymouse > tailleImg+75){
                *enfoncee = -1;
                return 5;
            }
            break;

        }

    if (*enfoncee == 0) return 0;
    if (*enfoncee == 1) return 1;

    }while (1);

    return -1;//vire le warning mais sert à rien :D
}



      ///----------------------------------------------///
     ///------------- TRANSFORMER IMAGE --------------///
    ///----------------------------------------------///
   /// J'arrive pas à mettre en parametre les       ///
  /// tableaux qui contiennent une image (Uint32)  ///
 /// donc pas d'autres fonctions...  NAILED IT    ///
///----------------------------------------------///

void transformer(int tailleImg,SDL_Surface *image)
{

    Uint32 **tableauImage = NULL; //ALLOCATION DYNAMIQUE A 2DIMENSIONS MAGGLE
    tableauImage = new Uint32*[tailleImg];
    for(int i=0;i<tailleImg;i++) tableauImage[i] = new Uint32 [tailleImg];


    //Init TTF
    char caracteres[40] = ""; // Tableau de char suffisamment grand
    TTF_Init(); //Initialisation de la banque de donnée pour le texte
    SDL_Surface *tours = NULL, *boutonPhotomaton = NULL, *boutonBoulanger = NULL, *boutonDroite = NULL, *boutonGauche = NULL, *boutonStop = NULL;
    SDL_Rect position, positionPhotomaton, positionBoulanger, positionDroite, positionGauche, positionStop;
        position.x = 20; position.y = 0;
        positionPhotomaton.x = 20; positionPhotomaton.y = tailleImg+20;
        positionBoulanger.x = tailleImg-229; positionBoulanger.y = tailleImg+20;
        positionGauche.x = 20; positionGauche.y = tailleImg+80;
        positionDroite.x = tailleImg-229; positionDroite.y = tailleImg+80;
        positionStop.x = tailleImg/2-50; positionStop.y = tailleImg+80;
        boutonPhotomaton = SDL_LoadBMP("images/boutons/photomaton.bmp");
        boutonBoulanger = SDL_LoadBMP("images/boutons/boulanger.bmp");
        boutonDroite = SDL_LoadBMP("images/boutons/flecheD.bmp");
        boutonGauche = SDL_LoadBMP("images/boutons/flecheG.bmp");
        boutonStop = SDL_LoadBMP("images/boutons/stop.bmp");

    TTF_Font *police = NULL; //TTF_OpenFont doit stocker son résultat dans une variable de type TTF_Font
    SDL_Color couleurRouge = {255, 0, 0}; //couleur police => Rouge
    police = TTF_OpenFont("tours.ttf", 50);//police choisie, taille police
    int compteurP = 0, compteurB = 0; //compteur de tours
    int retour = 0; //bool pour savoir si on va dans le sens inverse ou non
    int choix = 1; ;// choix de la transformation

    if(TTF_Init() == -1)
    {

        fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }//En cas d'erreur (plus propre)


    Uint32 tableauImageBase[tailleImg]; //tableau qui ne bougera pas qui contient l'image de base
    //Initialisation image
    for (int i = 0; i < tailleImg; i++){
        tableauImageBase[i] = getpixel(image,i, 1);
        for (int j = 0; j < tailleImg; j++)
            setPixel(i, j,getpixel(image,i, j));
    }


    int enfoncee = -1;//Pour pouvoir rester appuyé et defiler le machin
    int continuer = 1; int verif = 1;

    while(continuer){


        //SDL_SaveBMP(affichage,"images/save.bmp");// On sauvegarde l'image codée

        //On enregistre l'image affichée dans le tableau
        if (retour != 5)
            for (int i = 0; i < tailleImg; i++)
                for (int j = 0; j < tailleImg; j++)
                    tableauImage[i][j] = getpixel(affichage,i, j);


        //On regarde si c'est l'image de base (vrai de base)
        verif = 1;
        for (int i = 0; i < tailleImg; i++)if (tableauImage[i][1] != tableauImageBase[i]) verif = 0;
        if (verif == 1) enfoncee = -1; // On arrete si l'image est celle de base

         //boutons
        if (choix == 1) SDL_SetAlpha( boutonPhotomaton, SDL_SRCALPHA | SDL_RLEACCEL, 150 ); //transparence
        else SDL_SetAlpha( boutonPhotomaton, SDL_SRCALPHA | SDL_RLEACCEL, 255 );
        if (choix == 2) SDL_SetAlpha( boutonBoulanger, SDL_SRCALPHA | SDL_RLEACCEL, 150 ); //transparence
        else SDL_SetAlpha( boutonBoulanger, SDL_SRCALPHA | SDL_RLEACCEL, 255 );
        if (enfoncee == -1) SDL_SetAlpha( boutonStop, SDL_SRCALPHA | SDL_RLEACCEL, 150 ); //transparence
        else SDL_SetAlpha( boutonStop, SDL_SRCALPHA | SDL_RLEACCEL, 255 );
        if (enfoncee == 0) SDL_SetAlpha( boutonDroite, SDL_SRCALPHA | SDL_RLEACCEL, 150 ); //transparence
        else SDL_SetAlpha( boutonDroite, SDL_SRCALPHA | SDL_RLEACCEL, 255 );
        if (enfoncee == 1) SDL_SetAlpha( boutonGauche, SDL_SRCALPHA | SDL_RLEACCEL, 150 ); //transparence
        else SDL_SetAlpha( boutonGauche, SDL_SRCALPHA | SDL_RLEACCEL, 255 );
        SDL_BlitSurface(boutonPhotomaton, NULL, affichage, &positionPhotomaton);
        SDL_BlitSurface(boutonBoulanger, NULL, affichage, &positionBoulanger);
        SDL_BlitSurface(boutonGauche, NULL, affichage, &positionGauche);
        SDL_BlitSurface(boutonDroite, NULL, affichage, &positionDroite);
        SDL_BlitSurface(boutonStop, NULL, affichage, &positionStop);


        //nombre de tours
        sprintf(caracteres, "%d: P  %d: B", compteurP,compteurB);
        tours = TTF_RenderText_Solid(police, caracteres, couleurRouge);
        SDL_BlitSurface(tours, NULL, affichage, &position); /* Blit du texte*/






        SDL_Flip(affichage);
        retour = attendreTouche(&enfoncee,tailleImg,&choix);
        if (verif == 1) { compteurP = 0; compteurB = 0; }//Si on a fait un tour, on reprend à 0 !

        //Ecran noir, on efface tout pour remettre du propre !
        SDL_FillRect(affichage, NULL, SDL_MapRGB(affichage->format, 0,0,0));


			if(retour == 0)
			{
				if(choix == 1) compteurP++;
				if(choix == 2) compteurB++;
			}
			if (retour == 1)
			{
				if(choix == 1) compteurP--;
				if(choix == 2) compteurB--;
			}


        if(choix==1) photomaton(tableauImage,tailleImg,retour);
        if(choix==2) boulanger(tableauImage,tailleImg,retour);





        //Pour le changement, réafficher la même image
        if (retour == 5 )
            for (int i = 0; i < tailleImg; i++)
                for (int j = 0; j < tailleImg; j++)
                    setPixel(i,j,tableauImage[i][j]);

        if (enfoncee == 2) continuer = 0;//pour sortir de la boucle en appuyant sur ESCAPE


    }
}


  ///------------------------------------------------///
 ///----------------- SET PIXEL --------------------///
///------------------------------------------------///

void setPixel(int x, int y, Uint32 coul)
{
  *((Uint32*)(affichage->pixels) + x + y * affichage->w) = coul;
}


  ///------------------------------------------------///
 ///----------------- GET PIXEL --------------------///
///------------------------------------------------///

Uint32 getpixel(SDL_Surface *surface, int x, int y)
{
    int bpp = surface->format->BytesPerPixel;

    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        return *p;
        break;

    case 2:
        return *(Uint16 *)p;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;
        break;

    case 4:
        return *(Uint32 *)p;
        break;

    default:
        return 0;
    }
}


