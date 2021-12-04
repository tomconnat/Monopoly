//
// Created by Droubay on 04/12/2021.
//

#include <time.h>
#include <stdlib.h>
#include <assert.h>

#include "Initialisation.h"

void InitialisationPioche(Cartes* piocheChance, Cartes* piocheCommunaute) {
    Cartes Carte1;
    Cartes Carte2;
    Cartes Carte3;
    Cartes Carte4;
    Cartes Carte5;
    Cartes Carte6;
    Cartes Carte7;
    Cartes Carte8;
    Cartes Carte9;
    Cartes Carte10;
    Cartes Carte11;
    Cartes Carte12;
    Cartes Carte13;
    Cartes Carte14;
    Cartes Carte15;
    Cartes Carte16;
    Cartes Carte17;
    Cartes Carte18;
    Cartes Carte19;
    Cartes Carte20;


    Carte1.descriptif = "Allez a la case depart";
    Carte1.id = 1;
    Carte1.type = "CARTE CHANCE";
    Carte2.descriptif = "Allez a [Propriete 2 Group2]. Collectez salaire si passage par depart";
    Carte2.id = 2;
    Carte2.type = "CARTE CHANCE";
    Carte3.descriptif = "Allez a [Propriete 1 Group7]. Collectez salaire si passage par depart";
    Carte3.id = 3;
    Carte3.type = "CARTE CHANCE";
    Carte4.descriptif = "La banque vous paie 50e";
    Carte4.id = 4;
    Carte4.type = "CARTE CHANCE";
    Carte5.descriptif = "Carte sortez de prison";
    Carte5.id = 5;
    Carte5.type = "CARTE CHANCE";
    Carte6.descriptif = "Reculez de  cases";
    Carte6.id = 6;
    Carte6.type = "CARTE CHANCE";
    Carte7.descriptif = "Allez directement en prison, sans passer par depart";
    Carte7.id = 7;
    Carte7.type = "CARTE CHANCE";
    Carte8.descriptif = "Vous faites des reparations sur vos proprietes: Payez 25e par maison et 100e par hotel";
    Carte8.id = 8;
    Carte8.type = "CARTE CHANCE";
    Carte9.descriptif = "Vous avez ete elu maire, payez 50e a chaque joueur.euse";
    Carte9.id = 9;
    Carte9.type = "CARTE CHANCE";
    Carte10.descriptif = "Exces de vitesse : payez 100e";
    Carte10.id = 10;
    Carte10.type = "CARTE CHANCE";
    Carte11.descriptif = "Allez a la case depart (Recevez 200e)";
    Carte11.id = 11;
    Carte11.type = "CARTE COMMUNAUTE";
    Carte12.descriptif = "Frais de docteur. Payez 50e";
    Carte12.id = 12;
    Carte12.type = "CARTE COMMUNAUTE";
    Carte13.descriptif = "Carte sorti de prison";
    Carte13.id = 13;
    Carte13.type = "CARTE COMMUNAUTE";
    Carte14.type = "CARTE COMMUNAUTE";
    Carte14.id = 14;
    Carte14.descriptif = "Allez directement en prison, vous ne collectez pas votre salaire";
    Carte15.descriptif = "Vous faites un vide grenier et gagnez 30e";
    Carte15.id = 15;
    Carte15.type = "CARTE COMMUNUATE";
    Carte16.descriptif = "C'est votre anniversire, collectez 10e de chaque joueur.euse";
    Carte16.id = 16;
    Carte16.type = "CARTE COMMUNAUTE";
    Carte17.descriptif = "Vous recuperez les rentes : gagnez 100e";
    Carte17.id = 17;
    Carte17.type = "CARTE COMMUNAUTE";
    Carte18.descriptif = "Payez des frais d'hopitaux de 100e";
    Carte18.id = 18;
    Carte18.type = "CARTE COMMUNAUTE ";
    Carte19.descriptif = "Vous avez obtenu la seconde place d'un concours de beaute : gagnez 10e";
    Carte19.id = 19;
    Carte19.type = "CARTE COMMUNAUTE";
    Carte20.descriptif = "Vous heritez de 100e";
    Carte20.id = 20;
    Carte20.type = "CARTE COMMUNAUTE";

    piocheChance[0] = Carte1;
    piocheChance[1] = Carte2;
    piocheChance[2] = Carte3;
    piocheChance[3] = Carte4;
    piocheChance[4] = Carte5;
    piocheChance[5] = Carte6;
    piocheChance[6] = Carte7;
    piocheChance[7] = Carte8;
    piocheChance[8] = Carte9;
    piocheChance[9] = Carte10;
    piocheCommunaute[0] = Carte11;
    piocheCommunaute[1] = Carte12;
    piocheCommunaute[2] = Carte13;
    piocheCommunaute[3] = Carte14;
    piocheCommunaute[4] = Carte15;
    piocheCommunaute[5] = Carte16;
    piocheCommunaute[6] = Carte17;
    piocheCommunaute[7] = Carte18;
    piocheCommunaute[8] = Carte19;
    piocheCommunaute[9] = Carte20;

    printf("Creation de toute les cartes reussi\n");


    printf("\n");
    for (int i = 0; i < NB_CARTE; ++i) {
        int j = rand() % NB_CARTE;
        Cartes tmp = piocheChance[i];
        piocheChance[i] = piocheChance[j];
        piocheChance[j] = tmp;
    }
    for (int i = 0; i < NB_CARTE; ++i) {
        int j = rand() % NB_CARTE;
        Cartes tmp = piocheCommunaute[i];
        piocheCommunaute[i] = piocheCommunaute[j];
        piocheCommunaute[j] = tmp;
    }

}

