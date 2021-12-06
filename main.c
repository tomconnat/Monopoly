#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>


#include "Initialisation.h"


#define NB_CARTE 10

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

void varArgentJoueurs(Joueur *joueur, Joueur *joueurs, int nb, int gain) {
    for (int i = 0; i < nb; ++i) {
        if (strcmp(joueur->nom, joueurs[i].nom) == 0) {
            joueur->argent += nb * gain;
            printf("Vous gagner %d : \n", nb * gain);
        } else { joueur[i].argent -= gain; }
    }
}

void lancerDes(Joueur joueur, int *Double) {
    const int min = 1;
    const int max = 6;
    int resultat1 = 0;
    int resultat = 0;
    int resultat2;
    resultat1 = (rand() % (max - min + 1)) + min;
    resultat2 = (rand() % (max - min + 1)) + min;
    resultat = resultat1 + resultat2;
    if (joueur.etat == 0) {
        printf("Vous avez tire %d et %d\n", resultat1, resultat2);
        printf("Soit %d\n", resultat);
        joueur.pPion->position += resultat;
        if ((joueur.pPion->position > 32)) {
            joueur.pPion->position = joueur.pPion->position % 32;
        }
        if (resultat1 == resultat2) {
            *Double += 1;
            if (*Double < 3) {
                printf("C'est un double, le %d! Vous pourrez rejouer a la fin de votre tour\n", *Double);
            } else {
                printf("Cest illegale de faire 3 doubles d'affile tu vas en prison\n");
                *Double = 0;
                joueur.etat = 3;
                allerCase(&joueur, 9);
            }
        } else { *Double = 0; }
    } else {
        printf("Vous avez tire %d et %d \n", resultat1, resultat2);
        if (resultat1 == resultat2) {
            printf("C'est un double! Vous pouvez sortir de prison\n");
            joueur.
                    etat = 0;
        } else {
            printf("Vou n'avez pas reussi a faire de double \n");
            joueur.etat -= 1;
        }
    }
}

void afficherJoueur(Joueur joueur[], int nbJoueur) {
    for (int i = 0; i < nbJoueur; ++i) {
        printf("nom :%s\n", joueur[i].nom);
        printf("position pion :%d / forme : %d\n", joueur[i].pPion->position, joueur[i].pPion->forme);
        if (joueur[i].pPropriete != NULL) {
            printf("Propriete possede : %s \n", joueur[i].pPropriete->titre);
        } else { printf("PAs des prop\n"); }
        printf("argent : %d \n", joueur[i].argent);
        printf("\n");
    }
    printf("\n");
}

void charger(Joueur **joueurs, int *nbJoueur, Pion **pion) {
    FILE *pf = fopen("../sauvegardeMonopoly.txt", "r");
    if (pf == NULL) {
        printf("erreur ouverture fichier.\n");
    }
    fscanf(pf, "%d\n", nbJoueur);
    *joueurs = realloc(*joueurs, *nbJoueur * sizeof(Joueur));
    *pion = realloc(*pion, *nbJoueur * sizeof(pion));
    for (int i = 0; i < *nbJoueur; ++i) {
        fscanf(pf, "%s", joueurs[i]->nom);
        fscanf(pf, "%d %d", &pion[i]->position, &pion[i]->forme);
        joueurs[i]->pPion = pion[i];
        fscanf(pf, "%d", &joueurs[i]->argent);
        if (joueurs[i]->pPropriete != NULL) {
            fscanf(pf, "%s", joueurs[i]->pPropriete->titre);
        } else { joueurs[i]->pPropriete = NULL; }
        if (joueurs[i]->pCarte != NULL) {
            fscanf(pf, "%s", joueurs[i]->pCarte->descriptif);
        } else { joueurs[i]->pCarte = NULL; }

    }
    printf("%d", *nbJoueur);
    printf("chargement reussi\n");
}

