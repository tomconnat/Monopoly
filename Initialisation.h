#include <stdio.h>

#define NB_CARTE 10
typedef struct {
    int numero;
    char *nom;
    int prix;
} Maison;

typedef struct {
    int numero;
    char *nom;
    int prix;
} Hotel;

typedef struct {
    int id;
    char *type;
    char *descriptif;
} Cartes;

typedef struct {
    int forme;
    int position;
} Pion;
typedef struct {
    int numero;
    char *nom;
} Case;
typedef struct {
    int etat; // disponibilite : 1 (oui) 0 (non)
    int prix;
    int groupe;//
    int numero;// Surement remplacer pars chaine de Caractere en fct du theme
    Case *pCase; // pointeur sur la case propriete
    Maison *pMaison[4];
    Hotel *hotel;
    char *titre;
    int type; // 0 a 6 :
} Propriete;
typedef struct {
    char nom[10];
    int argent;
    int etat; //pour compter les tours en prison cad 0 : libre et 1-2-3 prison
    int nbProp;
    Pion *pPion;
    Propriete *pPropriete;
    Cartes *pCarte;
} Joueur;

#ifndef UNTITLED5_INITILISATION_H
#define UNTITLED5_INITILISATION_H

void InitialisationProprietes(Propriete propriete[16], Case plateau[32]);

void InitialisationPioche(Cartes *piocheChance, Cartes *piocheCommunaute);

void InitialisationPlateau(Case plateau[32]);

void InitialisationPions(int nb, Pion pions[nb]);

void InitialisationJoueur(Joueur joueur[], int nb, Pion *pion);

#endif //UNTITLED5_INITILISATION_H
