//
// Created by tomco on 24/11/2021.
//
#include <stdio.h>
#include "fonction.h"


void red ()   {printf("\033[0;31m");}
void grey()   {printf("\033[0;37m");}
void yellow() {printf("\033[0;33m");}
void blue()   {printf("\033[0;34m");}
void purple() {printf("\033[0;35m");}
void green()  {printf("\033[0;32m");}
void cyan()   {printf("\033[0;36m");}
void reset()  {printf("\033[0m");}

enum { ROUGE, VERT, BLEU, VIOLET, JAUNE, CYAN, AUTRE_C, NBCOULEURS };
enum { CARRE, ROND, TRIANGLE, LOSANGE, ETOILE, CROIX, AUTRE_F, NBFORMES };


char* getCharOfForme(int forme) {
    switch (forme) {
        case CARRE:
            return "|◼︎";
        case ROND:
            return "|●";
        case TRIANGLE:
            return "|▲";
        case LOSANGE:
            return "|♦︎";
        case ETOILE:
            return "|★";
        case AUTRE_F:
            return "| ";
        default:
            return ".";
    }
}

char* getCodeCouleur(int couleur) {
    switch (couleur) {
        case ROUGE:
            return "\033[31m";
        case VERT:
            return "\033[32m";
        case BLEU:
            return "\033[34m";
        case VIOLET:
            return "\033[35m";
        case JAUNE:
            return "\033[33m";
        case CYAN:
            return "\033[36m";
        case AUTRE_C:
            return "\033[0m";
        default:
            return ".";
    }
}





void Menu()
{
    int choix;
    int isEnd = 1;
    printf("Bienvenue dans MONOPOLY\n");
    printf("\033[1;33m");
    printf("\n\n(\\ _ /)\n(='.'=)\n(\")-(\")");
    printf("\n\n");

    printf("1) Jouer\n2) Afficher les regles\n3) Charger la partie suivante\n4) Presentation des createurs du projet\n5) Quitter le jeu.\n");
    scanf("%d", &choix);


    switch (choix) {

        case 1:
            break;
        case 2:
            printf("Presentation du MONOPOLY :\n\n");
            printf("Le Monopoly est un jeu de societe ou chaque joueur dispose\nd'une meme somme d argent \n"
                   "initiale, et va tenter de monopoliser\nle marche immobilier d'une ville, en ruinant \n"
                   "progressivement ses adversaires.\n\n");
            printf("Liste des cases :\n"
                   "1. Case depart\n"
                   "2. Propriete 1 du groupe 1\n"
                   "3. Taxe d habitation : Payez 100E\n"
                   "4. Propriete 2 du groupe 1\n"
                   "5. Raccourci : Avancez a la case 13\n"
                   "6. Propriete 1 du groupe 2\n"
                   "7. Tirez une carte communaute\n"
                   "8. Propriete 2 du groupe 2\n"
                   "9. Case prison\n"
                   "10. Propriete 1 du groupe 3\n"
                   "11. Impot sur la fortune : Payez 100€\n"
                   "12. Propriete 2 du groupe 3\n"
                   "13. Raccourci : Avancez à la case 21\n"
                   "14. Propriete 1 du groupe 4\n"
                   "15. Tirez une carte chance\n"
                   "16. Propriete 2 du groupe 4\n"
                   "17. Case stationnement gratuit\n"
                   "18. Propriete 1 du groupe 5\n"
                   "19. Taxe sur les produits de luxe : Payez 200E\n"
                   "20. Propriete 2 du groupe 5\n"
                   "21. Raccourci : Avancez a la case 29\n"
                   "22. Propriete 1 du groupe 6\n"
                   "23. Tirez une carte communaute\n"
                   "24. Propriete 2 du groupe 6\n"
                   "25. Allez en prison\n"
                   "26. Propriete 1 du groupe 7\n"
                   "27. Vous trouvez 50E par terre.\n"
                   "28. Propriete 2 du groupe 7\n"
                   "29. Raccourci : Avancez à la case 5 (Vous passez par la case depart et collectez 200E)\n"
                   "30. Propriete 1 du groupe 8\n"
                   "31. Tirez une carte chance\n"
                   "32. Propriete 2 du groupe 8\n\n");
            printf("Liste des cartes chance :\n"
                   ". Allez a la case de depart. (Collectez 200E)\n"
                   ". Allez a [Propriete 2 Groupe 1]. Collectez votre salaire si vous passez la case depart\n"
                   ". Allez a [Propriete 1 Groupe 7]. Collectez votre salaire si vous passez la case depart\n"
                   ". La banque vous paie 50€\n"
                   ". Carte sortez de prison\n"
                   ". Reculez de 3 cases\n"
                   ". Allez directement en prison, vous ne passez pas par la case depart\n"
                   ". Vous faites des reparations sur vos proprietes : Payez 25E/maison et 100E/hotel.\n"
                   ". Vous avez ete elu maire, payez 50E a chaque joueur.euse\n"
                   ". Exces de vitesse : payez 100E\n\n");
            printf("Liste des cartes communaute :\n"
                   ". Allez a la case depart. (Collectez 200E)\n"
                   ". Frais de docteur. Payez 50E\n"
                   ". Carte sortie de prison\n"
                   ". Allez directement en prison, vous ne collectez pas votre salaire\n"
                   ". Vous faites un vide grenier et gagnez 30E\n"
                   ". C’est votre anniversaire, collectez 10E de chaque joueur.euse\n"
                   ". Vous recuperez des rentes : gagnez 100E\n"
                   ". Payez des frais d hopital de 100E\n"
                   ". Vous avez obtenu la seconde place d’un concours de beaute : gagnez 10E\n"
                   ". Vous heritez de 100E\n\n");
            break;

    }

}