void sauvegarde(Joueur *joueur, int nbJoueur) {
    FILE *pf = fopen("../sauvegardeMonopoly.txt", "w");
    if (pf == NULL) {
        printf("erreur ouverture fichier.\n");
    } else {
        fprintf(pf, "%d\n", nbJoueur);
        for (int i = 0; i < nbJoueur; ++i) {
            fprintf(pf, "%s\n", joueur[i].nom);
            if (joueur[i].pPion != NULL) {
                fprintf(pf, "%d %d\n", joueur[i].pPion->position, joueur[i].pPion->forme);
            }
            if (joueur[i].pPropriete != NULL) {
                fprintf(pf, "%d\n", joueur[i].pPropriete->numero);
            }
            fprintf(pf, "%d\n", joueur[i].etat);
            fprintf(pf, "%d\n", joueur[i].argent);
            if (joueur[i].pCarte != NULL) {
                fprintf(pf, "%d\n", joueur[i].pCarte->id);
            }
        }
        fclose(pf);
        pf = NULL;
    }
}

int MenuPrincipal(int nb, Joueur *joueurs, Pion **pions) {
    int choix = 0;
    int isEndMenu = 0;
    printf("Bienvenue dans MONOPOLY\n");
    printf("\n\n");
    while (isEndMenu != 1) {
        if (nb == 0) {
            printf("1) Jouer\n2) Afficher les regles\n3) Charger la partie suivante\n4) Presentation des createurs du projet\n6) Quitter le jeu.\n");
        } else {
            printf("1) Jouer\n2) Afficher les regles\n3) Sauvegarder la partie\n4) Presentation des createurs du projet\n6) Quitter le jeu.\n");
        }
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                isEndMenu = 1;
                return 1;
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
            case 3:
                if (nb == 0) {
                    printf("charger partie\n");
                } else
                    sauvegarde(joueurs, nb);
                return 3;
                break;
            case 5:
                isEndMenu = 1;

        }

    }
}

void depart(Joueur *joueur) {
    printf("Vous avez passez la case Depart\n");
    varArgent(joueur, 200);
}

void afficherPion(Pion *pions, int nbJoueur) {
    for (int i = 0; i < nbJoueur; ++i) {
        printf("Pion %d : position : %d / forme : %d \n", i + 1, pions[i].position, pions[i].forme);
    }
    printf("\n");
}

void afficherPioche(Cartes *cartes, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d : %s\n", cartes[i].id, cartes[i].descriptif);
    }
    printf("\n");
}

void afficherPropriete(Propriete propriete[15]) {
    for (int i = 0; i < 16; ++i) {
        printf(" Propriete %d Groupe  %d \n prix : %d  position : %d \n", propriete[i].numero, propriete[i].groupe,
               propriete[i].prix, propriete[i].pCase->numero);
        printf("%s\n", propriete[i].titre);
    }
    printf("\n");
}

void afficherTableau(Case plateau[31]) {
    for (int i = 0; i < 32; ++i) {
        printf("case n : %d\n", plateau[i].numero);
        printf("%s \n", plateau[i].nom);
    }
    printf("\n");
}


void afficherLeJoueur(Joueur joueur) {
    printf("nom : %s \n", joueur.nom);
    printf("position pion : %d / forme : %d\n", joueur.pPion->position, joueur.pPion->forme);
    if (joueur.pPropriete != NULL) {
        for (int i = 0; i < joueur.nbProp; ++i) {
            printf("Propriete possede : %s \n", joueur.pPropriete->titre);
        }
    } else { printf("PAs des prop\n"); }
    printf("argent : %d \n", joueur.argent);
    printf("\n");
}

void Prison(Joueur *joueur) {
    int choix = 0;
    int lancer = 1;
    int Double = 0;
    int isEnd = 0;
    while (isEnd != 1) {
        printf("vous avez encore %d tours en prison\n", joueur->etat);
        printf("Vous pouvez : \n");
        printf("   - Lancez les des et tenter d'obtenir un double\n");
        printf("   - Utilisez une carte 'Sortie de Prison' si vous ne avez une\n");
        printf("   - Achetez une carte 'Sortie de Prison' a un autre joueur\n");
        printf("   - Payez une amende de 100e\n");
        printf("   - Passez son tour\n");
        scanf("%d", &choix);
        switch (choix) {
            case 1:
                if (lancer == 1) {
                    lancerDes(*joueur, &Double);
                    lancer = 0;
                } else {
                    printf("Vous avez deja utiliser votre lancer\n");
                }
                break;
            case 2:
                if (joueur->pCarte != NULL) {
                    printf("vous utilisez votre carte sortie de prison\n");
                    joueur->etat = 0;
                    joueur->pCarte = NULL;
                } else { printf("Vous ne possede pas de carte sortie de prison"); }
                break;
            case 3:
                printf("Acheter carte a joueur\n");
                break;
            case 4:
                printf("Vous payez l'amende\n");
                if (joueur->argent > 100) {
                    printf("Vous pouvez payer l'amende\n");
                    varArgent(joueur, -100);
                    printf("Vous avez payer l'amende vous pouvez sortir de prison\n");
                    joueur->etat = 0;
                    isEnd = 1;
                } else { printf("Vous ne pouvez pas payer votre liberte\n"); }
                break;
            case 5:
                isEnd = 1;
        }
    }
}


