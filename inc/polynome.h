/*
 * Fichier d'en tête polynome.h pour le projet POLYNOME
 * Auteur : GIRAUD Pierre  / lundi 5 décembre 2016, 20:41:00 (UTC+0100)
 * Ce document est sous Licence GPL v3
 * voir : http://www.gnu.org/licenses/gpl-3.0.html
 */

#include <stdlib.h>
#include <stdio.h>

#ifndef __POLYNOME__H__
#define __POLYNOME__H__


typedef struct Monome {
	float coef;
	int degre;
}Monome; 

typedef struct element {
	MONO * monome;
	struct element * suivant;
	struct element * precedent;
}Polyome;
typedef Monome * MONO;
typedef Polyome * POLY;


MONO creerMonome(float coef, int puissance);
POLY creerPolynome(void);
POLY ajouterMonome(POLY p, MONO m);
POLY supprimerMonome(POLY p, int deDegre);

POLY additionner(POLY p1, POLY p2);
POLY multiplier(POLY , POLY);
MONO mderiverI(MONO , int); // iterative
MONO mderiverR(MONO , int);// recursif
POLY pderiver(POLY , int);
void ecrireMonomeI(MONO); // iterative
void ecrireMonomeR(MONO);// recursif
void ecrirePolynome(POLY p);


typedef enum Bool {
  FALSE = 0;
  TRUE = 1
} BOOL;

void efface_ecran(void);














#endif /* __POLYNOME__H__ */