void InitialisationProprietes(Propriete propriete[16], Case plateau[32]) {
    int cpt = 1;
    int bug = 1;
    int cptCase = 1;
    for (int i = 0; i < 16; ++i) {
        propriete[i].numero = cpt;
        propriete[i].etat = 1;
        propriete[i].type = 0;
        propriete[i].groupe = bug;
        propriete[i].pCase = &plateau[cptCase];
        propriete[i].titre = plateau[cptCase].nom;
        switch (propriete[i].groupe) {
            case 1:
                propriete[i].prix = 50;
                break;
            case 2:
                propriete[i].prix = 100;
                break;
            case 3:
                propriete[i].prix = 250;
                break;
            case 4:
                propriete[i].prix = 500;
                break;
            case 5:
                propriete[i].prix = 750;
                break;
            case 6:
                propriete[i].prix = 1000;
                break;
            case 7:
                propriete[i].prix = 1500;
                break;
            case 8:
                propriete[i].prix = 2000;
        }
        cptCase += 2;
        cpt += 1;
        if (cpt == 3) {
            cpt = 1;
        }
        if (i % 2 == 1 ){
            bug += 1;
        }
    }

}

void InitialisationPlateau(Case plateau[31]) {
    int cpt = 1;
    for (int i = 0; i < 32; ++i) {
        plateau[i].numero = cpt;
        cpt += 1;
    }
    plateau[31].numero = 32;
    plateau[0].nom = "Depart";
    plateau[1].nom = "P 1 GP 1";
    plateau[2].nom = "Taxe hab";
    plateau[3].nom = "P 2 GP 1";
    plateau[4].nom = "GO Case 13";
    plateau[5].nom = "P 1 GP 2";
    plateau[6].nom = "Carte comu";
    plateau[7].nom = "P 2 GP 2";
    plateau[8].nom = "Prison";
    plateau[9].nom = "P 1 GP 3";
    plateau[10].nom = "ISF";
    plateau[11].nom = "P 2 GP 3";
    plateau[12].nom = "Go case 21";
    plateau[13].nom = "P 1 GP 4";
    plateau[14].nom = "Carte chance";
    plateau[15].nom = "P 2 GP 4'";
    plateau[16].nom = "Satio gratuit";
    plateau[17].nom = "P 1 GP 5";
    plateau[18].nom = "Taxe luxe";
    plateau[19].nom = "P 2 GP 5";
    plateau[20].nom = "Go case 29";
    plateau[21].nom = "P 1 GP 6";
    plateau[22].nom = "Carte comu";
    plateau[23].nom = "P 2 GP 6";
    plateau[24].nom = "Prison";
    plateau[25].nom = "P 1 GP 7";
    plateau[26].nom = "50e";
    plateau[27].nom = "P2 GP 7";
    plateau[28].nom = "Go case 5";
    plateau[29].nom = "P1 GP 8";
    plateau[30].nom = "Carte chance";
    plateau[31].nom = "P2 GP 8";
}

void InitialisationPions(int nb, Pion* pions) {
    for (int i = 0; i < nb; ++i) {
        pions[i].forme = i + 1;
        pions[i].position = 1;
    }
}

void InitialisationJoueur(Joueur joueur[], int nb, Pion *pion) {
    int flush = 0;
    assert(pion != NULL);
    assert(joueur != NULL);
    for (int i = 0; i < nb; ++i) {
        printf("Joueur %d saisir votre pseudo  :\n ", i + 1);
        scanf("%d", &flush);
        fgets(joueur[i].nom, 10, stdin);
        joueur[i].argent = 1500;
        joueur[i].pPion = &pion[i];
        joueur[i].pPropriete = NULL;
        flush = 0;
    }
}