void RemiseEnPioche(Cartes *pioche) {
    Cartes carteVolante = {0};
    carteVolante.id = pioche[9].id;
    carteVolante.descriptif = pioche[9].descriptif;
    carteVolante.type = pioche[9].type;
    for (int i = 9; i > 0; --i) {
        pioche[i].id = pioche[i - 1].id;
        pioche[i].type = pioche[i - 1].type;
        pioche[i].descriptif = pioche[i - 1].descriptif;

    }
    pioche[0].id = carteVolante.id;
    pioche[0].descriptif = carteVolante.descriptif;
    pioche[0].type = carteVolante.type;

}

void TirerUneCarte(Joueur *joueur1, Cartes *pioche, Joueur *joueurs, int nb) {
    printf("Vous avez Tirer : %s n%d.\n", pioche[9].type, pioche[9].id);
    printf("%s\n", pioche[9].descriptif);
    switch (pioche[9].id) {
        case 1 :
            printf("Vous allez a la case depart\n");
            allerCase(joueur1, 1);
            depart(joueur1);
            RemiseEnPioche(pioche);
            break;
        case 2 :
            printf("vous allez a la case 4\n ");
            if (joueur1->pPion->position > 4) {
                depart(joueur1);
            } else { printf("Vous ne passez pas par la case depart\n"); }
            allerCase(joueur1, 4);
            RemiseEnPioche(pioche);
            break;
        case 3 :
            printf("vous allez a la case 26");
            if (joueur1->pPion->position > 26) {
                depart(joueur1);
            } else { printf("Vous ne passez pas par la case depart\n"); }
            allerCase(joueur1, 26);
            RemiseEnPioche(pioche);
            break;
        case 4 :
            printf("vous recevez 50e\n");
            varArgent(joueur1, 50);
            RemiseEnPioche(pioche);
            break;
        case 5 :
            printf("Vous ganer un carte sortie de prison\n");
            printf("Cette carte vous apparrient vous pourrez l'utiliser quand vou serez en prison\n");
            joueur1->pCarte = &pioche[9];
            break;
        case 6 :
            printf("Vous Reculez de 3 cases \n");
            allerCase(joueur1, -3);
            RemiseEnPioche(pioche);
            break;
        case 7 :
            printf("Allez en prison\n");
            allerCase(joueur1, 9);
            RemiseEnPioche(pioche);
            joueur1->etat = 3;
            Prison(joueur1);
            break;
        case 8 :
            printf("Reparations vous perdez 25e/maison et 100e/hotel\n");
            RemiseEnPioche(pioche);
            //fct reparations
            break;
        case 9 :
            printf("Vous etes elu maire, 50e a chaque joueur \n");
            RemiseEnPioche(pioche);
            varArgentJoueurs(joueur1, joueurs, nb, 50);
            break;
        case 10 :
            printf("Exces de vitesse vous perdez 100e\n");
            varArgent(joueur1, -100);
            RemiseEnPioche(pioche);
            break;
        case 11 :
            printf("Vous allez a la case depart\n");
            allerCase(joueur1, 1);
            depart(joueur1);
            RemiseEnPioche(pioche);
            break;
        case 12 :
            printf("Vous payez le docteur vous perdez 50e\n");
            varArgent(joueur1, -50);
            RemiseEnPioche(pioche);
            break;
        case 13 :
            printf("Vous ganer un carte sortie de prison\n");
            printf("Cette carte vous apparrient vous pourrez l'utiliser quand vou serez en prison\n");
            joueur1->pCarte = &pioche[9];
            break;
        case 14 :
            printf("Allez en prison\n");
            allerCase(joueur1, 9);
            joueur1->etat = 3;
            Prison(joueur1);
            break;
        case 15 :
            printf("Vide de grenier vous gagne 30e\n");
            varArgent(joueur1, 30);
            RemiseEnPioche(pioche);
            break;
        case 16 :
            printf("Joyeux anniversaire vous recevez 30e de chaque joueuer\n");
            varArgentJoueurs(joueur1, joueurs, nb, 30);
            RemiseEnPioche(pioche);
            break;
        case 17 :
            printf("Recuperez vos rentes : 100e\n");
            varArgent(joueur1, 100);
            RemiseEnPioche(pioche);
            break;
        case 18 :
            printf("Frais d'hopitel 100e\n");
            varArgent(joueur1, -100);
            RemiseEnPioche(pioche);
            break;
        case 19 :
            printf("Vous ganer 10e uber eats\n ");
            varArgent(joueur1, 10);
            RemiseEnPioche(pioche);
            break;
        case 20:
            printf("Mamie est morte : 100e\n");
            varArgent(joueur1, 100);
            RemiseEnPioche(pioche);
            break;
    }
}

