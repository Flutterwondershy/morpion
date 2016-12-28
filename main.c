#include <stdio.h>

#include "morpion.h"


int main(int argc, char* argv[])
{	
	char jeu[3][3];
    int joueur = 2; //On commence par le joueur 1 donc on met 2
    char multi = getchar();
    int x, y;

    while(getchar() != '\n');


    mInitialisation(jeu);

    do
    {
        joueur = (joueur == 1) ? 2 : 1;
        if(joueur == 2)
            mChoixAlgo(jeu, 'O');
       else
        {
        	do
        	{
	        	printf("Entrez les coordonnées sous la forme: 'x,y'\n");
	        	while(getchar() != '\n');
	        	scanf("%d,%d", &x, &y);
            } while(!mChoix(jeu, x, y, joueur));
        }
        mAfficher(jeu);
    } while(!mVainqueur(jeu) && !mTableauPlein(jeu));
	
	return 0;
}
