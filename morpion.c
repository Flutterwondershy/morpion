#include "morpion.h"

void mInitialisation(char jeu[3][3])
{
    int i=0,j=0;
    for(; i < 3; i++)
        for(j = 0;j < 3; j++)
            jeu[i][j] = ' ';
}

int mChoix(char jeu[3][3], int x, int y, int joueur)
{
    if(x >= 1 && x <= 3 && y >= 1 && y <= 3 && (joueur == 1 || joueur == 2) && jeu[y-1][x-1] == ' ')
    {
        jeu[y-1][x-1] = (joueur == 1) ? 'X' : 'O';
        return 1;
    }
    else return 0;

}

int mVainqueur(char jeu[3][3])
{
    int i = 0;
    for(; i < 3; i++)
    {
        if  (
                (jeu[i][0] != ' ' && jeu[i][0] == jeu[i][1] && jeu[i][0] == jeu[i][2])||
                (jeu[0][i] != ' ' && jeu[0][i] == jeu[1][i] && jeu[0][i] == jeu[2][i])
            )
            return 1;
    }

    if (
            (jeu[0][0] != ' ' && jeu[0][0] == jeu[1][1] && jeu[0][0] == jeu[2][2]) ||
            (jeu[0][2] != ' ' && jeu[0][2] == jeu[1][1] && jeu[0][2] == jeu[2][0])
       )
        return 1;

    return 0;
}

void mAfficher(char jeu[3][3])
{
    int i = 0;
    printf("  -   -   -\n");
    for(; i <3; i++)
        printf("| %c | %c | %c |\n"
               "  -   -   -\n",
               jeu[i][0], jeu[i][1], jeu[i][2]);
}
int mChoixAlgo(char jeu[3][3], char lettre)
{
    int y, x, i, j, countL = 0, countSpace = 0; //jeu[y,x] et count[?] est le compteur
    char lettreAdverse = (lettre == 'X') ? 'O' : 'X';

    if(lettre != 'X' && lettre != 'O') return 0;

    ///////////////////On voit si on peut gagner
    //HORIZONTAL
    for(i=0; i < 3; i++)
    {
        for(j=0, countSpace = 0, countL = 0; j<3; j++)
        {
            if(jeu[i][j] == ' ')
            {
                countSpace++;
                y=i;x=j;
            }
            else if(jeu[i][j] == lettre) countL++;
        }
        if(countL == 2 && countSpace == 1)
        {
            jeu[y][x] = lettre;
            return 1;
        }
    }

    //VERTICAL
    for(i=0; i < 3; i++)
    {
        for(j=0, countSpace = 0, countL = 0; j<3; j++)
        {
            if(jeu[j][i] == ' ')
            {
                countSpace++;
                y=j;x=i;
            }
            else if(jeu[j][i] == lettre) countL++;
        }
        if(countL == 2 && countSpace == 1)
        {
            jeu[y][x] = lettre;
            return 1;
        }
    }

    //DIAGONALES
    for(i=0, countL = 0, countSpace = 0; i < 3; i++)
    {
        if(jeu[i][i] == ' ')
        {
            countSpace++;
            y=x=i;
        }
        else if(jeu[i][i] == lettre)
            countL++;
    }
    if(countL == 2 && countSpace == 1)
    {
        jeu[y][x] = lettre;
        return 1;
    }
    for(i=0, countL=0, countSpace=0; i<3; i++)
    {
        if(jeu[i][2-i] == ' ')
        {
            countSpace++;
            y=i;x=i-2;
        }
        else if(jeu[i][2-i] == lettre)
            countL++;
    }
    if(countL == 2 && countSpace == 1)
    {
        jeu[y][x] = lettre;
        return 1;
    }

    //On empêche l'autre de gagner avant d'essayer de gagner
    //HORIZONTAL
    for(i=0; i < 3; i++)
    {
        for(j=0, countSpace = 0, countL = 0; j<3; j++)
        {
            if(jeu[i][j] == ' ')
            {
                countSpace++;
                y=i;x=j;
            }
            else if(jeu[i][j] == lettreAdverse) countL++;
        }
        if(countL == 2 && countSpace == 1)
        {
            jeu[y][x] = lettre;
            return 1;
        }
    }

    //VERTICAL
    for(i=0; i < 3; i++)
    {
        for(j=0, countSpace = 0, countL = 0; j<3; j++)
        {
            if(jeu[j][i] == ' ')
            {
                countSpace++;
                y=j;x=i;
            }
            else if(jeu[j][i] == lettreAdverse) countL++;
        }
        if(countL == 2 && countSpace == 1)
        {
            jeu[y][x] = lettre;
            return 1;
        }
    }
    //DIAGONALES
    for(i=0, countL = 0, countSpace = 0; i < 3; i++)
    {
        if(jeu[i][i] == ' ')
        {
            countSpace++;
            y=x=i;
        }
        else if(jeu[i][i] == lettreAdverse)
            countL++;
    }
    if(countL == 2 && countSpace == 1)
    {
        jeu[y][x] = lettre;
        return 1;
    }
    for(i=0, countL=0, countSpace=0; i<3; i++)
    {
        if(jeu[i][2-i] == ' ')
        {
            countSpace++;
            y=i;x=2-i;
        }
        else if(jeu[i][2-i] == lettreAdverse)
            countL++;
    }
    if(countL == 2 && countSpace == 1)
    {
        jeu[y][x] = lettre;
        return 1;
    }

    //si rien ne va plus, autant parcourir tout le tableau et dès qu'on tombe sur un vide, on plonge dedans
    for(i=0; i <3;i++)
        for(j=0; j <3;j++)
            if(jeu[i][j] == ' ')
            {
                jeu[i][j] = lettre;
                return 1;
            }
    return 0; //Aucune case libre
}

int mTableauPlein(char jeu[3][3])
{
    int i=0,j=0;
    for(;i<3;i++)
        for(j=0;j<3;j++)
            if(jeu[i][j] == ' ')
                return 0;
    return 1;
}
