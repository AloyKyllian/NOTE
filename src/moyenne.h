#ifndef moyenne_H_INCLUS    
#define moyenne_H_INCLUS   
#include "note.h"

typedef struct
{
    char elum[10];
    float moyenne_elum;
} moyenne_matiere;

typedef struct 
{
    float UE1;
    float UE2;
    float UE3;
    float General;
}moyenne;

void Calcul_Moyenne_matiere(char chemin_dossier_coef[100], etudiant_typ etudiant[40], int numero_etu,moyenne_matiere tab_moyenne[]);
moyenne calcul_moyenne(moyenne_matiere tab_moyenne[]);

#endif