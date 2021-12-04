#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>


#define NB_CARTE 10


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
    char* nom;
} Case;
typedef struct {
    int etat; // disponibilite : 1 (oui) 0 (non)
    int prix;
    int groupe;//
    int numero;// Surement remplacer pars chaine de Caractere en fct du theme
    Case *pCase; // pointeur sur la case propriete
    char *titre;
    int type; // 0 a 6 :
} Propriete;
typedef struct {
    char nom[10];
    int argent;
    Pion *pPion;
    Propriete* pPropriete;
} Joueur;

#ifndef PROJETINFOING3_INITIALISATION_H
#define PROJETINFOING3_INITIALISATION_H
void InitialisationProprietes(Propriete propriete[16], Case plateau[32]);
void InitialisationPioche(Cartes* piocheChance, Cartes* piocheCommunaute);
void InitialisationPlateau(Case plateau[32]);
void InitialisationPions(int nb, Pion pions[nb]);
void InitialisationJoueur(Joueur joueur[], int nb, Pion* pion);
#endif //PROJETINFOING3_INITIALISATION_H