void Interface(Case *plateau, Joueur *joueur, Propriete *propriete, Pion *pions, int nb) {
    int cpt1 = 0;
    for (int i = 0; i < 11; ++i) {
        printf("   %d      ", plateau[i].numero);
    }
    printf("   %d\n", plateau[11].numero);
    printf(" %s    ", plateau[0].nom);
    for (int i = 1; i < 10; ++i) {
        printf("%s     ", plateau[i].nom);
    }
    printf("%s", plateau[10].nom);
    printf("      %s\n", plateau[11].nom);
    printf("   ");
    for (int i = 0; i < 11; ++i) {
        for (int j = 0; j < nb; ++j) {
            if (joueur[j].pPion->position == plateau[i].numero) {
                printf("%d", joueur[j].pPion->forme);
            }
        }
        printf("          ");
    }
    printf("\n");
    for (int i = 0; i < 4; ++i) {
        printf("   %d                                                                                                              %d\n",
               plateau[31 - i].numero, plateau[12 + i].numero);
        printf("  %s                                                                                                        %s\n",
               plateau[31 - i].nom, plateau[12 + i].nom);
        printf("   ");
        for (int j = 0; j < nb; ++j) {
            if (plateau[31 - i].numero == joueur[j].pPion->position) {
                printf("%d", joueur[j].pPion->forme);
            }
            if (plateau[12 + i].numero == joueur[j].pPion->forme) {
                if (cpt1 == 0) {
                    printf("      ");
                    cpt1 = 1;
                }
                printf("%d", joueur[j].pPion->forme);
            }

        }
        printf("\n");
    }


    printf("   %d     ", plateau[27].numero);
    for (int i = 26; i > 19; --i) {
        printf("    %d    ", plateau[i].numero);
    }
    printf(" ");
    for (int i = 19; i > 15; --i) {
        printf("    %d   ", plateau[i].numero);
    }
    printf("\n");
    for (int i = 27; i > 20; --i) {
        printf("  %s   ", plateau[i].nom);
    }
    printf("%s", plateau[20].nom);
    printf("     %s ", plateau[19].nom);
    printf("   %s  ", plateau[18].nom);
    printf(" %s ", plateau[17].nom);
    printf(" %s\n", plateau[16].nom);
    printf("   ");
    for (int i = 27; i > 15; --i) {
        for (int j = 0; j < nb; ++j) {
            if (joueur[j].pPion->position == plateau[i].numero) {
                printf("%d", joueur[j].pPion->forme);
            }
        }
        printf("          ");
    }
}
/*for (int i = 10; i < 22; i += 2) {
    printf("   %d                                                                                                      ",
           plateau[i].numero);
    printf("%d\n", plateau[i + 1].numero);
    printf("%s                                                        ", plateau[i].nom);
    printf(" %s\n", plateau[i + 1].nom);
}
printf("\n");
for (int i = 22; i < 31; ++i) {
    printf("   %d        ", plateau[i].numero);

}
printf("   32\n");*/


