
  ///------------------------------------------------///
 ///---------------- PHOTOMATON --------------------///
///------------------------------------------------///

void photomaton(Uint32 **tableauImage,int tailleImg,int retour)
{
            if (retour == 0 ){ //ordre normal
                for (int i = 0; i < tailleImg; i++)
                    for (int j = 0; j < tailleImg; j++){

                        if (i%2 == 0 && j%2 == 0) setPixel(i/2, j/2,tableauImage[i][j]);
                        if (i%2 != 0 && j%2 == 0) setPixel(i/2+tailleImg/2, j/2,tableauImage[i][j]);
                        if (i%2 == 0 && j%2 != 0) setPixel(i/2, j/2+tailleImg/2,tableauImage[i][j]);
                        if (i%2 != 0 && j%2 != 0) setPixel(i/2+tailleImg/2, j/2+tailleImg/2,tableauImage[i][j]);
                    }
            }

            if (retour == 1 ){ //ordre inverse
                for (int i = 0; i < tailleImg; i++)
                    for (int j = 0; j < tailleImg; j++){
                        if (i<tailleImg/2 && j<tailleImg/2) setPixel(i*2, j*2,tableauImage[i][j]);
                        if (i>tailleImg/2-1 && j<tailleImg/2) setPixel((i-tailleImg/2)*2+1, j*2,tableauImage[i][j]);
                        if (i<tailleImg/2 && j>tailleImg/2-1) setPixel(2*i, (j-tailleImg/2)*2+1,tableauImage[i][j]);
                        if (i>tailleImg/2-1 && j>tailleImg/2-1) setPixel((i-tailleImg/2)*2+1, (j-tailleImg/2)*2+1,tableauImage[i][j]);
                    }
            }
}

  ///------------------------------------------------///
 ///----------------- BOULANGER --------------------///
///------------------------------------------------///

void boulanger(Uint32 **tableauImage,int tailleImg,int retour)
{
            if (retour == 0 ){ //ordre normal
                for (int i = 0; i < tailleImg; i++)
                    for (int j = 0; j < tailleImg; j++){
                        if((j%2 == 0) && (i*2 < tailleImg)) setPixel(i*2, j/2,tableauImage[i][j]);
                        if((j%2 != 0) && (i*2+1 < tailleImg)) setPixel(i*2+1, j/2,tableauImage[i][j]);
                        if((j%2 == 0) && (i*2 >= tailleImg)) setPixel(tailleImg-(i*2)-1, (2*tailleImg-j)/2,tableauImage[i][j]);
                        if((j%2 != 0) && (i*2+1 >= tailleImg)) setPixel(tailleImg-(i*2+1)-1, (2*tailleImg-j)/2+1,tableauImage[i][j]);
                    }

            }

            if (retour == 1 ){ //ordre inverse
                for (int j = 0; j < tailleImg; j++)
                    for (int i = 0; i < tailleImg; i++){
                        if((i%2 == 0) && (j*2 < tailleImg)) setPixel(i/2, j*2,tableauImage[i][j]);
                        if((i%2 != 0) && (j*2+1 < tailleImg)) setPixel(i/2, j*2+1,tableauImage[i][j]);
                        if((i%2 == 0) && (j*2 >= tailleImg)) setPixel((2*tailleImg-i)/2-1, (tailleImg-j-1)*2+1,tableauImage[i][j]);
                        if((i%2 != 0) && (j*2+1 >= tailleImg)) setPixel((2*tailleImg-i)/2, (tailleImg-j-1)*2,tableauImage[i][j]);
                    }
            }
}
