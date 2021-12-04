//
// Created by tomco on 24/11/2021.
//

#include <stdio.h>
#include <winnt.h>
//#include "fonction.h"

#include "Initialisation.h"




void afficherPion(Pion *pions, int nbJoueur) {
    for (int i = 0; i < nbJoueur; ++i) {
        printf("Pion %d : position : %d / forme : %d \n", i + 1, pions[i].position, pions[i].forme);
    }
}

void afficherPioche(Cartes *cartes, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d : %s\n", cartes[i].id,cartes[i].descriptif);
    }
}

void afficherPropriete(Propriete propriete[15]) {
    for (int i = 0; i < 16; ++i) {
        printf(" Propriete %d Groupe  %d \n prix : %d  position : %d \n", propriete[i].numero, propriete[i].groupe,
               propriete[i].prix, propriete[i].pCase->numero);
        printf("%s\n", propriete[i].titre);
    }
}

void afficherTableau(Case plateau[31]) {
    for (int i = 0; i < 32; ++i) {
        printf("case n : %d\n", plateau[i].numero);
        printf("%s \n", plateau[i].nom);
    }
}

void afficherJoueur(Joueur joueur[], int nbJoueur) {
    for (int i = 0; i < nbJoueur; ++i) {
        printf("nom :%s", joueur[i].nom);
        printf("position pion :%d / forme : %d\n", joueur[i].pPion->position, joueur[i].pPion->forme);
        if (joueur[i].pPropriete != NULL) {
            printf("Propriete possede : %s \n", joueur[i].pPropriete->titre);
        } else { printf("PAs des prop\n"); }
        printf("argent : %d \n",joueur[i].argent);
    }
}
void allerCase(Joueur *joueur, int nb) {
    printf("Vous allez a la case : %d\n", nb);
    joueur->pPion->position = nb;
}

void varArgent(Joueur *joueur, int gain) {
    if (gain < 0) {
        printf("Vous perdez %d\n", -gain);
    } else {
        printf("Vous gagner %d\n", gain);
    }
    joueur->argent += gain;
}

