//
// Created by tomco on 24/11/2021.
//
//
// Created by tomco on 15/11/2021.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define Ligne 4
#define Colonne 8

typedef struct{
    int x,y;
    int couleur;
    int forme;
    struct Joueur* numero;
}Pion;


/*typedef struct{

    char Nom[100];
    int nbMaison;
    int nbHotel;
    int disponible;


}Propriété;*/



typedef struct{

    //int x,y;
    int* numero;
    char Nom;
    int* type;
    int maison;

}Case;

typedef struct{
    struct Pion* x;
    struct Pion* y;
    int numero;
    char Nom[100];
    int argent;

}Joueur;



#ifndef PROJETINFO_FONCTION_H
#define PROJETINFO_FONCTION_H
void red ();
void grey();
void yellow();
void blue();
void purple();
void green();
void cyan();
void reset ();
char* getCharOfForme(int forme);
char* getCodeCouleur(int couleur);
void plateaudejeux();
void Menu();
int LancerDes();
int initialisationDesJoueur();
void nomUtilisateur(char utilisateur[100]);
void TableauJoueur(int nombredejoueur, Joueur tabJoueur[]);
#endif //PROJETINFO_FONCTION_H
