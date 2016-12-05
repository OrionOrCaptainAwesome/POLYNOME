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

typedef struct monome {
	float valeur;
	int degre;
}Monome; 
#define ARRAY_SIZE_MAX 10
typedef Monome *Polynome[ARRAY_SIZE_MAX];

Monome creerMonome(float , int);
Polynome creerPolynome(void);
Polynome ajouterMonome(Polynome , Monome);
Polynome supprimerMonome(Polynome , int);
Polynome additionner(Polynome , Polynome);
Polynome multiplier(Polynome , Polynome);
Monome mderiverI(Monome , int); // iterative
Monome mderiverR(Monome , int);// recursif
Polynome pderiver(Polynome , int);
void ecrireMonomeI(Monome); // iterative
void ecrireMonomeR(Monome);// recursif
void ecrirePolynome(Polynome);


#endif /* __POLYNOME__H__ */

