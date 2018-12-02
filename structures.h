void initSDL(int tailleImg);
int attendreTouche(int *enfoncee, int tailleImg,int *choix);
void setPixel(int x, int y, Uint32 coul);
void transformer(int tailleImg,SDL_Surface *image);
int tailleImage(SDL_Surface *image);
int menu();
Uint32 getpixel(SDL_Surface *surface, int x, int y);
SDL_Surface *rotozoomSurface(SDL_Surface * src, double angle, double zoom, int smooth);
void photomaton(Uint32 **tableauImage,int tailleImg,int retour);
void boulanger(Uint32 **tableauImage,int tailleImg,int retour);

