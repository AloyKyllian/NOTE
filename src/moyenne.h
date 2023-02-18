#ifndef moyenne_H_INCLUS    
#define moyenne_H_INCLUS   

#include "note.h"

#define NB_MATIERE 12



typedef char controle_typ[9];

typedef char nom_typ[20];

typedef char nom_matiere[20];


typedef struct
{
    float coef_cc[NB_CONTROLE_TOT];
    controle_typ controle[NB_CONTROLE_TOT];
    nom_typ elum[NB_CONTROLE_TOT];
    nom_typ nom[NB_CONTROLE_TOT];
}coef_note_typ;



typedef struct
{
    float coef[NB_MATIERE];
    nom_typ elum[NB_MATIERE];
    nom_typ nom[NB_MATIERE];
}coef_matiere_typ;


typedef struct
{
    float coef[NB_MATIERE];
    nom_typ elum[NB_MATIERE];
    nom_typ nom[NB_MATIERE];
}matiere;

/*

typedef struct 
{
    char CC[5];
    float coef;
} controle;


typedef struct
{
    char elum[10];
    char nom[10];
    controle coef_CC[4];
    float coef_UE;
} matiere;



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


*/

//moyenne des UE et GENE
typedef struct 
{
    int ID_etu;
    float UE1;
    float UE2;
    float UE3;
    float gene;
} UE_typ;


//moyenne de chaque matiere
typedef struct 
{
    int ID_etu;
    float note_etu[NB_MATIERE];
    nom_typ elum[NB_MATIERE];
    nom_matiere nom_matiere[NB_MATIERE];
} moyenne_typ;

//toutes les notes
typedef struct 
{
    int ID_etu;
    float note_etu[NB_CONTROLE_TOT];
    controle_typ controle_etu[NB_CONTROLE_TOT];
    nom_typ elum[NB_CONTROLE_TOT];
    nom_matiere nom_matiere[NB_CONTROLE_TOT];
} note_typ;


void lecture_coef(char chemin_dossier_coef[],coef_note_typ *tab_note_coef,coef_matiere_typ *tab_mat_coef);
void lecture_note2(note_typ *note,char nom_fichier[]);
void lecture_note(etudiant_typ *etu,char nom_fichier[]);
void Calcul_note_coef(etudiant_typ etudiant[]);
/*
void Calcul_Moyenne_matiere(char chemin_dossier_coef[100], etudiant_typ etudiant[40], int numero_etu,moyenne_matiere tab_moyenne[]);
moyenne calcul_moyenne(moyenne_matiere tab_moyenne[]);
*/
#endif