/*void Fonction (Case plateau[31],Joueur joueur) {
    for (int i = 0; i < 31 ; ++i) {
        if (joueur.pPion->position == plateau[i].numero){
            switch (i) {
                case 1:
                    depart(&joueur);
                    break;
                case 2:
                    break;

            }
        }
    }
}*/
/*void surProprieté(Joueur joueur,Propriete* propriete){
    for (int i = 0; i < 16; ++i) {
        if (propriete[i].pCase->numero == joueur.pPion->position){
            if (propriete[i].type == 0) {
                printf("Vous pouvez acheter : %s\n", propriete[i].pCase->nom);
                printf("Pour un prix de : %d \n", propriete[i].prix);
            } else{ printf("Proprieté deja possede par quelun\n");}
        } else{ printf("il ny a pas de propriete sur cette case\n");}
    }

}*/

void acheterPropriete(Joueur *joueur, Propriete *propriete, Joueur *joueurs, int nb) {
    int choix = 0;
    for (int i = 0; i < 16; ++i) {
        if (propriete[i].pCase->numero == joueur->pPion->position) {
            if (propriete[i].etat == 1) {
                printf("Cet propriete est disponible a l'achat (prix : %d)\n", propriete[i].prix);
                printf("1 pour oui ou 0 pour non\n");
                scanf("%d", &choix);
                if (choix == 1) {
                    if (joueur->argent < propriete[i].prix) {
                        printf("Vous n'avez pas assez d'argent pour payer la proprieté\n");
                    } else {
                        printf("Vous acheter la propriete : %s\n", propriete[i].titre);
                        joueur->pPropriete = calloc(1, sizeof(Propriete));
                        joueur->pPropriete[0] = propriete[i];
                        joueur->nbProp += 1;
                        propriete[i].etat = 0;
                        printf(" Proriete %d du group %d vous appartient desormais", joueur->pPropriete[0].numero,
                               joueur->pPropriete[0].groupe);
                        joueur->argent -= propriete[i].prix;
                    }
                } else { printf("vous n'achetez pas le propriete\n"); }
            } else if (propriete[i].etat == 0) {
                for (int j = 0; j < nb; ++j) {
                    if (joueur[i].pPropriete->numero == propriete[i].numero) {
                        printf("Vous devez payer le loyer a %s de %de \n", joueur[i].nom, joueur[i].pPropriete->prix);
                        varArgent(joueur, -joueurs[i].pPropriete->prix);
                        varArgent(&joueurs[i], joueurs[i].pPropriete->prix);
                    }
                }
            }
        }
    }
}