void plateaudejeux(){
    Pion plateau[Ligne][Colonne];
    int ligne[Ligne];
    int colonne[Colonne];

    for (int i =0; i < 4; i++) {ligne[i] = i+1;}
    for (int i = 0; i < 8; i++) {colonne[i] = i+1;}

    red();
    printf("MONOPOLY :\n");
    printf("\t");
    for (int j = 0 ; j<8; j++){
        if(j<10){printf("  %d  ",colonne[j]);}
        else{printf(" %d ", colonne[j]);}
    }
    printf("\n");

    for(int i = 0; i<4; i++){
        red();
        printf("%d\t", ligne[i]);
        printf("%s%s  \033[0m ", getCodeCouleur(plateau[i][0].couleur), getCharOfForme(plateau[i][0].forme));
        printf("%s%s  \033[0m ", getCodeCouleur(plateau[i][1].couleur), getCharOfForme(plateau[i][1].forme));
        printf("%s%s  \033[0m ", getCodeCouleur(plateau[i][2].couleur), getCharOfForme(plateau[i][2].forme));
        printf("%s%s  \033[0m ", getCodeCouleur(plateau[i][3].couleur), getCharOfForme(plateau[i][3].forme));
        printf("%s%s  \033[0m ", getCodeCouleur(plateau[i][4].couleur), getCharOfForme(plateau[i][4].forme));
        printf("%s%s  \033[0m ", getCodeCouleur(plateau[i][5].couleur), getCharOfForme(plateau[i][5].forme));
        printf("%s%s  \033[0m ", getCodeCouleur(plateau[i][6].couleur), getCharOfForme(plateau[i][6].forme));
        printf("%s%s  \033[0m ", getCodeCouleur(plateau[i][7].couleur), getCharOfForme(plateau[i][7].forme));
        printf("%s%s  \033[0m ", getCodeCouleur(plateau[i][8].couleur), getCharOfForme(plateau[i][8].forme));
    }


}

int LancerDes()
{
    const int min = 1;
    const int max = 6;
    int resultat1;
    int resultat;
    int resultat2;
    int Double = 0;
    srand(time(NULL));
    resultat1 = (rand() % (max - min +1)) + min;
    resultat2 = (rand() % (max - min +1)) + min;
    resultat = resultat1 + resultat2;
    printf("Vous avez tire %d", resultat);
    if(resultat1 == resultat2){
        Double = 1;
        printf("C'est un double! Vous pourrez rejouer a la fin de votre tour");
    }
    printf("Vous avez tire %d", resultat);


    return resultat;

};

int initialisationDesJoueur()
{
    int nombredejoueur;
    Joueur tabJoueur[4] = {0};
    do{
        printf("Veuillez saisir le nombre de joueur entre 2 et 4:\n");
        scanf("%d", &nombredejoueur);
    }
    while (nombredejoueur != 2 && nombredejoueur != 3 && nombredejoueur != 4);

    printf("\t\tLancement d'une partie avec %d joueurs\n", nombredejoueur);
    for (int i = 1; i <= nombredejoueur ; ++i){
        tabJoueur[i].numero = i;
        printf("rentrez le nom du joueur %d\n", i);
        scanf("%s", tabJoueur[i].Nom);
        tabJoueur[i].argent = 1500;

    }
    TableauJoueur(nombredejoueur, tabJoueur);
    return tabJoueur;

}

void TableauJoueur(int nombredejoueur, Joueur tabJoueur[])
{

    for (int i = 1; i <= nombredejoueur ; ++i)
    {
        printf("Joueur %d :\n", tabJoueur[i].numero);
        printf("Nom : %s\n", tabJoueur[i].Nom);
        printf("Argent : %d\n", tabJoueur[i].argent);
    }


}



