#ifndef MORPION_H_INCLUDED
#define MORPION_H_INCLUDED
    #include<stdio.h>
    void mInitialisation(char jeu[3][3]);
    int mChoix(char jeu[3][3], int x, int y, int joueur);//renvoi un bool disant si le choix est bon
    int mVainqueur(char jeu[3][3]); //renvoi 0 si pas de vainqueur sinon 1
    void mAfficher(char jeu[3][3]);
    int mChoixAlgo(char jeu[3][3], char lettre);
    int mTableauPlein(char jeu[3][3]);
#endif // MORPION_H_INCLUDED