void actionCase(Joueur *joueur, Propriete *propriete, Case *plateau, int nbJoueur, Cartes *piocheCommu,
                Cartes *piocheChance, Joueur *joueurs, int* indicateur) {
    int flush = 0;
    for (int i = 0; i < 32; ++i) {
        if (joueur->pPion->position == plateau[i].numero) {
            if (plateau[i].numero % 2 == 0) {
                acheterPropriete(joueur, propriete, joueurs, nbJoueur);
            } else {
                switch (plateau[i].numero) {
                    case 1:
                        printf("Depart\n");
                        depart(joueur);
                        printf("Saisir un nombre pour continuer\n");
                        scanf("%d", &flush);
                        i = 32;
                        break;
                    case 3:
                        printf("Taxe habitation : Payez 100e \n");
                        varArgent(joueur, -100);
                        printf("Saisir un nombre pour continuer\n");
                        scanf("%d", &flush);
                        i = 32;
                        break;
                    case 5:
                        allerCase(joueur, 13);
                        printf("Saisir un nombre pour continuer\n");
                        scanf("%d", &flush);
                        i = 32;
                        break;
                    case 7:
                        printf("Tirez une carte communaute \n");
                        TirerUneCarte(joueur, piocheCommu, joueurs, nbJoueur);
                        printf("Saisir un nombre pour continuer\n");
                        scanf("%d", &flush);
                        i = 32;
                        break;
                    case 9:
                        if (joueur->etat == 0) {
                            printf("Vous visitez en prison \n");
                            scanf("%d", &flush);
                        } else {
                            Prison(joueur);
                            if (joueur->etat != 0) {
                                printf("Vous etes encore en prison\n");
                            } else { printf("Vous etes sorti de prison"); }
                        }
                        break;
                    case 11:
                        printf("Payez l'ISF : Payez 100e \n");
                        varArgent(joueur, -100);
                        printf("Saisir un nombre pour continuer\n");
                        scanf("%d", &flush);
                        i = 32;
                        break;
                    case 13:
                        allerCase(joueur, 21);
                        printf("Saisir un nombre pour continuer\n");
                        scanf("%d", &flush);
                        i = 32;
                        break;
                    case 15:
                        printf("Vous tirez une carte chance \n");
                        TirerUneCarte(joueur, piocheChance, joueurs, nbJoueur);
                        printf("Saisir un nombre pour continuer\n");
                        scanf("%d", &flush);
                        i = 32;
                        break;
                    case 17:
                        printf("stationnement gratuit \n");
                        scanf("%d", &flush);
                        i = 32;
                        break;
                    case 19:
                        printf("Taxe produits : Payez 200e \n");
                        varArgent(joueur, -200);
                        printf("Saisir un nombre pour continuer\n");
                        scanf("%d", &flush);
                        i = 32;
                        break;
                    case 21:
                        allerCase(joueur, 29);
                        printf("Saisir un nombre pour continuer\n");
                        scanf("%d", &flush);
                        i = 32;
                        break;
                    case 23:
                        printf("Tirez carte communaute \n");
                        TirerUneCarte(joueur, piocheCommu, joueurs, nbJoueur);
                        printf("Saisir un nombre pour continuer\n");
                        scanf("%d", &flush);
                        i = 32;
                        break;
                    case 25:
                        printf("Vous allez en prison\n");
                        allerCase(joueur, 9);
                        joueur->etat = 3;
                        //fct Prison
                        printf("Saisir un nombre pour continuer\n");
                        scanf("%d", &flush);
                        break;
                    case 27:
                        printf("vous trouver 50e par terre \n");
                        varArgent(joueur, 50);
                        printf("Saisir un nombre pour continuer\n");
                        scanf("%d", &flush);
                        i = 32;
                        break;
                    case 29:
                        allerCase(joueur, 5);
                        depart(joueur);
                        printf("Saisir un nombre pour continuer\n");
                        scanf("%d", &flush);
                        i = 32;
                        break;
                    case 31:
                        printf("tirez carte chance\n");
                        TirerUneCarte(joueur, piocheChance, joueurs, nbJoueur);
                        printf("Saisir un nombre pour continuer\n");
                        scanf("%d", &flush);
                        i = 32;
                        break;
                }
            }
        }
    }
}


