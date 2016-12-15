/*
 * Fichier code source polynome.c pour le projet POLYNOME
 * Auteur : GIRAUD Pierre  / lundi 5 décembre 2016, 20:37:52 (UTC+0100)
 * Ce document est sous Licence GPL v3
 * voir : http://www.gnu.org/licenses/gpl-3.0.html
 */

#include <stdlib.h>
#include <stdio.h>

#include "polynome.h"



MONO creerMonome(float coefficient, int puissance){
    MONO m;
    m = (Monome*)malloc(sizeof(Monome));
    m->coef = coefficient;
    m->degre = puissance;
    return m;
}

POLY creerPolynome(void){
    POLY p;
    p = (Polyome*)malloc(sizeof(Polyome));
    p->suivant = NULL;
    p->precedent = NULL;
    p->monome = NULL;
    return p;
}

POLY ajouterMonome(POLY p, MONO m){
    POLY temp = p;
    POLY nouvo = creerPolynome();
    while (temp != NULL && m->degre >= (temp->monome)->degre){
        temp = temp->suivant;
    }
    //insertion a gauche de temp
    (temp->precedent)->suivant = nouvo
    nouvo->suivant = temp;
    nouvo->precedent = temp->precedent
    temp->precedent = nouvo;
    nouvo->monome = m;
    return p;
}

POLY supprimerMonome(POLY p, int deDegre){
    POLY temp = p;
    while (temp != NULL && (temp->monome)->degre != deDegre){
        temp = temp->suivant;
    }
    (temp->precedent)->suivant = temp->suivant;
    (temp->suivant)->precedent = temp->precedent;
    free(temp->monome);
    free(temp);
    return p;
}


POLY additionner(POLY p1, POLY p2){
    int degreADD;
    int i;
    POLY temp1 = p1;
    POLY temp2 = p2;
    POLY p = creerPolynome();
/*
    while (temp1 != NULL){
        degreADD = (temp1->monome)->degre
        while (){

        }
        temp1 = temp1->suivant;
    }
*/
    //une fois temp1 et temp2 correct
    MONO mADD;
    mADD = creerMonome((temp1->monome)->coef + (temp2->monome)->coef , degreADD);
    p = ajouterMonome(p , mADD);


    return p
}




void ecrirePolynome(POLY p){
    if (p == NULL)
        printf(" fin \n");
    else {
        printf("%f*X^(%d) + ", (p->monome)->coef, (p->monome)->degre);
        ecrirePolynome(p->suivant);
    }
}