void depart(Joueur *joueur) {
    printf("Vous avez passez la case Depart\n");
    varArgent(joueur, 200);
}
void RemiseEnPioche(Cartes *pioche) {
    Cartes carteVolante = {0};
    carteVolante.id = pioche[19].id;
    carteVolante.descriptif = pioche[19].descriptif;
    carteVolante.type = pioche[19].type;
    for (int i = 19; i > 0; --i) {
        pioche[i].id = pioche[i - 1].id;
        pioche[i].type = pioche[i - 1].type;
        pioche[i].descriptif = pioche[i - 1].descriptif;

    }
    pioche[0].id = carteVolante.id;
    pioche[0].descriptif = carteVolante.descriptif;
    pioche[0].type = carteVolante.type;

}
/*void TirerUneCarte(Joueur* joueur1, Cartes* pioche) {
    printf("Vous avez Tirer : %s %d.\n", pioche[19].type, pioche[19].id);
    printf("%s\n", pioche[19].descriptif);
    switch (pioche[19].id) {
        case 1 :
            printf("Vous allez a la case depart\n");
            //allerCase(joueur1,0);
            break;
        case 2 :
            printf("vous allez a la case 4\n ");
            //allerCase(joueur1,4);
            break;
        case 3 :
            printf("vous allez a la case 26");
            //allerCase(joueur1,26);
            break;
        case 4 :
            printf("vous recevez 50e\n");
            //varArgent(joueur1,50);
            break;
        case 5 :
            printf("Vous sortez en prison\n");
            break;
        case 6 :
            printf("Vous Reculez de 3 cases \n");
            //allerCase(joueur1,-3);
            break;
        case 7 :
            printf("Allez en prison cas : 25 (sans case depart)\n");
            //allerCase(joueur1,25);
            break;
        case 8 :
            printf("Reparations vous perdez 25e/maison et 100e/hotel\n");

            break;
        case 9 :
            printf("Vous etes elu maire, 50e a chaque joueur \n");

            break;
        case 10 :
            printf("Exces de vitesse vous perdez 100e\n");
            //varArgent(joueur1,-100);
            break;
        case 11 :
            printf("Vous allez a la case depart\n");
            //allerCase(joueur1,1);
            break;
        case 12 :
            printf("Vous payez le docteur vous perdez 50e\n");
            //varArgent(joueur1,-50);
            break;
        case 13 :
            printf("Vous sortez de prison\n");

            break;
        case 14 :
            printf("Vous allez en prison case 25\n");
            //allerCase(joueur1,25);
            break;
        case 15 :
            printf("Vide de grenier vous gagne 30e\n");
            //varArgent(joueur1,30);
            break;
        case 16 :
            printf("Joyeux anniversaire vous recevez 10e de chaque joueuer\n");

            break;
        case 17 :
            printf("Recuperez vos rentes : 100e\n");
            //varArgent(joueur1,100);
            break;
        case 18 :
            printf("Frais d'hopitel 100e\n");
            //varArgent(joueur1,-100);
            break;
        case 19 :
            printf("Vous ganer 10e uber eats\n ");
            //varArgent(joueur1,10);
            break;
        case 20:
            printf("Mamie est morte tu hertie de 1pct : 100e\n");
            //varArgent(joueur1,100);
            break;

    }
    RemiseEnPioche(pioche);

}*/
void acheterPropriete(Joueur *joueur, Propriete *propriete) {
    int choix = 0;
    for (int i = 0; i < 16; ++i) {
        if (propriete[i].pCase->numero == joueur->pPion->position) {
            if (propriete[i].etat == 1) {
                printf("Cet propriete est disponible a l'achat\n");
                printf("1 pour oui ou 0 pour non\n");
                scanf("%d", &choix);
                if (choix == 1) {
                    printf("Vous acheter la prorp\n");
                    joueur->pPropriete = calloc(1, sizeof(Propriete));
                    joueur->pPropriete[0] = propriete[i];
                    propriete[i].etat = 0;
                    printf(" Proriete %d du group %d vous appartient desormais", joueur->pPropriete[0].numero,
                           joueur->pPropriete[0].groupe);
                    joueur->argent -= propriete[i].prix;
                } else { printf("vous n'achetez pas le propriete\n"); }
            } else { printf("PAYE\n"); }
        }
    }
}

void actionCase(Joueur* joueur,Propriete* propriete,Case* plateau, int nbJoueur ){
    for (int i = 0; i < 32; ++i) {
        if (joueur->pPion->position == plateau[i].numero) {
            if (plateau[i].numero % 2 == 0) {
                acheterPropriete(joueur, propriete);
            } else {
                switch (plateau[i].numero) {
                    case 1:
                        printf("Depart\n");
                        depart(joueur);
                        break;
                    case 3:
                        printf("Taxe habitation : \n");
                        varArgent(joueur, -100);
                        break;
                    case 5:
                        allerCase(joueur, 13);
                        break;
                    case 7:
                        printf("Tirez une carte communaute \n");
                        break;
                    case 9:
                        printf("Vous entrez en prison \n");
                        break;
                    case 11:
                        printf("Payez l'ISF : \n");
                        break;
                    case 13:
                        allerCase(joueur,13);
                        break;
                    case 15:
                        printf("Vous tirez une carte chance \n");
                        break;
                    case 17:
                        printf("stationnement gratuit \n");
                        break;
                    case 19:
                        printf("Taxe hab : \n");
                        break;
                    case 21:
                        allerCase(joueur,29);
                        break;
                    case 23:
                        printf("Tirez carte communaute \n");
                        break;
                    case 25:
                        allerCase(joueur,9);
                        break;
                    case 27:
                        printf("vous trouver 50e par terre \n");
                        break;
                    case 29:
                        allerCase(joueur,nbJoueur);
                        break;
                    case 31:
                        printf("tirez carte chance\n");
                        break;
                }
            }
        }
    }
}