int main() {
    srand(time(NULL));
    FILE *pf = NULL;
    int var = 0;
    int indicateur = 0;
    int Double = 0;
    int choix = 0;
    int isEnd = 0;
    int cptTour = 0;
    int nbJoueur = 0;
    Maison *maisons[32] = {0};
    Joueur *joueurs = calloc(nbJoueur, sizeof(Joueur));
    Pion *pions = calloc(nbJoueur, sizeof(Pion));
    var = MenuPrincipal(nbJoueur, joueurs, &pions);
    Propriete propriete[16] = {0};
    Case plateau[32] = {0};
    Cartes *piocheChance = calloc(10, sizeof(Cartes));
    Cartes *piocheCommunaute = calloc(10, sizeof(Cartes));
    InitialisationPlateau(plateau);
    InitialisationPioche(piocheChance, piocheCommunaute);
    InitialisationProprietes(propriete, plateau);
    InitialisationPions(nbJoueur, pions);
    InitialisationJoueur(joueurs, nbJoueur, pions);
    switch (var) {
        case 1:
            printf("Lancement nouvelle partie : \n");
            //Initilisation
            printf("Veuillez entrer le nombre de joueur : \n");
            scanf("%d", &nbJoueur);
            joueurs = realloc(joueurs, nbJoueur * sizeof(Joueur));
            pions = realloc(pions, nbJoueur * sizeof(Pion));
            assert(pions != NULL);
            InitialisationPions(nbJoueur, pions);
            InitialisationJoueur(joueurs, nbJoueur, pions);
            break;
        case 3:
            pf = fopen("../sauvegardeMonopoly.txt", "r");
            if (pf == NULL) {
                printf("erreur ouverture fichier.\n");
            }
            fscanf(pf, "%d\n", &nbJoueur);
            joueurs = realloc(joueurs, nbJoueur * sizeof(Joueur));
            pions = realloc(pions, nbJoueur * sizeof(Pion));
            for (int i = 0; i < nbJoueur; ++i) {
                fscanf(pf, "%s", joueurs[i].nom);
                fscanf(pf, "%d %d", &pions[i].position, &pions[i].forme);
                joueurs[i].pPion = &pions[i];
                fscanf(pf, "%d", &joueurs[i].etat);
                fscanf(pf, "%d", &joueurs[i].argent);
                if (joueurs[i].pPropriete != NULL) {
                    fscanf(pf, "%s", joueurs[i].pPropriete->titre);
                } else { joueurs[i].pPropriete = NULL; }
                if (joueurs[i].pCarte != NULL) {
                    fscanf(pf, "%s", joueurs[i].pCarte->descriptif);
                } else { joueurs[i].pCarte = NULL; }
            }
            break;
    }
    printf("Verif : \n");
    afficherTableau(plateau);
    printf("Pioche communaute\n");
    afficherPioche(piocheCommunaute, NB_CARTE);
    printf("Pioche Chance\n");
    afficherPioche(piocheChance, NB_CARTE);
    afficherPropriete(propriete);
    afficherPion(pions, nbJoueur);
    afficherJoueur(joueurs, nbJoueur);
    while (isEnd != 1) {
        if (joueurs[cptTour].etat == 0) {
            printf("C'est au tour de %s de jouer : \n", joueurs[cptTour].nom);
            Interface(plateau, joueurs, propriete, pions, nbJoueur);
            printf("\n\n");
            afficherLeJoueur(joueurs[cptTour]);
            indicateur = 0;
            printf("Quitter : 1 \n");
            printf("Lancer les des : 2 \n");
            printf("Afficher le menu : 3 \n");
            scanf("%d", &choix);
            switch (choix) {
                case 1:
                    isEnd = 1;
                    break;
                case 2:
                    printf("lancer les des\n");
                    lancerDes(joueurs[cptTour], &Double);
                    if (indicateur == 0) {
                        actionCase(&joueurs[cptTour], propriete, plateau, nbJoueur, piocheCommunaute, piocheChance,
                                   joueurs, &indicateur);
                        indicateur = 1;
                    }
                    if (Double != 0 && Double < 3) {
                        cptTour = cptTour;
                    } else { cptTour++; }
                    break;
                case 3:
                    MenuPrincipal(nbJoueur, joueurs, &pions);
                    Double = 1;
                    break;
            }
            if (cptTour == nbJoueur) {
                cptTour = 0;
            }
        } else { Prison(&joueurs[cptTour]); }
    }
    //TirerUneCarte(&joueurs[0], piocheCommunaute);
    //joueurs[0].pPion->position = 0;
    //joueurs[1].pPion->position = 4;
    // actionCase
    //actionCase(&joueurs[0],propriete,plateau,nbJoueur);
    // acheterPropriete(&joueurs[1],propriete);
    //afficherJoueur(joueurs, nbJoueur);
    //printf("Pioche communaute\n");
    //afficherPioche(piocheCommunaute, NB_CARTE);
    //printf("Pioche Chance\n");
    //afficherPioche(piocheChance, NB_CARTE);
    //AFFichage
    // afficherTableau(plateau);
    // printf("pioche communaute : \n");
    // afficherPioche(piocheCommunaute,NB_CARTE);
    // printf("pioche chance  : \n");
    // afficherPioche(piocheChance,NB_CARTE);

    //afficherPropriete(propriete);
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
    //afficherPropriete(propriete);*/
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
    free(joueurs);
    free(piocheChance);
    free(piocheCommunaute);
    free(pions);
    return 0;
}
