#ifndef moyenne_H_INCLUS    
#define moyenne_H_INCLUS   

#define NB_MATIERE 20

typedef struct
{
    int ID;
    float note;
} eleve_typ;

typedef char controle_typ[9];

typedef char nom_typ[20];

typedef struct
{
    int ID_etu;
    float note_etu[NB_MATIERE];
    controle_typ controle_etu[NB_MATIERE];
    nom_typ nom_etu[NB_MATIERE];
} etudiant_typ;

typedef struct
{
    eleve_typ *eleve;
    controle_typ controle;
    nom_typ nom;
} matiere_typ;

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
typedef struct
{
    int ID;
    float note;
} eleve_typ;

typedef char controle_typ[9];

typedef char nom_typ[20];

typedef struct
{
    int ID_etu;
    float note_etu[NB_MATIERE];
    controle_typ controle_etu[NB_MATIERE];
    nom_typ nom_etu[NB_MATIERE];
} etudiant_typ;

typedef struct
{
    eleve_typ *eleve;
    controle_typ controle;
    nom_typ nom;
} matiere_typ;

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

moyenne_matiere Calcul_Moyenne_matiere(char chemin_dossier_coef[100], etudiant_typ etudiant[40], int numero_etu);
moyenne calcul_moyenne(moyenne_matiere tab_moyenne[]);

#endif