int main() {
    //Menu();
    //LancerDes();
    //initialisationDesJoueur();
    //plateaudejeux();
    srand(time(NULL));
    //Initilisation
    Propriete propriete[16] = {0};
    Case plateau[32] = {0};
    int nbJoueur = 1;
    //printf("Saisir nombre de Joueur :\n");
    //scanf("%d", &nbJoueur);
    Joueur joueurs[nbJoueur];
    Pion *pions = calloc(nbJoueur, sizeof(Pion));
    assert(pions != NULL);
    Cartes *piocheChance = calloc(10, sizeof(Cartes));
    Cartes *piocheCommunaute = calloc(10, sizeof(Cartes));
    // Initialisation des tous les elements du jeu
    InitialisationPlateau(plateau);
    InitialisationPioche(piocheChance,piocheCommunaute);
    InitialisationProprietes(propriete, plateau);
    InitialisationPions(nbJoueur, pions);
    InitialisationJoueur(joueurs, nbJoueur, pions);
    // TEST AFFICHAGE ELEMENTS INITIALISER
    // afficherTableau(plateau);
    // printf("pioche communaute : \n");
    // afficherPioche(piocheCommunaute,NB_CARTE);
    // printf("pioche chance  : \n");
    // afficherPioche(piocheChance,NB_CARTE);
    // afficherPropriete(propriete);
    // afficherPion(pions,nbJoueur);
    // afficherJoueur(joueurs, nbJoueur);
    joueurs[0].pPion->position = 23;
    joueurs[1].pPion->position = 4;
    actionCase(&joueurs[0],propriete,plateau,nbJoueur);
    // acheterPropriete(&joueurs[1],propriete);
    //  afficherJoueur(joueurs, nbJoueur);
    //  afficherPion(pions,nbJoueur);
    // afficherJoueur(joueurs,nbJoueur);
    //TEST ACQUERI PROP
    // joueurs[0].pPion->position = 15;
    // joueurs[1].pPion->position = 23;
    //joueurs[2].pPion->position = 1;
    // afficherPion(pions, nbJoueur);
    // afficherJoueur(joueurs, nbJoueur);

    //actionCarte(joueurs[1],plateau);
    //actionCarte(joueurs[2],plateau);

//TEST ACHAT PROP
    // acheterPropriete(&joueurs[0], propriete);
    // joueurs[1].pPion->position = 2;
    // acheterPropriete(&joueurs[1], propriete);
    // afficherJoueur(joueurs, nbJoueur);
    //for (int i = 0; i < 16; ++i) {
    //printf("%d",propriete[i].pCase->numero);
    //printf("%s",propriete[i].pCase->nom);}
    //afficherJoueur(joueurs,nbJoueur);
    // allerCase(&joueurs[0],5);
    // afficherJoueur(joueurs,nbJoueur);
    // printf(" %d %s",plateau[joueurs[0].pPion->position - 1].numero,plateau[joueurs[0].pPion->position - 1].nom);
    //printf("%d \n",propriete[0].pCase->numero);
    //printf("%d\n",plateau[joueurs[0].pPion->position - 1].numero);
    //afficherPropriete(propriete);
    /*   for (int i = 0; i < 16; ++i) {
        if (propriete[i].pCase->numero == joueurs->pPion->position -1 ){
            printf("carre\n");
        }
    }*/

    //afficherPropriete(propriete);

    //  afficherPioche(pioche,NB_CARTE);
    // Interface(plateau);
    // allerCase(&joueur1,6);
    //Interface(plateau,joueur1,propriete);
    // afficherPropriete(propriete);
    //printf("(avant apres)nom du joueur : %s \n argent de %d\n position : %d \n",joueur1.nom,joueur1.argent,joueur1.pPion->position);
    //TirerUneCarte(&joueurs[0],pioche);
    //printf("(avant apres)nom du joueur : %s \n argent de %d\n position : %d \n",joueur1.nom,joueur1.argent,joueur1.pPion->position);
    //afficherPioche(pioche,NB_CARTE);
    //Interface(plateau, joueur1, propriete);
    free(piocheChance);
    free(piocheCommunaute);
    free(pions);





    return 0;
}